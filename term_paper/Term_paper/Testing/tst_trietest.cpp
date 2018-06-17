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
        QCOMPARE(Node_p::p_indexHelper(QChar(i)), i-'a');
    }

    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        QCOMPARE(Node_p::p_indexHelper(ru[i]), i+26);
    }

    for (int i = '0'; i <= '9'; i++)
    {
        QCOMPARE(Node_p::p_indexHelper(QChar(i)), i-'0'+59);
    }
}

void TrieTest::test_letter()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        QCOMPARE(Node_p::p_letterHelper(i-'a'), QChar(i));
    }

    QString ru = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < ru.size(); i++)
    {
        QCOMPARE(Node_p::p_letterHelper(i+26), ru[i]);
    }

    for (int i = '0'; i <= '9'; i++)
    {
        QCOMPARE(Node_p::p_letterHelper(i-'0'+59), QChar(i));
    }
}

void TrieTest::test_contains_addWord()
{
    QStringList words;

    QFile f(QDir::currentPath()+"/dict.txt");
    if (f.open(QIODevice::ReadOnly))
    {
        QString buf(f.readAll());
        buf.remove('\r');

        words = buf.split('\n');

        f.close();
    }
    else
    {
        QWARN("dict.txt not open");
        return;
    }

    Trie trie;

    foreach (QString word, words)
    {
        QCOMPARE(trie.contains(word), false);
    }

    foreach (QString word, words)
    {
        if (trie.contains(word)) qWarning() << "trie already contains:" << word;
        QCOMPARE(trie.contains(word), false);
        trie.addWord(word);
        QCOMPARE(trie.contains(word), true);
    }

    foreach (QString word, words)
    {
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

    int c = 0;
    foreach (QString word, words)
    {
        c++;
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

    QCOMPARE(trie.words("Zorg", -1), QStringList());

    trie.addWord("Анубис");
    QCOMPARE(trie.words("Ану"), QStringList() << "Анубис");
}

QTEST_APPLESS_MAIN(TrieTest)

#include "tst_trietest.moc"
