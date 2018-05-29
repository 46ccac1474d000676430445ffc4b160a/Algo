#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <QVector>
#include <QLinkedList>
#include <QCryptographicHash>

#include <QDebug>

template <class T>
class HashTable
{
    int m_capacity;
    QVector< QLinkedList< QPair<QString, T> > > m_list;

    int hash(const QByteArray &data)
    {
        QByteArray hashsum = QCryptographicHash::hash(data, QCryptographicHash::Md5);

        int h = 0;

//        foreach (auto &val, hashsum)
//        {
//            h += val * val;
//        }

        h |= (hashsum[0] & 255) << 24;
        h |= (hashsum[1] & 255) << 16;
        h |= (hashsum[2] & 255) << 8;
        h |= hashsum[3] & 255;

        h &= 0x7fffffff;

        return h % m_capacity;
    }

public:
    HashTable(int cap = 256);

    bool exists(const QString &key);
    void add(const QString &key, const T &value);
    T get(const QString &key);
    bool remove(const QString &key);
    QVector<T> values();
    QStringList keys(int n = 0);

};

template<class T>
HashTable<T>::HashTable(int cap) :
    m_capacity(cap)
{
    m_list.reserve(cap);
    for (int i = 0; i < cap; i++)
    {
        m_list.append(QLinkedList<QPair<QString, T>>());
    }
}

template<class T>
bool HashTable<T>::exists(const QString &key)
{
    int index = hash(key.toUtf8());

    if (!m_list[index].isEmpty())
    {
        foreach (auto &val, m_list[index])
        {
            if (val.first == key) return true;
        }
    }

    return false;
}

template<class T>
void HashTable<T>::add(const QString &key, const T &value)
{
    int index = hash(key.toUtf8());

    m_list[index].append(QPair<QString, T>(key, value));
}

template<class T>
T HashTable<T>::get(const QString &key)
{
    int index = hash(key.toUtf8());

    if (!m_list[index].isEmpty())
    {
        foreach (auto &val, m_list[index])
        {
            if (val.first == key) return val.second;
        }
    }

    return T();
}

template<class T>
bool HashTable<T>::remove(const QString &key)
{
    int index = hash(key.toUtf8());

    if (!m_list[index].isEmpty())
    {
        foreach (auto &val, m_list[index])
        {
            if (val.first == key)
            {
                return m_list[index].removeOne(val);
            }
        }
    }

    return false;
}

template<class T>
QVector<T> HashTable<T>::values()
{
    QVector<T> vec;

    foreach(auto &list, m_list)
    {
        foreach(auto &val, list)
        {
            vec.append(val.second);
        }
    }

    return vec;
}

template<class T>
QStringList HashTable<T>::keys(int n)
{
    QStringList strlist;

    if(n > 0)
    {
        foreach(auto &list, m_list)
        {
            foreach(auto &val, list)
            {
                strlist << val.first;
                if (--n == 0) return strlist;
            }
        }
    }
    else
    {
        foreach(auto &list, m_list)
        {
            foreach(auto &val, list)
            {
                strlist << val.first;
            }
        }
    }

    return strlist;
}

#endif // HASHTABLE_HPP
