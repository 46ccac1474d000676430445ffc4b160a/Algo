#include "widget.hpp"
#include <QApplication>
#include <ctime>

#include "structures/structure.hpp"

int main(int argc, char *argv[])
{
    srand(time(0));

    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    emit w.inited();

    return a.exec();
}
