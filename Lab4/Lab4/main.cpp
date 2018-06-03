#include "widget.hpp"
#include <QApplication>

#include "structures/structure.hpp"

int main(int argc, char *argv[])
{
    qRegisterMetaType<GeneratedStruct>("GeneratedStruct");

    QApplication a(argc, argv);

    MainWindow w;

    return a.exec();
}
