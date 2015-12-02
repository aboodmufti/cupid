#ifndef ALGORITHMMANAGER_H
#define ALGORITHMMANAGER_H


#include "entity/EntityDef.h"
#include "database/storage.h"
//#include "StorageSubsytem/Defs.h"

#include "mainwindow.h"

#include <QMap>
#include <QtMath>

class MainWindow;

class AlgorithmManager
{
public:
    //AlgorithmManager(Storage* storage, MainWindow* main);
    AlgorithmManager();
    void runAlgorithm(Project* project, QList<StudentProfile*>* studentsInProject);

private:
    Storage* storage;
    MainWindow* mainWindow;

    QList<QMap<QString, int>*>* preventiveMeasures(int minSize, int maxSize, int numStudents);
    QList<QMap<int, QMap<int,int>*>*>* step1(QList<StudentProfile*>* studentsInProject);
    QList<QList<int>*>* step2(QList<QMap<int, QMap<int,int>*>*>* individualScoreList);
    void step3(QList<QMap<QString, int>*>* initialTeams, QList<QList<int>*>* finalList, QList<int>* listOfIds);
    QList<int>* idList(QList<StudentProfile*>* studentsInProject);
};

#endif // ALGORITHMMANAGER_H
