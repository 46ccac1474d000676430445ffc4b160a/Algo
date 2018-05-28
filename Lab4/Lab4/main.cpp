#include "widget.hpp"
#include <QApplication>
#include <ctime>

#include "structures/structure.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qsrand(time(0));

    MainWindow w;
    w.show();
    emit w.inited();

    return a.exec();
}
