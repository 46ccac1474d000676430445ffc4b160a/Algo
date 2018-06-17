#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile f(QDir::currentPath()+"/dict.txt");
    if (f.open(QIODevice::ReadOnly))
    {
        QString buf(f.readAll());
        buf.remove('\r');
        QStringList list = buf.split('\n', QString::SkipEmptyParts);
        f.close();

        foreach (auto val, list)
        {
            Trie::obj() << val;
        }
    }
    else qDebug() << "dict.txt not open";

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);

    ui->tabWidget->addTab(new TextEdit(), "Sometab");
}

MainWindow::~MainWindow()
{
    delete ui;
}
