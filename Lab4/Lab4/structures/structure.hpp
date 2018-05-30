#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include "hashtable.hpp"
#include "names.hpp"
#include <stdexcept>
#include <QString>
#include <QStringList>
#include <QObject>

#include <cstdlib>
#include <ctime>

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

    static QString rndname()
    {
        static int id = 1;

        return QString("%1 %2  id%3")
                .arg(last_names[rand()%LNAMES_C])
                .arg(names[rand()%NAMES_C])
                .arg(id++);
    }

    Counts m_counts;

    QPair<HashTable<City>, HashTable<WorkerData>> generate(
                            int ci, // Cities
                            int br, // Branches
                            int de, // Departments
                            int gr, // Groups
                            int wo) // Workers
    {
        ci = ci > CITIES_C ? CITIES_C : ci;
        br = br > BRANCHES_C ? BRANCHES_C : br;
        de = de > DEPARTMENTS_C ? DEPARTMENTS_C : de;

        int c_size = ci * br * de * gr * wo;
        int percent = (c_size / 100) == 0 ? 1 : c_size / 100;
        int counter = 0;

        HashTable<City> cities;
        HashTable<WorkerData> workersData;

        int _ci = ci;
        while(ci--)
        {
            HashTable<Branch> branches;

            QString cityName = g_cities[_ci - ci - 1];

#ifdef local_struct_debug
            qDebug() << "CITY * * *" << cityName << endl;
#endif

            int b = br;
            while (b--)
            {
                HashTable<Department> departments;

                QString brName = QString("%1 филиал").arg(g_branches[br - b - 1]);

#ifdef local_struct_debug
                qDebug() << "BRANCH * * *" << brName << endl;
#endif

                int d = de;
                while (d--)
                {
                    HashTable<Group> groups;

                    QString depName = g_departments[de - d - 1];

#ifdef local_struct_debug
                    qDebug() << "DEPARTMENT * * *" << depName << endl;
#endif

                    int g = gr;
                    while (g--)
                    {
                        QStringList workers;

                        QString grName = QString("Группа %1").arg(gr - g);

#ifdef local_struct_debug
                        qDebug() << "GROUP * * *" << grName << endl;
#endif

                        int w = wo;
                        while (w--)
                        {
                            QString worker = rndname();
                            workers << worker;

                            workersData.add(worker, WorkerData(cityName,
                                                               brName,
                                                               depName,
                                                               grName));

                            counter++;
                            if (counter % percent == 0) emit progressUpdated(counter / percent);

#ifdef local_struct_debug
                            qDebug() << worker;
#endif
                        } // Workers

                        Group group;
                        group.headName = rndname();
                        group.workers = workers;

                        workersData.add(group.headName, WorkerData(cityName,
                                                           brName,
                                                           depName,
                                                           grName));

                        groups.add(grName, group);

                    } // Groups

                    Department department;
                    department.headName = rndname();
                    department.groups = groups;

                    workersData.add(department.headName, WorkerData(cityName,
                                                       brName,
                                                       depName));

                    departments.add(depName, department);

                } // Departments

                Branch branch;
                branch.headName = rndname();
                branch.departments = departments;

                workersData.add(branch.headName, WorkerData(cityName, brName));

                branches.add(brName, branch);

            } // Branches

            cities.add(cityName, branches);

        } // Cities

        return QPair<HashTable<City>, HashTable<WorkerData>>(cities, workersData);
    }

public:
    StructGenerator(const Counts &c) :
        QObject(0),
        m_counts(c)
    {}

public slots:
    void run()
    {
        emit structGenerated(generate(m_counts.cities, m_counts.branches, m_counts.departments, m_counts.groups, m_counts.workers));
        emit finished();
        deleteLater();
    }

signals:
    void progressUpdated(int);
    void structGenerated(const QPair<HashTable<City>, HashTable<WorkerData>>&);
    void finished();

};

#endif // STRUCTURE_HPP
