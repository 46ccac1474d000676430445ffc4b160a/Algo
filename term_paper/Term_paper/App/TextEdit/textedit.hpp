#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QTextEdit>
#include <QListWidget>
#include <QShortcut>
#include <QMutex>

#include "Trie/trie.hpp"

#include <QDebug>

class TextEdit : public QTextEdit
{
    Q_OBJECT

    int last_pos;
    QListWidget *suggestions;

    QMutex suggestionsClear_mutex;

    QShortcut *callSuggestionsShortcut;
    QShortcut *hideSuggestionsShortcut;
    QShortcut *arrowUpShortcut;
    QShortcut *arrowDownShortcut;
    QShortcut *chooseSuggestionShortcut;

private slots:
    void callSuggestions(const QString &preffix);
    void hideSuggestions();

    void on_textCursorChanged();
    void on_suggestionChoosen(QListWidgetItem *item);

public:
    explicit TextEdit(QWidget *parent = nullptr);

};

#endif // TEXTEDIT_HPP
