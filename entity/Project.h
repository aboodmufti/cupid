#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>

using namespace std;

class Project
{
  public:
    Project(String,int,int,String);
   ~Project();
    String    getProjectName();
    int       getTeamSizeMin();
    int       getTeamSizeMax();
    String    getProjectDescription();
    String    getStatus();
    void      setProjectName(String);
    void      setTeamSizeMin(int);
    void      setTeamSizeMax(int);
    void      setProjectDescription(String);
    void      setStatus(String);
    /*String  projectName;
    int     teamSizeMin;
    int     teamSizeMax;
    String  projectDescription;
    String  status;*/

  private:
    String  projectName;
    int     teamSizeMin;
    int     teamSizeMax;
    String  projectDescription;
    String  status;
};

#endif
