#include "widget.hpp"
#include <QApplication>
#include <ctime>

#include "structures/structure.hpp"

int main(int argc, char *argv[])
{
    qsrand(time(0));
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
