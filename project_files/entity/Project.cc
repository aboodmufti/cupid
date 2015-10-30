#include "Project.h"


Project::Project(){
  projectName = "unknown";
  minTeamSize = -1;
  maxTeamSize = -1;
  projectDescription = "unknown";
  id = -1;
  status = "NOT_PUBLISHED";
}

Project::~Project(){

}

int Project::getID(){
    return id;
}

QString Project::getName(){
  return projectName;
}

int Project::getMinTeamSize(){
  return minTeamSize;
}

int Project::getMaxTeamSize(){
  return maxTeamSize;
}

QString Project::getDescription(){
  return projectDescription;
}

QString Project::getStatus(){
  return status;
}

void Project::setID(int newID){
    id = newID;
}

void Project::setName(QString name){
  projectName = name;
}

void Project::setMinTeamSize(int min){
  minTeamSize = min;
}

void Project::setMaxTeamSize(int max){
  maxTeamSize = max;
}

void Project::setDescription(QString description){
  projectDescription = description;
}

void Project::setStatus(QString newStatus){
  status = newStatus;
}
