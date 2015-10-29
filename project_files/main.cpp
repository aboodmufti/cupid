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

    qDebug() << "adminTable " << storage->setUpAdministratorTable();
    qDebug() << "adminProjectTable " << storage->setUpAdminProjectTable();
    qDebug() << "ProjectStudentTable " << storage->setUpProjectStudentTable();
    qDebug() << "projectTable " << storage->setUpProjectTable();
    qDebug() << "Q table " << storage->setUpQualificationsTable();
    qDebug() << "student table " << storage->setUpStudentTable();

    StudentProfile* stu = new StudentProfile();
    QList<int>* ownq = new QList<int>();

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


    stu->setID(10023492);
    stu->setName("Hussam");

    stu->setOwnQ(ownq);
    stu->setPartnerQ(ownq);

    stu->setUsername("hussamabubaker");

    qDebug() << "insert student " << storage->insertStudent(stu);

    StudentProfile* newStu = storage->getStudentByUsername("hussamabubaker");

    qDebug() << newStu->getName();

    return a.exec();
}
