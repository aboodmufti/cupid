#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include "StorageSubsystem/storage.h"
#include "ProfileSubsystem/studentloginpage.h"
#include "ProfileSubsystem/studentprofilepage.h"
#include "ProfileSubsystem/editprofilepage.h"
#include "ProfileSubsystem/studentprojectspage.h"
//#include "ProfileSubsystem/welcomepage.h"
#include "mainwindow.h"
class Storage;

class ProfileManager
{
public:
    ProfileManager();
    Storage* getStorage();
    MainWindow* getMainWindow();

    void setStudentLoginPage();
    void setStudentProfilePage();
    void setEditProfilePage();
    void setStudentProjectsPage();

    void editProfileSubmit(int, StudentProfile*);
    void joinProject(int pid);
    void checkStudentLogin(QString);
    void openProject(int);
    bool getStudentbyID(int);
    void setMainStorage(MainWindow* main,Storage* storage);

    void setStuProfileInStorage(StudentProfile* stu);

private:
    Storage *storage;
    MainWindow *mainWindow;
};

#endif // PROFILEMANAGER_H
