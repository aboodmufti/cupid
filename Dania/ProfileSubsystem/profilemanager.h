#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include "StorageSubsystem/storage.h"
#include "mainwindow.h"

class ProfileManager
{
public:
    ProfileManager();
    Storage* getStorage();
    MainWindow* getMainWindow();

    void editProfileSubmit(int, StudentProfile*);
    void joinProject(int pid);
    void checkStudentLogin(QString);
    void openProject(int);
    bool getStudentbyID(int);

private:
    Storage *storage;
    MainWindow *mainWindow;
};

#endif // PROFILEMANAGER_H
