#include "structure.hpp"

QRandomGenerator StructGenerator::rnd(QTime::currentTime().msecsSinceStartOfDay());

GeneratedStruct StructGenerator::generate(int ci, int br, int de, int gr, int wo)
{
    ci = ci > CITIES_C ? CITIES_C : ci;
    br = br > BRANCHES_C ? BRANCHES_C : br;
    de = de > DEPARTMENTS_C ? DEPARTMENTS_C : de;

    int c_size = ci * br * de * gr * wo;
    int percent = (c_size / 100) == 0 ? 1 : c_size / 100;
    int counter = 0;

    HashTable<City> cities(ci/3 > 8 ? ci/3 : 8);
    HashTable<WorkerData> workersData(c_size/3 > 8 ? c_size/3 : 8);

    int _ci = ci;
    while(ci--)
    {
        HashTable<Branch> branches(br/3 > 8 ? br/3 : 8);

        QString cityName = g_cities[_ci - ci - 1];

#ifdef local_struct_debug
        qDebug() << "CITY * * *" << cityName << endl;
#endif

        int b = br;
        while (b--)
        {
            HashTable<Department> departments(de/3 > 8 ? de/3 : 8);

            QString brName = QString("%1 филиал").arg(g_branches[br - b - 1]);

#ifdef local_struct_debug
            qDebug() << "BRANCH * * *" << brName << endl;
#endif

            int d = de;
            while (d--)
            {
                HashTable<Group> groups(gr/3 > 8 ? gr/3 : 8);

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

    return GeneratedStruct(cities, workersData);
}

void StructGenerator::run()
{
    emit structGenerated(generate(m_counts.cities, m_counts.branches, m_counts.departments, m_counts.groups, m_counts.workers));
    emit finished();
    deleteLater();
}
