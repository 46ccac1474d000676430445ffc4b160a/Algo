#ifndef STRUCTURE_HPP
#define STRUCTURE_HPP

#include "hashtable.hpp"
#include "names.hpp"
#include <stdexcept>
#include <QString>
#include <QStringList>

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

typedef HashTable<Branch> City;


class StructGenerator
{
    static QString rndstr()
    {
        QString str;

        int rn  = 5 + qrand() % 5;

        for (int i = 0; i < rn; i++)
        {
            str.append(char( 97 + qrand() % 26 ));
        }

        return str;
    }

    static QString rndname()
    {
        static int id = 1;

        return QString("%1 %2  id%3")
                .arg(last_names[qrand()%503])
                .arg(names[qrand()%615])
                .arg(id++);
    }

public:
    static QPair<HashTable<City>, HashTable<WorkerData>> generate(
                            int ci, // Cities
                            int br, // Branches
                            int de, // Departments
                            int gr, // Groups
                            int wo) // Workers
    {
        HashTable<City> cities;
        HashTable<WorkerData> workersData;

        while(ci--)
        {
            HashTable<Branch> branches;

            QString cityName = QString("C_%1").arg(rndstr());

#ifdef local_struct_debug
            qDebug() << "CITY * * *" << cityName << endl;
#endif

            int b = br;
            while (b--)
            {
                HashTable<Department> departments;

                QString brName = QString("B_%1").arg(rndstr());

#ifdef local_struct_debug
                qDebug() << "BRANCH * * *" << brName << endl;
#endif

                int d = de;
                while (d--)
                {
                    HashTable<Group> groups;

                    QString depName = QString("D_%1").arg(rndstr());

#ifdef local_struct_debug
                    qDebug() << "DEPARTMENT * * *" << depName << endl;
#endif

                    int g = gr;
                    while (g--)
                    {
                        QStringList workers;

                        QString grName = QString("G_%1").arg(rndstr());

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

};

#endif // STRUCTURE_HPP
