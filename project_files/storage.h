#ifndef STORAGE_H
#define STORAGE_H

#include <QtSql>

class Storage
{
public:
    Storage();
    bool insertProject(Project *proj);
    bool insertAdministrator(Administrator *admin);
    bool insertStudent(StudentProfile *stuProfile);
    int insertQualifications(Qualifications *qualifications);
    bool addStudentProject(int projId, int stuId);
    bool addAdminProject(int projId, QString adminUsername);
    Administrator* getAdminByUsername(QString adminUsername);
    QList<Project*> getAllProjects();

private:
    QSqlQuery *query;
};

#endif // STORAGE_H
