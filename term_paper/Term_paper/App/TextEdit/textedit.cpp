#include "textedit.hpp"

void TextEdit::keyReleaseEvent(QKeyEvent *e)
{
    QChar ch(e->key());

    if (ch.isLetter() || ch == '-')
    {
        m_buffer.append(ch.toLower());

        if (m_buffer.size() > 3)
        {
            qDebug() << Trie::trie().words(m_buffer);
        }
    }
    else if (ch.isSpace())
    {
        m_buffer.clear();
    }
    else QTextEdit::keyReleaseEvent(e);
}

TextEdit::TextEdit(QWidget *parent) :
    QTextEdit(parent)
{
}
