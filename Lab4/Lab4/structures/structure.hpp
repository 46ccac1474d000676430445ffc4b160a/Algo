#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include "hashtable.hpp"
#include "names.hpp"
#include <stdexcept>
#include <QString>
#include <QStringList>
#include <QObject>

#include <QRandomGenerator>
#include <QTime>

//#define local_struct_debug

/*

  City
    |
  Branch, HeadName
    |
  Department, HeadName
    |
  Group, HeadName
    |
  Workers (1, 2, ..., n)

 */

struct Group
{
    QString headName;
    QStringList workers;
};

struct Department
{
    QString headName;
    HashTable<Group> groups; // key is name of group
};

struct Branch
{
    QString headName;
    HashTable<Department> departments; // key is name of department
};

struct WorkerData
{
    const QString city;
    const QString branch;
    const QString department;
    const QString group;
    WorkerData(){}
    WorkerData(const QString c, const QString b, const QString d = QString(), const QString g = QString()) :
        city(c),
        branch(b),
        department(d),
        group(g)
    {}
};

struct Counts
{
    int cities;
    int branches;
    int departments;
    int groups;
    int workers;
};

typedef HashTable<Branch> City;


class StructGenerator : public QObject
{
    Q_OBJECT

    static QRandomGenerator rnd;

    static QString rndname()
    {
        static int id = 1;

        return QString("%1 %2  id%3")
                .arg(last_names[rnd.generate() % LNAMES_C])
                .arg(names[rnd.generate() % NAMES_C])
                .arg(id++);
    }

    Counts m_counts;

    QPair<HashTable<City>, HashTable<WorkerData>> generate(
                            int ci, // Cities
                            int br, // Branches
                            int de, // Departments
                            int gr, // Groups
                            int wo);

public:
    StructGenerator(const Counts &c) :
        QObject(0),
        m_counts(c)
    {}

public slots:
    void run();

signals:
    void progressUpdated(int);
    void structGenerated(const QPair<HashTable<City>, HashTable<WorkerData>>&);
    void finished();

};

#endif // STRUCTURE_HPP
