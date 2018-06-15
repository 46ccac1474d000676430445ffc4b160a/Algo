#ifndef TRIE_HPP
#define TRIE_HPP

#include <QChar>
#include <QVector>
#include <QLinkedList>

#include <stdexcept>

#include <QDebug>

class Node_p
{
    friend class Trie;
#ifdef QT_QTTEST_MODULE_H
    friend class TrieTest;
#endif

    QVector<Node_p *> d;
    bool isEnd;

    Node_p();

    Node_p *&node(const QChar &c);
    bool isEmpty();

    static int index(const QChar &c);
    static QChar letter(int index);

public:
    virtual ~Node_p();
};




class Trie
{
#ifdef QT_QTTEST_MODULE_H
    friend class TrieTest;
#endif

    Node_p *root;

    static void p_words(Node_p *node, QString word, QStringList &list, int n);

public:
    Trie();
    virtual ~Trie();

    bool isEmpty();

    QStringList words(const QString &preffix, int n = 5) const;
    bool contains(const QString &word);

    void addWord(const QString &word);
    void remove(const QString &word);

};

#endif // TRIE_HPP
