#include "projectmanager.h"

Storage* ProjectManager::getStorage()
{
  return storage;
}

MainWindow* ProjectManager::getMain()
{
  return mainWindow;
}
/*
void ProjectManager::stuProjListPage()
{
  StudentProjectsPage *stuProjList = new StudentProjectsPage();
  QList<QList<QString>*>* projects = storage->getStudentProjects(storage->getStudent()->getStudentProfile()->getID())  ;
  stuProjList->setProjects(projects);
  stuProjList->setManager(this);
  mainWindow->setCentralWidget(stuProjList);
}
*/
void ProjectManager::createProjectPage2()
{
  createProjectPage *createProject = new createProjectPage();
  //Project* project = createProject->getProject();
  //storage->insertProject(project); // returns bool, so we can display an error message later on
  createProject->setManager(this);
  mainWindow->setCentralWidget(createProject);
}

void ProjectManager::projectPage()
{
  ProjectPage *projectPage = new ProjectPage();
  // we need to get project ID from adminMainPage
  // when the admin has clicked on a specific project
  //AdminMainPage *adminMain = new AdminMainPage();
  //int projectId = adminMain->getProjectId();
  //Project* project = storage->getProjectById(projectId);
  //projectPage->setProject(project);
  projectPage->setManager(this);
  mainWindow->setCentralWidget(projectPage);
}

void ProjectManager::editProjectPage()
{
  EditProjectPage *editProjectPage = new EditProjectPage();
  Project *project = editProjectPage->getProject();
  storage->updateProject(project);  // returns bool
  editProjectPage->setManager(this);
  mainWindow->setCentralWidget(editProjectPage);
}

void ProjectManager::adminMainPage()
{
  AdminMainPage *adminMain = new AdminMainPage();
  QList<Project*>* projects = storage->getAllProjects();
  adminMain->setProjects(projects);
  adminMain->setManager(this);
  mainWindow->setCentralWidget(adminMain);
}

void ProjectManager::joinProject(int pid){

    storage->addStudentProject(pid, storage->getStudent()->getStudentProfile()->getID());
    //handleNewPage(STUDENT_PROJECT_LIST);
    //stuProjListPage();
}

int ProjectManager::createProject(Project* proj)
{
    return storage->insertProject(proj);
}

void ProjectManager::openProject(int pid, int err)
{

    project = storage->getProjectById(pid);
    studentsInProject = storage->getStudentsInProject2(pid) ;//getStudentsInProject(pid)
    ProjectPage *projectPage = new ProjectPage();

    projectPage->setProject(project,studentsInProject);
    projectPage->setManager(this);
    if(err == 0 ){
        projectPage->setError("Can't form teams with the given minimum and maximum team size");
    }
    mainWindow->setCentralWidget(projectPage);
}

void ProjectManager::editProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    EditProjectPage *editProjectPage = new EditProjectPage();

    editProjectPage->setProject(project);
    editProjectPage->setManager(this);
    mainWindow->setCentralWidget(editProjectPage);
}

void ProjectManager::updateProject(Project* proj)
{
    storage->updateProject(proj);
}

void ProjectManager::publishProject(int pid)
{
    AdminMainPage *adminMainPage = new AdminMainPage();
    storage->publishProject(pid);
    adminMainPage->setManager(this);
    mainWindow->setCentralWidget(adminMainPage);
}

void ProjectManager::viewProjects()
{
    AdminMainPage *adminMain = new AdminMainPage();
    QList<Project*>* projects = storage->getAllProjects();
    adminMain->setProjects(projects);
    adminMain->setManager(this);
    mainWindow->setCentralWidget(adminMain);
}

void ProjectManager::displayStudentProfile(int sid,int pid)
{
    StudentProfile *stuProfile = storage->getStudentProfile(sid);
    AdminStudentProfilePage *studentProfilePage = new AdminStudentProfilePage();

    studentProfilePage->setStudentProfile(stuProfile,pid);
    studentProfilePage->setManager(this);
    mainWindow->setCentralWidget(studentProfilePage);
}

void ProjectManager::setMainStorage(MainWindow* main,Storage* storage){
    this->mainWindow = main;
    this->storage = storage;
}

void ProjectManager::executeAlgorithm(){
    storage->executeAlgorithm(project,studentsInProject, mainWindow);
}


void ProjectManager::checkAdminLogin(QString userName)
{
    Administrator* admin = new Administrator();
    admin = storage->getAdminByUsername(userName);
    if(admin->getUsername() == "unknown" ){
        admin->setUsername(userName);
        storage->insertAdministrator(admin);
        storage->setAdministrator(admin);
    }else{
        admin->setUsername(userName);
        storage->setAdministrator(admin);
    }
    //handleNewPage(ADMIN_MAIN_PAGE);
    adminMainPage();
}


void ProjectManager::goToAdminLoginPage(){
    AdminLoginPage *adminLoginPage = new AdminLoginPage();
    adminLoginPage->setManager(this);
    mainWindow->setCentralWidget(adminLoginPage);
}
