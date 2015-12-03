#include "mainwindow.h"
#include <QApplication>
//#include "database/storage.h"
//#include "entity/EntityDef.h"
#include "StorageSubsystem/storage.h"
//#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initialize();
    w.show();

    //std::cout << "MAIN!";
    qDebug() << "In Main";
    return a.exec();

}


