#include "widget.hpp"
#include <QApplication>

#include "structures/structure.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    return a.exec();
}
