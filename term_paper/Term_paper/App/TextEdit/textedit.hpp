#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QTextEdit>
#include <QKeyEvent>

#include "Trie/trie.hpp"

#include <QDebug>

class TextEdit : public QTextEdit
{
    Q_OBJECT

    Q_PROPERTY(QString buffer READ buffer WRITE setBuffer NOTIFY bufferChanged)

    QString m_buffer;

protected:
    void keyReleaseEvent(QKeyEvent *e);

public:
    explicit TextEdit(QWidget *parent = nullptr);

    QString buffer() const
    {
        return m_buffer;
    }

signals:

    void bufferChanged(QString buffer);

public slots:
void setBuffer(QString buffer)
{
    if (m_buffer == buffer)
        return;

    m_buffer = buffer;
    emit bufferChanged(m_buffer);
}
};

#endif // TEXTEDIT_HPP
