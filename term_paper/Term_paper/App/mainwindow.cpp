#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str;
    for (int i = 'a'; i <= 'z'; i++)
    {
        str.append(QChar(i));
        Trie::trie().addWord(str);
    }

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);


    QVBoxLayout *vlay = new QVBoxLayout();
    vlay->addWidget(new TextEdit());
    ui->tab->setLayout(vlay);
}

MainWindow::~MainWindow()
{
    delete ui;
}
