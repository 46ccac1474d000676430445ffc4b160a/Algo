#ifndef TRIE_HPP
#define TRIE_HPP

#include <QChar>
#include <QVector>
#include <QLinkedList>

#include <stdexcept>

#include <QDebug>

static const int CAP = 70;

class Node_p
{
    friend class Trie;
#ifdef QT_QTTEST_MODULE_H
    friend class TrieTest;
#endif

//STATIC
    static int p_indexHelper(const QChar &c);
    static QChar p_letterHelper(int p_indexHelper);

//FIELDS
    Node_p *m_parent;

    Node_p *d[CAP] = {0x0};

    bool isEnd;

//METHODS
    Node_p(Node_p *parent = 0x0);

    Node_p *parent() const;
    Node_p *at(const QChar &c) const;
    bool isEmpty() const;

    void set(const QChar &c, Node_p *val);
    void setParent(Node_p *parent);

public:
    virtual ~Node_p();
};




class Trie
{
#ifdef QT_QTTEST_MODULE_H
    friend class TrieTest;
#endif

//STATIC
    static void p_wordsHelper(Node_p *node, QString word, QStringList &list, int n);

    static Trie s_trie;

public:
    static Trie &obj();

private:

//FIELDS
    Node_p *root;

//METHODS
    Trie() : root(new Node_p()) {}
    Trie(const Trie &){}
    Trie(Trie &){}

public:
    virtual ~Trie();

    bool isEmpty() const;

    QStringList words(const QString &preffix, int n = -1) const;
    bool contains(const QString &word) const;

    void addWord(const QString &word);
    Trie &operator <<(const QString &word);
    void remove(const QString &word);
    void clear();

};

#endif // TRIE_HPP
