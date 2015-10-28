#ifndef STORAGE_H
#define STORAGE_H
#include <QList>
#include "entity/StudentProfile.h"
#include <QtSql>

class Storage
{
public:
    Storage();
    Project* getProjectById(int);
    bool updateProject(Project*);
    bool publishProject(int);
    StudentProfile* getStudentProfile(int);
    QList<int>* getQualifications(int); // inside getStudentProfile()
    QList<Project*> getStudentProjects(int);
    bool StudentJoinedProject(int,int);
    bool updateStudentProfile(StudentProfile*);
    bool updateQualifications(QList<int>*);

private:
    QSqlQuery *query;
};

#endif // STORAGE_H
