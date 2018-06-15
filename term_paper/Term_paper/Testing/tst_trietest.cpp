#include <QString>
#include <QtTest>

#include "../App/Trie/trie.hpp"

class TrieTest : public QObject
{
    Q_OBJECT

public:
    TrieTest();

private Q_SLOTS:
    void test_index();
    void test_letter();
    void test_words();
    void test_contains();
    void test_remove();
};

TrieTest::TrieTest()
{
}

void TrieTest::test_index()
{
    int in[] = {0, 8, 25, 26, 57};

    int t[5];

    t[0] = Node_p::index(QChar('a'));
    t[1] = Node_p::index(QChar('i'));
    t[2] = Node_p::index(QChar('z'));
    t[3] = Node_p::index(QString("а")[0]);
    t[4] = Node_p::index(QString("я")[0]);

    for (int i = 0; i < 4; i++)
    {
        QCOMPARE(t[i], in[i]);
    }
}

void TrieTest::test_letter()
{
    int in[] = {0, 8, 25, 26, 57};

    QCOMPARE(Node_p::letter(in[0]), QChar('a'));
    QCOMPARE(Node_p::letter(in[1]), QChar('i'));
    QCOMPARE(Node_p::letter(in[2]), QChar('z'));
    QCOMPARE(Node_p::letter(in[3]), QString("а")[0]);
    QCOMPARE(Node_p::letter(in[4]), QString("я")[0]);
}

void TrieTest::test_words()
{
    QStringList words;
    words << "prefirststr";
    words << "presecond-str";
    words << "preтретьястрока";
    words << "preчетвертая-строка";


    Trie trie;

    foreach (QString word, words)
    {
        trie.addWord(word);
    }

    QCOMPARE(trie.words("pre"), words);
}

void TrieTest::test_contains()
{
    QStringList words1;
    words1 << "prefirststr";
    words1 << "presecond-str";
    words1 << "preтретьястрока";
    words1 << "preчетвертая-строка";

    Trie trie;

    foreach (QString word, words1)
    {
        trie.addWord(word);
    }

    QStringList words2;
    words2 << "firststr";
    words2 << "second-str";
    words2 << "третьястрока";
    words2 << "четвертая-строка";

    foreach (QString word, words1)
    {
        QCOMPARE( trie.contains(word), true);
    }

    foreach (QString word, words2)
    {
        QCOMPARE( trie.contains(word), false);
    }

}

void TrieTest::test_remove()
{
    QStringList words;
    words << "prefirststr";
    words << "presecond-str";
    words << "preтретьястрока";
    words << "preчетвертая-строка";


    Trie trie;

    foreach (QString word, words)
    {
        trie.addWord(word);
    }

    foreach (QString word, words)
    {
        QCOMPARE( trie.contains(word), true);
        trie.remove(word);
        QCOMPARE( trie.contains(word), false);
    }
}


QTEST_APPLESS_MAIN(TrieTest)

#include "tst_trietest.moc"
