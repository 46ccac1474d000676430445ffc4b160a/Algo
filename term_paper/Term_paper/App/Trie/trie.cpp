#include "trie.hpp"

int Node_p::p_indexHelper(const QChar &c)
{
    QChar ch = c.toLower();
    int index = ( ch.row() << 8 ) | ch.cell();

    if ('a' <= index && index <= 'z') return index - 'a';
    else if (1072 <= index && index <= 1103) return (index - 1072) + 26; //ru а-я
    else if (index == 1105) return 58;  //ru ё
    else if('0' <= index && index <= '9') return (index - '0') + 59;
    else if (index == '-') return 69;
    else return -1;
}

QChar Node_p::p_letterHelper(int index)
{
    if (0 <= index && index <= 25) return QChar(index + 'a');
    else if (26 <= index && index <= 57) return QChar(index - 26 + 1072);   //ru а-я
    else if (index == 58) return QChar(1105);   //ru ё
    else if (59 <= index && index <= 68) return QChar(index - 59 + '0');
    else if (index == 69) return QChar('-');
    else return QChar();
}



Node_p::Node_p(Node_p *parent) :
    m_parent(parent),
    isEnd(false)
{
}

Node_p *Node_p::parent() const
{ return m_parent; }

Node_p *Node_p::at(const QChar &c) const
{
    int index = p_indexHelper(c);
    if (index < 0) throw std::range_error("in \"Node_p *Node_p::operator [](const QChar &c)\" range error");

    return d[index];
}

bool Node_p::isEmpty() const
{
    for (int i = 0; i < CAP; i++)
    {
        if (d[i] != 0x0) return false;
    }

    return !isEnd;
}

void Node_p::set(const QChar &c, Node_p *node)
{
    int index = p_indexHelper(c);
    if (index < 0) throw std::range_error("in \"void Node_p::set(const QChar &c, Node_p *node)\" range error");

    if (node == 0x0) delete d[index];
    d[index] = node;
}

void Node_p::setParent(Node_p *parent)
{ m_parent = parent; }

Node_p::~Node_p()
{
    for (int i = 0; i < CAP; i++)
        delete d[i];
}




void Trie::p_wordsHelper(Node_p *node, QString word, QStringList &list, int n)
{
    for (int i = 0; i < CAP; i++)
    {
        Node_p *t = node->d[i];
        if (t)
        {
            QChar c = Node_p::p_letterHelper(i);
            if (t->isEnd)
            {
                list << word+c;
                n--;
            }
            if (n) p_wordsHelper(t, word+c, list, n);
            else return;
        }
    }
}



Trie Trie::s_trie = Trie();

Trie &Trie::obj()
{ return s_trie; }

Trie::~Trie()
{ delete root; }

bool Trie::isEmpty() const
{ return root->isEmpty(); }

QStringList Trie::words(const QString &preffix, int n) const
{
    Node_p *node = root;

    foreach (const QChar &c, preffix)
    {
        if ( (node = node->at(c)) == 0x0) return QStringList();
    }

    QStringList s_list;

    QString str = preffix;

    p_wordsHelper(node, str, s_list, n);

    return s_list;
}

bool Trie::contains(const QString &word) const
{
    Node_p *node = root;

    foreach (const QChar &c, word)
    {
        if ( (node = node->at(c)) == 0x0) return false;
    }
    return node->isEnd;
}

void Trie::addWord(const QString &word)
{
    Node_p *node = root;

    foreach (QChar c, word)
    {
        if (Node_p::p_indexHelper(c) < 0) c = '-';
        Node_p *t = node->at(c);
        if (t == 0x0)
        {
            t = new Node_p(node);
            node->set(c, t);
        }
        node = t;
    }
    node->isEnd = true;
}

Trie &Trie::operator <<(const QString &word)
{
    addWord(word);
    return *this;
}

void Trie::remove(const QString &word)
{
    Node_p *node = root;

    QString stack;

    foreach (const QChar &c, word)
    {
        if ( (node = node->at(c)) == 0x0) return;
        stack.prepend(c);
    }

    node->isEnd = false;

    foreach (const QChar &c, stack)
    {
        if ( (node = node->parent()) == 0x0) return;
        if (!node->isEmpty()) return;
        node->set(c, 0x0);
    }
}

void Trie::clear()
{
    delete root;
    root = new Node_p();
}
