#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Graph<QString, QGraphicsEllipseItem*> g;

//    int n = 15;
//    for (int i = 0; i < n; i++)
//    {
//        g.addVertex(QString::number(i+1));
//    }

//    for (int i = 0; i < n; i++)
//    {
//        g.addEdge(QString::number(i+1), QString::number(n-i));
//    }

    g.addVertex("Вершина 1");
    g.addVertex("Вершина 2");
    g.addVertex("Вершина 3");
    g.addVertex("Вершина 4");
    g.addVertex("Вершина 5");
    g.addVertex("Вершина 6");

    g.addEdge("Вершина 1", "Вершина 2");
    g.addEdge("Вершина 2", "Вершина 3");
    g.addEdge("Вершина 3", "Вершина 4");
    g.addEdge("Вершина 4", "Вершина 5");
    g.addEdge("Вершина 5", "Вершина 6");
    g.addEdge("Вершина 6", "Вершина 3");
    g.addEdge("Вершина 5", "Вершина 1");
    g.addEdge("Вершина 4", "Вершина 2");

    QRectF rect(0., 0., 600., 600.);

    auto scene = new GraphPresentation(rect, this);
    scene->setGraph(g);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAttribute(Qt::WA_AlwaysShowToolTips);
}

MainWindow::~MainWindow()
{
    delete ui;
}
