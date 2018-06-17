#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QTextEdit>
#include <QKeyEvent>

#include "Trie/trie.hpp"

#include <QDebug>

class TextEdit : public QTextEdit
{
    Q_OBJECT

    int last_pos;

    static QString p_firstWordFind_Helper(QTextDocument *doc, int pos);

private slots:
    void on_textCursorChanged(const QTextCursor &cursor);

public:
    explicit TextEdit(QWidget *parent = nullptr);

};

#endif // TEXTEDIT_HPP
