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

    Trie() : root(new Node_p()) {}
    Trie(const Trie &){}
    Trie(Trie &){}

    static Trie p_trie;

public:
    static Trie &trie();
    virtual ~Trie();

    bool isEmpty() const;

    QStringList words(const QString &preffix, int n = 5) const;
    bool contains(const QString &word) const;

    void addWord(const QString &word);
    void remove(const QString &word);
    void clear();

};

#endif // TRIE_HPP
