#include "mainwindow.h"
#include <QApplication>

#include "mainwindow.h"
#include "StorageSubsystem/storage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
   Storage* storage = new Storage();
    w->initialize(storage);
    w->show();


    //MainWindow* mainWindow = new MainWindow();

    return a.exec();
}
