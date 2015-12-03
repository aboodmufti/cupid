#include "ProfileSubsystem/profilemanager.h"

ProfileManager::ProfileManager()
{
    storage = new Storage();
    qDebug() << "In ProfileManager Constructor";
}

Storage* ProfileManager::getStorage()
{
    return storage;
}

MainWindow* ProfileManager::getMainWindow()
{
    return mainWindow;
}

void ProfileManager::editProfileSubmit(int newStu, StudentProfile* stuProfile){
    if(newStu == 1){
        storage->insertStudent(stuProfile);
    }else if(newStu == 0){
        storage->updateStudentProfile(stuProfile);
    }
    storage->setStudent(stuProfile);
    mainWindow->handleNewPage(STUDENT_PROFILE);
}

void ProfileManager::joinProject(int pid)
{
    storage->addStudentProject(pid, storage->getProfileID());
    mainWindow->handleNewPage(STUDENT_PROJECT_LIST);
}

void ProfileManager::checkStudentLogin(QString username)
{
    //stu = new Student();
    storage->createStudent();
    StudentProfile *stuProfile = storage->getStudentByUsername(username);
    if((stuProfile->getName()) == "unknown" ){
        storage->getStudent()->setUsername(username);
        storage->setStudentProfile(stuProfile);
        storage->getStudentProfile()->setUsername(username);

    }else{
        storage->getStudent()->setUsername(username);
        storage->setStudentProfile(stuProfile);
    }
    mainWindow->handleNewPage(STUDENT_PROFILE);
}

/*
void MainWindow::checkStudentLogin(QString userName){
    stu = new Student();
    StudentProfile *sP = storage->getStudentByUsername(userName);
    if((sP->getName()) == "unknown" ){
        stu->setUsername(userName);
        stu->setStudentProfile(sP);
        stu->getStudentProfile()->setUsername(userName);

    }else{
        stu->setUsername(userName);
        stu->setStudentProfile(sP);
    }
    handleNewPage(STUDENT_PROFILE);
}
*/

/*void ProfileManager::openProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    QList<StudentProfile*>* list = mainWindow->getStudentsInProject(pid);


    Project* project = storage->getProjectById(pid);
    QList<StudentProfile*>* list = getStudentsInProject(pid);
    ProjectPage *projectPage = new ProjectPage();

    projectPage->setProject(project,list);
    projectPage->setMain(this);
    this->setCentralWidget(projectPage);

}*/

bool ProfileManager::getStudentbyID(int sid)
{
    StudentProfile* stu = storage->getStudentProfile(sid);
    if(stu->getName() == "unknown"){
        return false;
    }
    return true;
}
