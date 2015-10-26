#include "StudentProfile.h"


StudentPofile::StudentPofile(String userN ,String studentN ,int ID ){
    username = userN;
    studentName = studentN;
    studentID = ID;
}

//Getters
String StudentPofile::getUsername(){
    return username;
}

String StudentPofile::getStudentName(){
    return studentName;
}

int StudentPofile::getStudentID(){
    return studentID;
}

int* StudentPofile::getOwnQualifications(){
    return ownQualifications;
}

int* StudentPofile::getPartnerQualifications(){
    return partnerQualifications;
}

list<Team*> StudentPofile::getTeams(){
    return teams;
}

list<Projects*> StudentPofile::getProjects(){
    return projects;
}

//Setters
void StudentPofile::setUsername(String newUserName){
    username = newUserName;
}

void StudentPofile::setStudentName(String newStudentName){
    studentName = newStudentName;
}

void StudentPofile::setStudentID(int newID){
    studentID = newID;
}

void StudentPofile::setOwnQualifications(int* newList){
    ownQualifications = newList;
}

void StudentPofile::setPartnerQualifications(int* newList){
    partnerQualifications = newList;
}

void StudentPofile::addTeam(Team* newTeam){
    teams.push_back(newTeam);
}
void StudentPofile::addProject(Project* newProject){
    projects.push_back(newProject);
}
