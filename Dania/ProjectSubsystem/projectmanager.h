#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QMainWindow>


#include "createprojectpage.h"
#include "projectpage.h"
#include "editprojectpage.h"
//#include "studentprojectspage.h"
#include "mainwindow.h"
#include "adminloginpage.h"
#include "StorageSubsystem/storage.h"
#include "adminmainpage.h"
#include "StorageSubsystem/Project.h"
#include "adminstudentprofilepage.h"
/* control class for the project subsystem */

//namespace Ui {
//class ProjectManager;
//}

class Storage;

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
    void createProjectPage2();
    void projectPage();
    void editProjectPage();
    void adminMainPage();
    void setMainStorage(MainWindow* main,Storage* storage);
    void executeAlgorithm();
    void checkAdminLogin(QString);
    void goToAdminLoginPage();

private:
    MainWindow *mainWindow;
    Storage *storage;
    //Student *stu;
    //Administrator *admin;
    Project* project;
    QList<StudentProfile*>* studentsInProject;
};

#endif // MAINWINDOW_H
