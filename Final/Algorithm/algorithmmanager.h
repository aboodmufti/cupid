#ifndef ALGORITHMMANAGER_H
#define ALGORITHMMANAGER_H


//#include "entity/EntityDef.h"
//#include "database/storage.h"
#include "StorageSubsystem/storage.h"

#include "mainwindow.h"
#include "algorithmsummary.h"
#include "detailedresults.h"

#include <QMap>
#include <QtMath>

class MainWindow;
class Storage;

class AlgorithmSummary;
class DetailedResults;

class AlgorithmManager
{
public:
    AlgorithmManager(Storage* storage, MainWindow* main);
    //AlgorithmManager(MainWindow* main);
    void runAlgorithm(Project* project, QList<StudentProfile*>* studentsInProject);
    void goToProject();
    void goToSummary();
    void goToDetails();
    Storage* getStorage();

private:
    Storage* storage;
    MainWindow* mainWindow;
    QString output;
    QString* output2;
    AlgorithmSummary* algoPage;
    //DetailedResults* detailedPage;
    int pid;
    QList<QMap<QString, int>*>* initialTeams2;

    QList<QMap<QString, int>*>* preventiveMeasures(int minSize, int maxSize, int numStudents);
    QList<QMap<int, QMap<int,int>*>*>* step1(QList<StudentProfile*>* studentsInProject);
    QList<QList<int>*>* step2(QList<QMap<int, QMap<int,int>*>*>* individualScoreList);
    QString step3(QList<QMap<QString, int>*>* initialTeams, QList<QList<int>*>* finalList, QList<int>* listOfIds);
    QList<int>* idList(QList<StudentProfile*>* studentsInProject);
    int coef(int score, int q);
};

#endif // ALGORITHMMANAGER_H
