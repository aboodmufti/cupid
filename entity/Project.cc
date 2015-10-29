#include "Project.h"

Project::Project(String name, int min, int max, int description){
  projectName = name;
  teamSizeMin = min;
  teamSizeMax = max;
  projectDescription = description;
}

String Project::getProjectName(){
  return projectName;
}

int Project::getTeamSizeMin(){
  return teamSizeMin;
}

int Project::getTeamSizeMax(){
  return teamSizeMax;
}

String Project::getProjectDescription(){
  return projectDescription;
}

String Project::getStatus(){
  return status;
}

void Project::setProjectName(String name){
  projectName = name;
}

void Project::setTeamSizeMin(int min){
  teamSizeMin = min;
}

void Project::setTeamSizeMax(int max){
  teamSizeMax = max;
}

void Project::setProjectDescription(String description){
  projectDescription = description;
}

void Project::setStatus(String newStatus){
  status = newStatus;
}
