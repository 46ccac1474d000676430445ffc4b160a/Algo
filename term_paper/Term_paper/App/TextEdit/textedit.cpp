#include "textedit.hpp"
#include "textedit_p.hpp"

static QString p_firstWordFind_Helper(QTextDocument *doc, int pos)
{
    pos--;
    QString word;
    while (pos >= 0)
    {
        QChar ch = doc->characterAt(pos).toLower();
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

void TextEdit::on_callSuggestions(int n)
{
    QString preffix = p_firstWordFind_Helper(document(), textCursor().anchor());

    if (preffix.size() >= n || suggestions->isVisible())
    {
        QStringList words = Trie::obj().words(preffix);

        if (words.isEmpty()) suggestions->hideSuggestions();
        else suggestions->showSuggestions(words);
    }
}

void TextEdit::on_textCursorChanged()
{
    int pos = textCursor().anchor();

    if (pos - last_pos == 1) on_callSuggestions();
    else suggestions->hideSuggestions();

    last_pos = pos;
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

void TextEdit::setFileName(const QString &fileName)
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
    suggestions(new SuggestionsList(this)),
    m_saved(false),
    callSuggestionsShortcut(new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Space), this)),
    hideSuggestionsShortcut(new QShortcut(QKeySequence(Qt::Key_Escape), this))
{
    connect(this, &TextEdit::textChanged, [this](){ m_saved = false; } );
    connect(this, &TextEdit::cursorPositionChanged, this, &TextEdit::on_textCursorChanged);

    connect(callSuggestionsShortcut, &QShortcut::activated, [=]() {
        on_callSuggestions(0);
    });
    connect(hideSuggestionsShortcut, &QShortcut::activated,
            suggestions, &SuggestionsList::hideSuggestions);
}

