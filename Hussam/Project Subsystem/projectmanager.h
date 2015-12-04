#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QMainWindow>


#include "createprojectpage.h"
#include "projectpage.h"
#include "editprojectpage.h"
#include "studentprojectspage.h"
#include "mainwindow.h"

#include "database/storage.h"
/* control class for the project subsystem */

//namespace Ui {
//class ProjectManager;
//}

class ProjectManager : public QMainWindow
{
    Q_OBJECT

public:
    void joinProject(int pid);
    int  createProject(Project*);
    void openProject(int);
    void editProject(int);
    void updateProject(Project*);
    void publishProject(int);
    void viewProjects();
    Storage* getStorage();
    MainWindow* getMain();
    void displayStudentProfile(int,int);
    /* The following functions are to switch between the ui pages */
    void stuProjListPage();
    void createProjectPage();
    void projectPage();
    void editProjectPage();
    void adminMainPage();
private:
    MainWindow *mainWindow;
    Storage *storage;
    //Student *stu;
    //Administrator *admin;
};

#endif // MAINWINDOW_H