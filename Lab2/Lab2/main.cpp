#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFont(QFont(QApplication::font().defaultFamily(), 13));
    w.setGeometry(50, 100, 1000, 600);
    w.showMaximized();

    return a.exec();
}
