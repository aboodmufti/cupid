
#ifndef STUDENT_PROFILE_H
#define STUDENT_PROFILE_H

#include <iostream>
#include <QString>
#include <QList>

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
    QList<Projects*>  getProjects();
    void              setUsername(String);
    void              setName(String);
    void              setID(int);
    void              setOwnQ(QList<int>*);
    void              setPartnerQ(QList<int>*);
    //void              addTeam(Team*);  // What about remove?
    void              addProject(Project*);
    
  private:
    QString           username;
    QString           studentName;
    int               studentID;
    QList<int>*        ownQualifications;
    QList<int>*        partnerQualifications;
    //QList<Team*>      teams;
    QList<Projects*>  projects;
};

#endif
