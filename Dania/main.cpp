#include "mainwindow.h"
#include <QApplication>

#include "mainwindow.h"
#include "StorageSubsystem/storage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString test = __FILE__;
    QString test2 = test.left(test.length() - 8);
    QString final_path = test2.append("style.qss");

    // Load an application style
    QFile styleFile( final_path );
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style( styleFile.readAll() );
    //a.setStyleSheet( style );
    //fff8ec
    MainWindow* w = new MainWindow();
    Storage* storage = new Storage();
    w->setStyleSheet(style);
    w->initialize(storage);
    w->show();


    //MainWindow* mainWindow = new MainWindow();

    return a.exec();
}
