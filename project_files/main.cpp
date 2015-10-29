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

    Storage* storage = new Storage();

    storage->setUpAdministratorTable();
    storage->setUpAdminProjectTable();
    storage->setUpProjectStudentTable();
    storage->setUpProjectTable();
    storage->setUpQualificationsTable();
    storage->setUpStudentTable();

    StudentProfile* stu = new StudentProfile();
    QList<int>* ownq = new QList<int>();
    qDebug() << "DEBUG 6";
    (*(ownq)) += 1;
    (*(ownq)) += 1;
    (*(ownq)) += 2;
    (*(ownq)) += 3;
    (*(ownq)) += 4;
    (*(ownq)) += 5;
    (*(ownq)) += 6;
    (*(ownq)) += 6;
    (*(ownq)) += 7;
    (*(ownq)) += 8;
    (*(ownq)) += 9;
    (*(ownq)) += 12;
    (*(ownq)) += 14;
    (*(ownq)) += 19;
    qDebug() << "DEBUG 7";

    stu->setID(10023492);
    stu->setName("Hussam");
    qDebug() << "DEBUG 10";
    stu->setOwnQ(ownq);
    stu->setPartnerQ(ownq);
    qDebug() << "DEBUG 11";
    stu->setUsername("hussamabubaker");

    storage->insertStudent(stu);
    qDebug() << "DEBUG 12";
    StudentProfile* newStu = storage->getStudentByUsername("hussamabubaker");
    qDebug() << "DEBUG 13";
    qDebug() << newStu->getName();

    return a.exec();
}
