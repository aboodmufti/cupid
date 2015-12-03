#include "projectmanager.h"

Storage* ProjectManager::getStorage()
{
  return storage;
}

MainWindow* ProjectManager::getMain()
{
  return mainWindow;
}

void ProjectManager::stuProjListPage()
{
  StudentProjectsPage *stuProjList = new StudentProjectsPage();
  QList<QList<QString>*>* projects = storage->getStudentProjects(storage->getStudent()->getStudentProfile()->getID())  ;
  stuProjList->setProjects(projects);
  stuProjList->setManager(this);
  mainWindow->setCentralWidget(stuProjList);
}

void ProjectManager::createProjectPage()
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
    handleNewPage(STUDENT_PROJECT_LIST);
}

int ProjectManager::createProject(Project* proj)
{
    return storage->insertProject(proj);
}

void ProjectManager::openProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    QList<StudentProfile*>* list = getStudentsInProject(pid);
    ProjectPage *projectPage = new ProjectPage();

    projectPage->setProject(project,list);
    projectPage->setMain(this);
    mainWindow->setCentralWidget(projectPage);
}

void ProjectManager::editProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    EditProjectPage *editProjectPage = new EditProjectPage();

    editProjectPage->setProject(project);
    editProjectPage->setMain(this);
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
    adminMainPage->setMain(this);
    mainWindow->setCentralWidget(adminMainPage);
}

void ProjectManager::viewProjects()
{
    AdminMainPage *adminMain = new AdminMainPage();
    QList<Project*>* projects = storage->getAllProjects();
    adminMain->setProjects(projects);
    adminMain->setMain(this);
    mainWindow->setCentralWidget(adminMain);
}

void ProjectManager::displayStudentProfile(int sid,int pid)
{
    StudentProfile *stuProfile = storage->getStudentProfile(sid);
    AdminStudentProfilePage *studentProfilePage = new AdminStudentProfilePage();

    studentProfilePage->setStudentProfile(stuProfile,pid);
    studentProfilePage->setMain(this);
    mainWindow->setCentralWidget(studentProfilePage);
}
