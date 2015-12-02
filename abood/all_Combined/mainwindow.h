#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "adminloginpage.h"
#include "adminmainpage.h"
#include "createprojectpage.h"
#include "editprofilepage.h"
#include "projectpage.h"
#include "editprojectpage.h"
#include "studentloginpage.h"
#include "studentprofilepage.h"
#include "studentprojectspage.h"
#include "welcomepage.h"
#include "adminstudentprofilepage.h"

#include "database/storage.h"
/* control class for the whole program */
namespace Ui {
class MainWindow;
}

enum View{WELCOME_PAGE, STUDENT_LOGIN, ADMIN_LOGIN,
           STUDENT_PROFILE, EDIT_PROFILE, STUDENT_PROJECT_LIST,
           ADMIN_MAIN_PAGE, CREATE_PROJECT, PROJECT, EDIT_PROJECT};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void handleNewPage(View view);
    void initialize();
    void editProfileSubmit(int newStu, StudentProfile* stuProfile);
    void joinProject(int pid);
    void checkAdminLogin(QString);
    void checkStudentLogin(QString);
    int  createProject(Project*);
    void openProject(int);
    void editProject(int);
    void updateProject(Project*);
    void publishProject(int);
    void viewProjects();
    void displayStudentProfile(int sid, int pid);
    QList<StudentProfile*>* getStudentsInProject(int pid);
    bool getStudentbyID(int);

private:
    Ui::MainWindow *ui;
    Storage *storage;
    Student *stu;
    Administrator *admin;
};

#endif // MAINWINDOW_H
