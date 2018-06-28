#include "trie.hpp"

QChar Node_p::checkChar(const QChar &c)
{
    QChar ch = c.toLower();
    int index = ( ch.row() << 8 ) | ch.cell();

    if (
            ('a' <= index && index <= 'z') ||
            (1072 <= index && index <= 1103) ||
            (index == 1105) ||
            ('0' <= index && index <= '9') ||
            (index == '-')
       ) return ch;
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
    QChar index = checkChar(c);
    if (index.isNull()) throw std::invalid_argument("in \"Node_p *Node_p::at(const QChar &c) const\" invalid char");

    if (d.contains(index)) return d.value(index);
    else return nullptr;
}

bool Node_p::isEmpty() const
{
    if (!d.isEmpty()) return false;
    return !isEnd;
}

void Node_p::set(const QChar &c, Node_p *node)
{
    QChar index = checkChar(c);
    if (index.isNull()) throw std::invalid_argument("in \"void Node_p::set(const QChar &c, Node_p *node)\" invalid char");

    if (d.contains(index))
    {
        Node_p *l_node = d.value(index);
        d.remove(index);
        delete l_node;
    }

    if (node == nullptr) return;

    d.insert(index, node);
}

void Node_p::setParent(Node_p *parent)
{ m_parent = parent; }

Node_p::~Node_p()
{
    QList<Node_p *> children = d.values();
    foreach (Node_p *node, children)
    {
        delete node;
    }
}




void Trie::p_wordsHelper(Node_p *node, QString word, QStringList &list, int n)
{
    QList<QChar> keys = node->d.keys();
    foreach (QChar index, keys)
    {
        Node_p *t = node->d.value(index);
        if (t->isEnd)
        {
            list << word+index;
            n--;
        }
        if (n) p_wordsHelper(t, word+index, list, n);
        else return;
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
        if ( (node = node->at(c)) == nullptr) return QStringList();
    }

    QStringList s_list;

    p_wordsHelper(node, preffix, s_list, n);

    return s_list;
}

bool Trie::contains(const QString &word) const
{
    Node_p *node = root;

    foreach (QChar c, word)
    {
        if (Node_p::checkChar(c).isNull()) c = '-';
        if ((node = node->at(c)) == nullptr) return false;
    }
    return node->isEnd;
}

void Trie::addWord(const QString &word)
{
    Node_p *node = root;

    foreach (QChar c, word)
    {
        if (Node_p::checkChar(c).isNull())
        {
            qDebug() << c;
            c = '-';
        }
        Node_p *t = node->at(c);
        if (t == nullptr)
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

Trie &Trie::operator <<(const QStringList &dict)
{
    foreach (const QString &word, dict)
    {
        addWord(word);
    }
    return *this;
}

void Trie::remove(const QString &word)
{
    Node_p *node = root;

    QString stack;

    foreach (const QChar &c, word)
    {
        if ( (node = node->at(c)) == nullptr) return;
        stack.prepend(c);
    }

    node->isEnd = false;

    foreach (const QChar &c, stack)
    {
        if ( (node = node->parent()) == nullptr) return;
        if (!node->isEmpty()) return;
        node->set(c, nullptr);
    }
}

void Trie::clear()
{
    delete root;
    root = new Node_p();
}
