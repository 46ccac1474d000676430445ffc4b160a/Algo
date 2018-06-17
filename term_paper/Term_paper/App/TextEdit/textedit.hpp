#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QTextEdit>
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>
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

    bool m_saved;
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)

    QShortcut *callSuggestionsShortcut;
    QShortcut *hideSuggestionsShortcut;
    QShortcut *arrowUpShortcut;
    QShortcut *arrowDownShortcut;
    QShortcut *chooseSuggestionShortcut;

    QString m_fileName;

private slots:
    void callSuggestions(const QString &preffix);
    void hideSuggestions();

    void on_textCursorChanged();
    void on_suggestionChoosen(QListWidgetItem *item);

public slots:
    bool open(const QString &file);
    bool save();
    void setFileName(QString fileName);

public:
    explicit TextEdit(QWidget *parent = nullptr);

    bool saved() const;
    QString fileName() const;

signals:
    void fileNameChanged(QString fileName);
};

#endif // TEXTEDIT_HPP
