
#ifndef STUDENT_PROFILE_H
#define STUDENT_PROFILE_H

#include <iostream>
#include <string>

using namespace std;


class StudentPofile 
{
  public:
    StudentPofile(String,String,int);
    String            getUsername();
    String            getStudentName();
    int               getStudentID();
    int*              getOwnQualifications();
    int*              getPartnerQualifications();
    list<Team*>       getTeams();
    list<Projects*>   getProjects();
    void              setUsername(String);
    void              setStudentName(String);
    void              setStudentID(int);
    void              setOwnQualifications(int*);
    void              setPartnerQualifications(int*);
    void              addTeam(Team*);  // What about remove?
    void              addProject(Project*);
    
  private:
    String            username;
    String            studentName;
    int               studentID;
    int*              ownQualifications[13];
    int*              partnerQualifications[13];
    list<Team*>       teams;
    list<Projects*>   projects;
};

#endif