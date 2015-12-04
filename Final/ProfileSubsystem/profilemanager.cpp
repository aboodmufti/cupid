#include "ProfileSubsystem/profilemanager.h"

ProfileManager::ProfileManager()
{
    //storage = new Storage();
}

Storage* ProfileManager::getStorage()
{
    return storage;
}

MainWindow* ProfileManager::getMainWindow()
{
    return mainWindow;
}

void ProfileManager::setStudentLoginPage()
{
    StudentLoginPage *studentLoginPage = new StudentLoginPage();
    studentLoginPage->setManager(this);
    mainWindow->setCentralWidget(studentLoginPage);
}

void ProfileManager::setStudentProfilePage()
{
    StudentProfilePage *studentProfilePage = new StudentProfilePage();
    //StudentProfile* stuProfile = storage->getStudentByUsername(student->getUsername());
    //student->setStudentProfile(stuProfile);  //if coming from editProfile
    StudentProfile* stuPro = storage->getOwnProfile();
    studentProfilePage->setStudentProfile(stuPro);
    studentProfilePage->setManager(this);
    mainWindow->setCentralWidget(studentProfilePage);
}

void ProfileManager::setEditProfilePage()
{
    EditProfilePage *editProfilePage = new EditProfilePage();
    editProfilePage->setStudentProfile(getStorage()->getOwnProfile());
    editProfilePage->setManager(this);
    mainWindow->setCentralWidget(editProfilePage);
}

void ProfileManager::setStudentProjectsPage()
{
    StudentProjectsPage *studentProjectsPage = new StudentProjectsPage();
    QList<QList<QString>*>* projects = storage->getStudentProjects(getStorage()->getOwnProfile()->getID());
    studentProjectsPage->setProjects(projects);
    studentProjectsPage->setManager(this);
    mainWindow->setCentralWidget(studentProjectsPage);
}

void ProfileManager::editProfileSubmit(int newStu, StudentProfile* stuProfile){
    if(newStu == 1){
        storage->insertStudent(stuProfile);
    }else if(newStu == 0){
        storage->updateStudentProfile(stuProfile);
    }
    //storage->setStudent(stuProfile);
    //storage->setStudentProfile();
    storage->setOwnProfile(stuProfile);
    //mainWindow->handleNewPage(STUDENT_PROFILE);
    setStudentProfilePage();
}

void ProfileManager::joinProject(int pid)
{
    storage->addStudentProject(pid, storage->getOwnProfile()->getID());
    //mainWindow->handleNewPage(STUDENT_PROJECT_LIST);
    setStudentProjectsPage();
}

void ProfileManager::checkStudentLogin(QString username)
{
    //stu = new Student();
    storage->createStudent();
    StudentProfile *stuProfile = storage->getStudentByUsername(username);
    if((stuProfile->getName()) == "unknown" ){
        storage->getStudent()->setUsername(username);
        storage->setOwnProfile(stuProfile);
        //storage->setStudentProfile(stuProfile);
        //storage->getStudentProfile()->setUsername(username);
        storage->getOwnProfile()->setUsername(username);

    }else{
        storage->getStudent()->setUsername(username);
        storage->setOwnProfile(stuProfile);
        //storage->setStudentProfile(stuProfile);
    }
    //mainWindow->handleNewPage(STUDENT_PROFILE);
    setStudentProfilePage();
}

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


void ProfileManager::setMainStorage(MainWindow* main,Storage* storage){
    this->mainWindow = main;
    this->storage = storage;
}

void ProfileManager::setStuProfileInStorage(StudentProfile* stu){
    storage->setStudentProfile(stu);
}
