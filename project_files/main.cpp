#include "mainwindow.h"
#include <QApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initialize();
    w.show();

    DatabaseManager *db = new DatabaseManager();

    return a.exec();
}
