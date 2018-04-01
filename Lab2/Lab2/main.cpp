#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.setFont(QFont(QApplication::font().defaultFamily(), 10));
    w.setGeometry(50, 100, 1000, 600);
    w.showMaximized();

    return a.exec();
}
