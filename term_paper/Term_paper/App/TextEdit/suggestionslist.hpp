#ifndef SUGGESTIONSLIST_HPP
#define SUGGESTIONSLIST_HPP

#include <QTextEdit>
#include <QListWidget>
#include <QKeyEvent>
#include <QFocusEvent>

#include <QDebug>

class SuggestionsList : public QListWidget
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusOutEvent(QFocusEvent *e) override;

private slots:
    void on_itemActivated(QListWidgetItem *item);

public:
    SuggestionsList(QTextEdit *parent);

public slots:
    void showSuggestions(const QStringList &suggestions);
    void hideSuggestions();

signals:
    void focusLost();
};

#endif // SUGGESTIONSLIST_HPP
