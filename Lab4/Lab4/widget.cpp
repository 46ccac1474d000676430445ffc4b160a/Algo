#include "widget.hpp"
#include "ui_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    workersData(2048)
{
    ui->setupUi(this);

    ui->searchFormData->setIcon(QIcon(":/find.png"));
    ui->searchFormData->setShortcut(QKeySequence("return"));
    ui->searchFormData_2->setIcon(QIcon(":/find.png"));
    ui->searchFormData_2->setShortcut(QKeySequence("return"));

    connect(ui->listWidget_2, &QListWidget::itemDoubleClicked, this, &MainWindow::on_listWidget_itemDoubleClicked);

    show();

    Dialog *d = new Dialog(this);
    d->open();

    connect(d, &Dialog::finished, [=](int val) -> void {
        if (val == QDialog::Accepted)
        {
            Counts c;
            c.cities = d->citiesCount();
            c.branches = d->branchesCount();
            c.departments = d->departmentsCount();
            c.groups = d->groupsCount();
            c.workers = d->workersCount();

            on_countsEntered(c);
        }
        else
        {
            close();
        }

        d->deleteLater();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchFormData_clicked()
{
    QString city = ui->cityInput->currentText(),
            branch = ui->branchInput->currentText(),
            department = ui->departmentInput->currentText(),
            group = ui->groupInput->currentText();

    ui->listWidget->clear();

    if (!city.isEmpty())
    {
        if (cities.exists(city))
        {
            if (!branch.isEmpty())
            {
                if (cities.get(city).exists(branch))
                {
                    if (!department.isEmpty())
                    {
                        if (cities.get(city).get(branch).departments.exists(department))
                        {
                            if (!group.isEmpty())
                            {
                                if (cities.get(city).get(branch).departments.get(department).groups.exists(group))
                                {
                                    auto item = new QListWidgetItem(QString("Начальник группы: %1")
                                                                    .arg(cities
                                                                         .get(city)
                                                                         .get(branch)
                                                                         .departments
                                                                         .get(department)
                                                                         .groups
                                                                         .get(group)
                                                                         .headName));

                                    item->setBackground(QBrush("#ee9090"));
                                    ui->listWidget->addItem(item);

                                    ui->listWidget->addItems(cities
                                                            .get(city)
                                                            .get(branch)
                                                            .departments
                                                            .get(department)
                                                            .groups
                                                            .get(group)
                                                            .workers);
                                }
                                else
                                {
                                    QMessageBox::information(this, "Поиск группы", QString("Группа \"%1\"не найдена").arg(group));
                                }
                            }
                            else
                            {
                                auto item = new QListWidgetItem(QString("Начальник отдела: %1")
                                                                .arg(cities
                                                                     .get(city)
                                                                     .get(branch)
                                                                     .departments
                                                                     .get(department)
                                                                     .headName));

                                item->setBackground(QBrush("#ee9090"));
                                ui->listWidget->addItem(item);

                                ui->listWidget->addItems(cities
                                                         .get(city)
                                                         .get(branch)
                                                         .departments
                                                         .get(department)
                                                         .groups
                                                         .keys());
                            }
                        }
                        else
                        {
                            QMessageBox::information(this, "Поиск отдела", QString("Отдел \"%1\"не найден").arg(department));
                        }
                    }
                    else
                    {
                        auto item = new QListWidgetItem(QString("Директор: %1")
                                                        .arg(cities
                                                        .get(city)
                                                        .get(branch)
                                                        .headName));
                        item->setBackground(QBrush("#ee9090"));
                        ui->listWidget->addItem(item);

                        ui->listWidget->addItems(cities
                                                .get(city)
                                                .get(branch)
                                                .departments
                                                .keys());
                    }
                }
                else
                {
                    QMessageBox::information(this, "Поиск филиала", QString("Филиал \"%1\"не найден").arg(branch));
                }
            }
            else
            {
                ui->listWidget->addItems(cities.get(city).keys());
            }
        }
        else
        {
            QMessageBox::information(this, "Поиск города", QString("Город \"%1\"не найден").arg(city));
        }
    }
}

void MainWindow::on_cityInput_currentTextChanged(const QString &city)
{
    QStringList s_list;
    s_list << QString();
    s_list << cities.get(city).keys();

    ui->branchInput->clear();
    ui->branchInput->addItems(s_list);
}

void MainWindow::on_branchInput_currentTextChanged(const QString &branch)
{
    QStringList s_list;
    s_list << QString();
    s_list << cities
              .get(ui->cityInput->currentText())
              .get(branch)
              .departments
              .keys();

    ui->departmentInput->clear();
    ui->departmentInput->addItems(s_list);
}

void MainWindow::on_departmentInput_currentTextChanged(const QString &department)
{
    QStringList s_list;
    s_list << QString();
    s_list << cities
              .get(ui->cityInput->currentText())
              .get(ui->branchInput->currentText())
              .departments
              .get(department)
              .groups
              .keys();

    ui->groupInput->clear();
    ui->groupInput->addItems(s_list);
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QListWidget *l_wgt = dynamic_cast<QListWidget*>(sender());

    qApp->clipboard()->setText(item->text());

    auto lbl = new QLabel("Текс скопирован", l_wgt);
    lbl->setGraphicsEffect(new QGraphicsOpacityEffect());
    lbl->setStyleSheet(
                "background: #666e77;"
                "border-radius: 10px;"
                "padding: 10px;"
                       );

    QRect r;
    r.setLeft(l_wgt->width()/2 - lbl->sizeHint().width()/2);
    r.setTop(l_wgt->height()/2 - lbl->sizeHint().height()/2);
    r.setSize(lbl->sizeHint());

    lbl->setGeometry(r);

    lbl->show();

    QTimer *t = new QTimer(lbl);
    connect(t, &QTimer::timeout, [=]() -> void {
        static int level = 150;
        static_cast<QGraphicsOpacityEffect*>(lbl->graphicsEffect())->setOpacity(level*0.01);
        level--;
        if (!level)
        {
            t->deleteLater();
            lbl->deleteLater();
            level = 150;
        }
    });
    t->start(20);
}

void MainWindow::on_searchFormData_2_clicked()
{
    ui->listWidget_2->clear();

    if (!ui->nameInput->currentText().isEmpty()) ui->nameInput->addItem(ui->nameInput->currentText());

    if (workersData.exists(ui->nameInput->currentText()))
    {
        WorkerData data = workersData.get(ui->nameInput->currentText());

        QStringList s_list;
        if (!data.group.isEmpty()) s_list << QString("Группа: %1").arg(data.group);
        if (!data.department.isEmpty()) s_list << QString("Отдел: %1").arg(data.department);
        if (!data.branch.isEmpty()) s_list << QString("Филиал: %1").arg(data.branch);
        if (!data.city.isEmpty()) s_list << QString("Город: %1").arg(data.city);

        ui->listWidget_2->addItems(s_list);
    }
    else
    {
        QMessageBox::information(this, "Поиск сотрудника", QString("Сотрудник \"%1\" не найден").arg(ui->nameInput->currentText()));
    }
}

void MainWindow::on_countsEntered(const Counts &c)
{
    ui->tabWidget->setDisabled(true);

    auto prog = new QProgressBar(this);
    this->layout()->addWidget(prog);
    prog->setRange(0, 100);
    prog->setToolTip("Прогресс генерации структуры организации");
    prog->show();

    auto stGen = new StructGenerator(c);

    auto t = new QThread();
    stGen->moveToThread(t);

    connect(stGen, &StructGenerator::finished, t, &QThread::quit, Qt::DirectConnection);
    connect(t, &QThread::finished, t, &QThread::quit, Qt::DirectConnection);
    connect(this, &MainWindow::destroyed, t, &QThread::quit, Qt::DirectConnection);

    connect(t, &QThread::started, stGen, &StructGenerator::run);

    connect(stGen, &StructGenerator::progressUpdated, prog, &QProgressBar::setValue);

    connect(stGen, &StructGenerator::structGenerated, this, &MainWindow::on_structGenerated);
    connect(stGen, &StructGenerator::finished, prog, &QProgressBar::deleteLater);

    t->start(QThread::TimeCriticalPriority);
}

void MainWindow::on_structGenerated(const GeneratedStruct &val)
{
    cities = val.first;
    workersData = val.second;

    QStringList s_list;
        s_list << QString();
        s_list << cities.keys();

    ui->cityInput->addItems(s_list);

    ui->tabWidget->setEnabled(true);
}

void MainWindow::on_writeButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить", QDir::homePath());

    if (!fileName.isEmpty())
    {
        QFile f(fileName);
        if (f.open(QIODevice::WriteOnly))
        {
            qApp->setOverrideCursor(Qt::WaitCursor);

            QTextStream s(&f);
            s.setCodec("UTF-8");

            QStringList s_list = workersData.keys(10000);

            foreach (const QString &val, s_list)
            {
                s << val << "\n";
            }

            f.close();

            qApp->restoreOverrideCursor();

            QMessageBox::information(this, "Запись в файл", QString("Запись в файл \"%1\" прошла успешно!").arg(fileName));

        }
        else
        {
            QMessageBox::warning(this, "Сохранение файла", QString("Не удалось сохранить файл \"%1\"").arg(fileName));
        }
    }
}

void MainWindow::on_readButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath());

    if (!fileName.isEmpty())
    {
        QFile f(fileName);
        if(f.open(QIODevice::ReadOnly))
        {
            qApp->setOverrideCursor(Qt::WaitCursor);

            QString tmp(f.readAll());

            f.close();

            ui->listWidget_2->clear();

            QStringList s_list = tmp.split("\n", QString::SkipEmptyParts);

            foreach (const QString &key, s_list)
            {
                if (workersData.exists(key))
                {
                    auto name = new QListWidgetItem(key);
                    name->setBackground(QBrush("#90ee90"));

                    ui->listWidget_2->addItem(name);

                    WorkerData data = workersData.get(key);

                    QStringList s_list;
                    if (!data.group.isEmpty()) s_list << QString("Группа: %1").arg(data.group);
                    if (!data.department.isEmpty()) s_list << QString("Отдел: %1").arg(data.department);
                    if (!data.branch.isEmpty()) s_list << QString("Филиал: %1").arg(data.branch);
                    if (!data.city.isEmpty()) s_list << QString("Город: %1").arg(data.city);

                    ui->listWidget_2->addItems(s_list);
                }
                else
                {
                    auto name = new QListWidgetItem(QString("Сотрудник \"%1\" не найден").arg(key));
                    name->setBackground(QBrush("#ee9090"));

                    ui->listWidget_2->addItem(name);
                }
            }

            qApp->restoreOverrideCursor();

            QMessageBox::information(this, "Чтение файла", QString("Чтение из файла \"%1\" окончено").arg(fileName));

        }
        else
        {
            QMessageBox::warning(this, "Чтение файла", QString("Невозможно открыть файл \"%1\"").arg(fileName));
        }
    }
}
