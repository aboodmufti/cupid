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
        bool                            insertProject(Project*);
        bool                            insertAdministrator(Administrator*);
        bool                            insertStudent(StudentProfile*);
        int                             insertQualifications(QList<int>*);
        bool                            addStudentProject(int, int);
        bool                            addAdminProject(int projId, QString);
        Administrator*                  getAdminByUsername(QString);
        QList<Project*>*                 getAllProjects();
        Project*                        getProjectById(int);
        bool                            updateProject(Project*);
        bool                            publishProject(int);
        StudentProfile*                 getStudentProfile(int);
        QList<int>*                     getQualifications(int);
        QList<QList<QString>*>*         getStudentProjects(int);
        bool                            studentJoinedProject(int,int);
        bool                            updateStudentProfile(StudentProfile*);
        bool                            updateQualifications(QList<int>*);
        StudentProfile*                 getStudentByUsername(QString);
        bool                            setUpProjectTable();
        bool                            setUpStudentTable();
        bool                            setUpQualificationsTable();
        bool                            setUpProjectStudentTable();
        bool                            setUpAdministratorTable();
        bool                            setUpAdminProjectTable();
        QList<StudentProfile*>*         getStudentsInProject(int);
        QSqlQuery* getQueryObject();

    private:
        QSqlQuery                       *query;
        QSqlDatabase                     db;
};

#endif // STORAGE_H
