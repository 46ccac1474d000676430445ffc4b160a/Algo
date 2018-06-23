#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QTextEdit>
#include <QListWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QApplication>
#include <QDesktopWidget>
#include <QWindow>
#include <QAction>
#include <QContextMenuEvent>
#include <QMenu>

#include "Trie/trie.hpp"
#include "suggestionslist.hpp"

#include <QDebug>

class TextEdit : public QTextEdit
{
    Q_OBJECT

    int last_pos;
    SuggestionsList *suggestions;

    bool m_saved;
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)

    QShortcut *callSuggestionsShortcut;
    QShortcut *hideSuggestionsShortcut;

    QString m_fileName;

protected:
    void contextMenuEvent(QContextMenuEvent *e) override;

private slots:
    void on_callSuggestions(int n = 3);
    void on_textCursorChanged();

public slots:
    bool open(const QString &file);
    bool save(const QString &filename);
    void setFileName(const QString &fileName);

public:
    explicit TextEdit(QWidget *parent = nullptr);

    bool saved() const;
    QString fileName() const;

signals:
    void fileNameChanged(QString fileName);
};

#endif // TEXTEDIT_HPP
