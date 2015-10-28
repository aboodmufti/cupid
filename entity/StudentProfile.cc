#include "StudentProfile.h"


StudentProfile::StudentProfile(){
    username = "unknown";
    studentName = "unknown";
    studentID = -1;
}

//Getters
QString StudentProfile::getUsername(){
    return username;
}

QString StudentProfile::getName(){
    return studentName;
}

int StudentProfile::getID(){
    return studentID;
}

QList<int>*  StudentProfile::getOwnQ(){
    return ownQualifications;
}

QList<int>*  StudentProfile::getPartnerQ(){
    return partnerQualifications;
}
/*
QList<Team*> StudentProfile::getTeams(){
    return teams;
}
*/
QList<Projects*> StudentProfile::getProjects(){
    return projects;
}

//Setters
void StudentProfile::setUsername(QString newUserName){
    username = newUserName;
}

void StudentProfile::setName(QString newStudentName){
    studentName = newStudentName;
}

void StudentProfile::setID(int newID){
    studentID = newID;
}

void StudentProfile::setOwnQ(QList<int>*  newList){
    ownQualifications = newList;
}

void StudentProfile::setPartnerQ(QList<int>*  newList){
    partnerQualifications = newList;
}

/*
void StudentProfile::addTeam(Team* newTeam){
    teams += newTeam;
}
*/
void StudentProfile::addProject(Project* newProject){
    projects += newProject;
}
