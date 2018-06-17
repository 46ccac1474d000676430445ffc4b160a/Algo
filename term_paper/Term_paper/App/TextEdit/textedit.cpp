#include "textedit.hpp"

static inline bool p_isLetterOrNumber(const QChar &ch)
{
    int d = ( ch.row() << 8 ) | ch.cell();

    return (
             ('a' <= d && d <= 'z') ||
             ('0' <= d && d <= '9') ||
             (1072 <= d && d <= 1103) ||
             (d == 1105) ||
             (d == '-')
           );
}

static inline QString p_firstWordFind_Helper(QTextDocument *doc, int pos)
{
    pos--;
    QString word;
    while (pos >= 0)
    {
        QChar ch = doc->characterAt(pos);
        if (p_isLetterOrNumber(ch)) word.prepend(ch);
        else break;

        pos--;
    }

    return word;
}

bool TextEdit::saved() const
{ return m_saved; }

QString TextEdit::fileName() const
{ return m_fileName; }

void TextEdit::callSuggestions(const QString &preffix)
{
    arrowUpShortcut->setEnabled(true);
    arrowDownShortcut->setEnabled(true);
    chooseSuggestionShortcut->setEnabled(true);

    suggestions->setGeometry(QRect(cursorRect().bottomLeft(), suggestions->sizeHint()));

    QStringList words = Trie::obj().words(preffix);

    if (suggestionsClear_mutex.tryLock())
    {
        suggestions->clear();
        suggestionsClear_mutex.unlock();
    }

    if (!words.isEmpty())
    {
        suggestions->addItems(words);
        suggestions->setCurrentRow(0);
        suggestions->show();
    }
    else suggestions->hide();
}

void TextEdit::hideSuggestions()
{
    arrowUpShortcut->setEnabled(false);
    arrowDownShortcut->setEnabled(false);
    chooseSuggestionShortcut->setEnabled(false);

    if (suggestionsClear_mutex.tryLock())
    {
        suggestions->clear();
        suggestionsClear_mutex.unlock();
    }
    suggestions->hide();
    this->setFocus();
}

void TextEdit::on_textCursorChanged()
{
    int pos = textCursor().anchor();

    if (qAbs(pos - last_pos) == 1)
    {
        QString buf = p_firstWordFind_Helper(document(), pos);

        if (buf.size() >= 3 || suggestions->isVisible())
            callSuggestions(buf);
    }
    else hideSuggestions();

    last_pos = pos;
}

void TextEdit::on_suggestionChoosen(QListWidgetItem *item)
{
    if (suggestionsClear_mutex.tryLock())
    {
        QString text = item->text();

        int p = textCursor().anchor() - 1;
        while (p >= 0)
        {
            QChar ch = document()->characterAt(p);
            if (p_isLetterOrNumber(ch))
            {
                textCursor().deletePreviousChar();
                p--;
            }
            else break;
        }

        textCursor().insertText(text);
        this->hideSuggestions();

        suggestionsClear_mutex.unlock();
    }
}

bool TextEdit::open(const QString &file)
{
    if (!file.isEmpty())
    {
        QFile f(file);
        if(f.open(QIODevice::ReadOnly))
        {
            setPlainText(QString(f.readAll()));
            f.close();
            setFileName(file);
            m_saved = true;
            return true;
        }
    }
    return false;
}

bool TextEdit::save()
{
    if (saved()) return true;
    if (fileName().isEmpty()) return false;

    QFile f(fileName());
    if (f.open(QIODevice::WriteOnly))
    {
        f.write(toPlainText().toUtf8());
        f.close();
        m_saved = true;
        return true;
    }

    return false;
}

void TextEdit::setFileName(QString fileName)
{
    if (m_fileName == fileName)
        return;

    m_saved = false;
    m_fileName = fileName;
    emit fileNameChanged(m_fileName);
}

TextEdit::TextEdit(QWidget *parent) :
    QTextEdit(parent),
    last_pos(textCursor().anchor()),
    suggestions(new QListWidget(this)),
    m_saved(false),
    callSuggestionsShortcut(new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Space), this)),
    hideSuggestionsShortcut(new QShortcut(QKeySequence(Qt::Key_Escape), this)),
    arrowUpShortcut(new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Up), this)),
    arrowDownShortcut(new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Down), this)),
    chooseSuggestionShortcut(new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Return), this))
{
    connect(this, &TextEdit::textChanged, [this](){ m_saved = false; } );
    connect(this, &TextEdit::cursorPositionChanged, this, &TextEdit::on_textCursorChanged);

    suggestions->hide();
    connect(suggestions, &QListWidget::itemActivated, this, &TextEdit::on_suggestionChoosen);
    connect(suggestions, &QListWidget::itemDoubleClicked, this, &TextEdit::on_suggestionChoosen);

    connect(callSuggestionsShortcut, &QShortcut::activated, [=](){
        callSuggestions(p_firstWordFind_Helper(document(), textCursor().anchor()));
    });
    connect(hideSuggestionsShortcut, &QShortcut::activated, this, &TextEdit::hideSuggestions);

    arrowUpShortcut->setEnabled(false);
    arrowDownShortcut->setEnabled(false);
    chooseSuggestionShortcut->setEnabled(false);

    connect(arrowUpShortcut, &QShortcut::activated, [=](){
        int row = suggestions->currentRow();
        row = row > 0 ? row-1 : suggestions->count()-1;
        suggestions->setCurrentRow(row);
    });
    connect(arrowDownShortcut, &QShortcut::activated, [=](){
        int row = suggestions->currentRow();
        row = row == suggestions->count()-1 ? 0 : row+1;
        suggestions->setCurrentRow(row);
    });
    connect(chooseSuggestionShortcut, &QShortcut::activated, [=](){
        on_suggestionChoosen(suggestions->currentItem());
    });
}

