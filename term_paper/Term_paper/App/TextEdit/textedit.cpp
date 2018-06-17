#include "textedit.hpp"

QString TextEdit::p_firstWordFind_Helper(QTextDocument *doc, int pos)
{
    QString word;
    while (pos >= 0)
    {
        QChar ch = doc->characterAt(pos);

        if (ch.isLetter() || ch == '-') word.prepend(ch);
        else break;

        pos--;
    }
    return word;
}

void TextEdit::on_textCursorChanged(const QTextCursor &cursor)
{
    int pos = cursor.position()-1;

    if (pos - last_pos == 1)
    {
        QString buf = p_firstWordFind_Helper(document(), pos);

        if (buf.size() >= 3) qDebug() << Trie::obj().words(buf, 5);
    }

    last_pos = cursor.position()-1;
}

TextEdit::TextEdit(QWidget *parent) :
    QTextEdit(parent),
    last_pos(textCursor().position())
{
    connect(document(), &QTextDocument::cursorPositionChanged, this, &TextEdit::on_textCursorChanged);
}

