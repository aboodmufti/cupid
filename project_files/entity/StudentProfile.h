
#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H

#include <QString>
#include <QList>
#include "Project.h"

using namespace std;


class StudentProfile
{
  public:
    StudentProfile();
    QString           getUsername();
    QString           getName();
    int               getID();
    QList<int>*       getOwnQ();
    QList<int>*       getPartnerQ();
    //Qlist<Team*>      getTeams();
    QList<Project*>   getProjects();
    void              setUsername(QString);
    void              setName(QString);
    void              setID(int);
    void              setOwnQ(QList<int>*);
    void              setPartnerQ(QList<int>*);
    //void              setTeams(Team*);
    void              addProject(Project*);
    void              setProjects(QList<Project*>);
    
  private:
    QString           username;
    QString           studentName;
    int               studentID;
    QList<int>*       ownQualifications;
    QList<int>*       partnerQualifications;
    //QList<Team*>      teams;
    QList<Project*>   projects;

};

#endif
