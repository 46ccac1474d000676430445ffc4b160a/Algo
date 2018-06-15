#include "trie.hpp"


Node_p::Node_p() :
    d(60, nullptr),
    isEnd(false)
{
}

Node_p *&Node_p::node(const QChar &c)
{
    int val = index(c);
    if (val < 0) throw std::range_error("in \"Node_p *Node_p::operator [](const QChar &c)\" range error");

    return d[val];
}

bool Node_p::isEmpty()
{
    foreach (Node_p *val, d)
    {
        if (val != nullptr) return false;
    }

    return true;
}

int Node_p::index(const QChar &c)
{
    int index = ( c.row() << 8 ) | c.cell();

    if (97 <= index && index <= 122) return index - 97;
    else if (1072 <= index && index <= 1103) return (index - 1072) + 26;
    else if (index == 45) return 58;
    else if (index == 1105) return 59;
    else return -1;
}

QChar Node_p::letter(int index)
{
    if (0 <= index && index <= 25) return QChar(index + 97);
    else if (26 <= index && index <= 57)
    {
        QChar ch(index - 26 + 1072);
        return ch;
    }
    else if (index == 58) return QChar('-');
    else if (index == 59) return QChar(1105);
    else return QChar();
}

Node_p::~Node_p()
{
    foreach (Node_p *val, d)
    {
        delete val;
    }
}




void Trie::p_words(Node_p *node, QString word, QStringList &list, int n)
{
    for (int i = 0; i < node->d.size(); i++)
    {
        Node_p *t = node->d[i];
        if (t != nullptr)
        {
            QChar c = Node_p::letter(i);
            if (t->isEnd)
            {
                list << word+c;
                n--;
            }
            if (n) p_words(t, word+c, list, n);
            else return;
        }
    }
}

Trie::Trie() :
    root(new Node_p())
{
}

Trie::~Trie()
{ delete root; }

bool Trie::isEmpty()
{ return root->isEmpty(); }

QStringList Trie::words(const QString &preffix, int n) const
{
    Node_p *node = root;

    foreach (const QChar &c, preffix)
    {
        Node_p *t = node->node(c);
        if (t == nullptr) break;
        node = t;
    }

    QStringList s_list;

    QString str = preffix;

    p_words(node, str, s_list, n);

    return s_list;
}

bool Trie::contains(const QString &word)
{
    Node_p *node = root;

    foreach (const QChar &c, word)
    {
        Node_p *t = node->node(c);
        if (t == nullptr) return false;
        node = t;
    }
    return node->isEnd;
}

void Trie::addWord(const QString &word)
{
    Node_p *node = root;

    foreach (const QChar &c, word)
    {
        Node_p *t = node->node(c);
        if (t == nullptr)
        {
            t = node->node(c) = new Node_p();
        }
        node = t;
    }
    node->isEnd = true;
}

void Trie::remove(const QString &word)
{
    Node_p *node = root;

    foreach (const QChar &c, word)
    {
        Node_p *t = node->node(c);
        if (t == nullptr) return;
        node = t;
    }
    node->isEnd = false;
}
