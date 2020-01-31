#include "mainwindow.h"
#include "cerrar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyle("fusion");
    w.show();
    return a.exec();


}

