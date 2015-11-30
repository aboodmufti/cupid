#include "Administrator.h"
#include <QString>

Administrator::Administrator() : User() {}



void Administrator::addProject(Project* project){
    projects += project;
}
