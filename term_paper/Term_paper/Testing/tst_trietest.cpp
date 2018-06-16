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
    void test_contains_addWord();
    void test_remove();
    void test_words();
};

TrieTest::TrieTest()
{
}

void TrieTest::test_index()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        QCOMPARE(Node_p::index(QChar(i)), i-'a');
    }

    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        QCOMPARE(Node_p::index(ru[i]), i+26);
    }
}

void TrieTest::test_letter()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        QCOMPARE(Node_p::letter(i-'a'), QChar(i));
    }

    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        QCOMPARE(Node_p::letter(i+26), ru[i]);
    }
}

void TrieTest::test_contains_addWord()
{
    QStringList words;
    QString buf;

    for (int i = 'a'; i <= 'z'; i++)
    {
        buf.append(QChar(i));
        words << buf;
    }

    buf.clear();
    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        buf.append(ru[i]);
        words << buf;
    }

    Trie trie;

    foreach (QString word, words)
    {
        QCOMPARE(trie.contains(word), false);
        trie.addWord(word);
        QCOMPARE(trie.contains(word), true);
    }
}

void TrieTest::test_remove()
{
    QStringList words;
    QString buf;

    for (int i = 'a'; i <= 'z'; i++)
    {
        buf.append(QChar(i));
        words << buf;
    }

    buf.clear();
    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        buf.append(ru[i]);
        words << buf;
    }

    Trie trie;

    foreach (QString word, words)
    {
        trie.addWord(word);
    }

    foreach (QString word, words)
    {
        QCOMPARE(trie.contains(word), true);
        trie.remove(word);
        QCOMPARE(trie.contains(word), false);
    }
}

void TrieTest::test_words()
{
    QStringList wordsEn;
    QString buf;

    for (int i = 'a'; i <= 'z'; i++)
    {
        buf.append(QChar(i));
        wordsEn << buf;
    }

    buf.clear();

    QStringList wordsRu;
    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        buf.append(ru[i]);
        wordsRu << buf;
    }

    Trie trie;

    foreach (QString word, wordsEn)
    {
        trie.addWord(word);
    }

    foreach (QString word, wordsRu)
    {
        trie.addWord(word);
    }

    wordsEn.removeOne("a"); //en a
    wordsRu.removeOne("а"); //ru a

    QCOMPARE(trie.words("a", -1), wordsEn); //en a
    QCOMPARE(trie.words("а", -1), wordsRu); //ru a
}

QTEST_APPLESS_MAIN(TrieTest)

#include "tst_trietest.moc"
