#ifndef STORAGE_H
#define STORAGE_H
#include <QList>
#include <QtSql>

#include "entity/EntityDef.h"

#include <string>
#include <QString>
using namespace std;

class Storage
{
    public:
        Storage();
        int                            insertProject(Project*);    //abood
        bool                            insertAdministrator(Administrator*);
        bool                            insertStudent(StudentProfile*); //abood
        int                             insertQualifications(QList<int>*); //abood
        bool                            addStudentProject(int, int);  //abood
        bool                            addAdminProject(int projId, QString);
        Administrator*                  getAdminByUsername(QString);
        QList<Project*>*                 getAllProjects();          //abood
        Project*                        getProjectById(int);        //abood
        bool                            updateProject(Project*);
        bool                            publishProject(int);        //abood
        StudentProfile*                 getStudentProfile(int);     //abood
        QList<int>*                     getQualifications(int);
        QList<QList<QString>*>*         getStudentProjects(int);    //abood
        bool                            studentJoinedProject(int,int);
        bool                            updateStudentProfile(StudentProfile*); //abood
        bool                            updateQualifications(QList<int>*);
        StudentProfile*                 getStudentByUsername(QString);
        bool                            setUpProjectTable();
        bool                            setUpStudentTable();
        bool                            setUpQualificationsTable();
        bool                            setUpProjectStudentTable();
        bool                            setUpAdministratorTable();
        bool                            setUpAdminProjectTable();
        QList<StudentProfile*>*         getStudentsInProject(int);  //abood
        QSqlQuery* getQueryObject();

    private:
        QSqlQuery                       *query;
        QSqlDatabase                     db;
};

#endif // STORAGE_H
