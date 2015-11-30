#include "mainwindow.h"
#include <QApplication>
#include "database/storage.h"
#include "entity/EntityDef.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initialize();
    w.show();


    return a.exec();

}


