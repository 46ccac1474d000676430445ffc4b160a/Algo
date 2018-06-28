#include "suggestionslist.hpp"
#include "textedit_p.hpp"

void SuggestionsList::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    QString text = e->text();

    QTextEdit *textEdit = static_cast<QTextEdit *>(parentWidget());

    if (key == Qt::Key_Space)
    {
        textEdit->textCursor().insertText(QString(QChar::Space));
        e->ignore();
        hideSuggestions();
        return;
    }
    else if (key == Qt::Key_Backspace)
    {
        textEdit->textCursor().deletePreviousChar();
        e->ignore();
        return;
    }
    else if (key == Qt::Key_Delete)
    {
        textEdit->textCursor().deleteChar();
        e->ignore();
        return;
    }
    else if (key == Qt::Key_Left)
    {
        QTextCursor cursor = textEdit->textCursor();
        cursor.movePosition(QTextCursor::Left);
        textEdit->setTextCursor(cursor);
        e->ignore();
        return;
    }
    else if (key == Qt::Key_Right)
    {
        QTextCursor cursor = textEdit->textCursor();
        cursor.movePosition(QTextCursor::Right);
        textEdit->setTextCursor(cursor);
        e->ignore();
        return;
    }
    else if (!text.isEmpty())
    {
        foreach (QChar ch, text)
        {
            if (p_isLetterOrNumber(ch.toLower()))
            {
                textEdit->textCursor().insertText(QString(ch));
                e->ignore();
                return;
            }
        }
    }

    QListWidget::keyPressEvent(e);
}

void SuggestionsList::focusOutEvent(QFocusEvent *e)
{
    if (e->lostFocus()) emit focusLost();
    QListWidget::focusOutEvent(e);
}

void SuggestionsList::on_itemActivated(QListWidgetItem *item)
{
    QString text = item->text();

    QTextEdit *textEdit = static_cast<QTextEdit *>(parentWidget());

    hideSuggestions();

    int p = textEdit->textCursor().anchor() - 1;
    while (p >= 0)
    {
        QChar ch = textEdit->document()->characterAt(p).toLower();
        if (p_isLetterOrNumber(ch))
        {
            textEdit->textCursor().deletePreviousChar();
            p--;
        }
        else break;
    }

    textEdit->textCursor().insertText(text);
}

SuggestionsList::SuggestionsList(QTextEdit *parent) :
    QListWidget(parent)
{
    setSortingEnabled(true);
    setTabKeyNavigation(true);
    setFocusPolicy(Qt::StrongFocus);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    hide();

    connect(this, &SuggestionsList::itemActivated, this, &SuggestionsList::on_itemActivated);
    connect(this, &SuggestionsList::focusLost, this, &SuggestionsList::hideSuggestions);
}

void SuggestionsList::showSuggestions(const QStringList &suggestions)
{
    clear();
    addItems(suggestions);

    QTextEdit *textEdit = static_cast<QTextEdit *>(parentWidget());

    QPoint s_point = textEdit->mapToGlobal(textEdit->geometry().topLeft());
    QPoint point = s_point + textEdit->cursorRect().bottomLeft();

    setGeometry(QRect(point, sizeHint()));

    show();
    setCurrentRow(0);
    textEdit->clearFocus();
    setFocus();
    activateWindow();
    raise();
}

void SuggestionsList::hideSuggestions()
{
    clearFocus();
    static_cast<QTextEdit *>(parentWidget())->setFocus();
    hide();
    clear();
}
