#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storage = new Storage();
    storage->setUpAdministratorTable();
    storage->setUpAdminProjectTable();
    storage->setUpProjectStudentTable();
    storage->setUpProjectTable();
    storage->setUpQualificationsTable();
    storage->setUpStudentTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::welcomePage()
{
  WelcomePage *welcomePage = new WelcomePage();
  welcomePage->setMain(this);
  this->setCentralWidget(welcomePage);
}

void MainWindow::initialize(){
    this->handleNewPage(WELCOME_PAGE);
}
void MainWindow::handleNewPage(View view){

    switch (view)
    {
        case STUDENT_LOGIN:
        {
            StudentLoginPage *studentLoginPage = new StudentLoginPage();
            /*stu = new Student();
            StudentProfile *sP = storage->getStudentByUsername(newPage2->getUsername());
            if((sP->getName()) == "unknown" ){
                stu->setUsername(newPage2->getUsername());
                stu->setStudentProfile(sP);
                storage->insertStudent(sP);
            }*/
            studentLoginPage->setMain(this);
            this->setCentralWidget(studentLoginPage);
        }
            break;
        case ADMIN_LOGIN:
        {
            AdminLoginPage *adminLoginPage = new AdminLoginPage();
            /*admin = new Administrator();
            admin = storage->getAdminByUsername(newPage3->getUsername());
            if(admin == 0){
                admin->setUsername(newPage3->getUsername());
                storage->insertAdministrator(admin);
            }*/
            adminLoginPage->setMain(this);
            this->setCentralWidget(adminLoginPage);
        }
        break;
        case STUDENT_PROFILE:
        {
            StudentProfilePage *newPage4 = new StudentProfilePage();
            //StudentProfile* stuProfile = storage->getStudentByUsername(student->getUsername());
            //student->setStudentProfile(stuProfile);  //if coming from editProfile
            newPage4->setStudentProfile(stu->getStudentProfile());
            newPage4->setMain(this);
            this->setCentralWidget(newPage4);
        }
            break;
        case EDIT_PROFILE:
        {
          EditProfilePage *newPage5 = new EditProfilePage();
          newPage5->setStudentProfile(stu->getStudentProfile());
          newPage5->setMain(this);
          this->setCentralWidget(newPage5);
        }
          break;
        case STUDENT_PROJECT_LIST:
        {
          StudentProjectsPage *newPage6 = new StudentProjectsPage();
          QList<QList<QString>*>* projects = storage->getStudentProjects(stu->getStudentProfile()->getID())  ;
          newPage6->setProjects(projects);
          newPage6->setMain(this);
          this->setCentralWidget(newPage6);
        }
          break;
        case ADMIN_MAIN_PAGE:
        {
          AdminMainPage *adminMain = new AdminMainPage();
          QList<Project*>* projects = storage->getAllProjects();
          adminMain->setProjects(projects);
          adminMain->setMain(this);
          this->setCentralWidget(adminMain);
        }
          break;
        case CREATE_PROJECT:
        {
          createProjectPage *createProject = new createProjectPage();
          //Project* project = createProject->getProject();
          //storage->insertProject(project); // returns bool, so we can display an error message later on
          createProject->setMain(this);
          this->setCentralWidget(createProject);
        }
          break;
        case PROJECT:
        {
          ProjectPage *projectPage = new ProjectPage();
          // we need to get project ID from adminMainPage
          // when the admin has clicked on a specific project
          //AdminMainPage *adminMain = new AdminMainPage();
          //int projectId = adminMain->getProjectId();
          //Project* project = storage->getProjectById(projectId);
          //projectPage->setProject(project);

          projectPage->setMain(this);
          this->setCentralWidget(projectPage);
        }
          break;
        case EDIT_PROJECT:
        {
          EditProjectPage *editProjectPage = new EditProjectPage();
          Project *project = editProjectPage->getProject();
          storage->updateProject(project);  // returns bool
          editProjectPage->setMain(this);
          this->setCentralWidget(editProjectPage);
        }
          break;
        default:
          break;
    }

}

//Abood's
bool MainWindow::getStudentbyID(int sid){
    StudentProfile* stu = storage->getStudentProfile(sid);
    if(stu->getName() == "unknown"){
        return false;
    }
    return true;

}

void MainWindow::editProfileSubmit(int newStu, StudentProfile* stuProfile){

    if(newStu == 1){
        storage->insertStudent(stuProfile);
    }else if(newStu == 0){
        storage->updateStudentProfile(stuProfile);
    }
    stu->setStudentProfile(stuProfile);
    handleNewPage(STUDENT_PROFILE);

}

void MainWindow::joinProject(int pid){

    storage->addStudentProject(pid, stu->getStudentProfile()->getID());
    handleNewPage(STUDENT_PROJECT_LIST);
}


//Dania's
QList<StudentProfile*>* MainWindow::getStudentsInProject(int pid){

    QList<StudentProfile*>* list = storage->getStudentsInProject2(pid);
    return list;

}

void MainWindow::displayStudentProfile(int sid,int pid)
{
    StudentProfile *stuProfile = storage->getStudentProfile(sid);
    AdminStudentProfilePage *studentProfilePage = new AdminStudentProfilePage();

    studentProfilePage->setStudentProfile(stuProfile,pid);
    studentProfilePage->setMain(this);
    this->setCentralWidget(studentProfilePage);
}

int MainWindow::createProject(Project* proj)
{
    return storage->insertProject(proj);
}

void MainWindow::openProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    QList<StudentProfile*>* list = getStudentsInProject(pid);
    ProjectPage *projectPage = new ProjectPage();

    projectPage->setProject(project,list);
    projectPage->setMain(this);
    this->setCentralWidget(projectPage);
}

void MainWindow::editProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    EditProjectPage *editProjectPage = new EditProjectPage();

    editProjectPage->setProject(project);
    editProjectPage->setMain(this);
    this->setCentralWidget(editProjectPage);
}

void MainWindow::updateProject(Project* proj)
{
    storage->updateProject(proj);
}

void MainWindow::publishProject(int pid)
{
    AdminMainPage *adminMainPage = new AdminMainPage();
    storage->publishProject(pid);
    adminMainPage->setMain(this);
    this->setCentralWidget(adminMainPage);
}

void MainWindow::viewProjects()
{
    AdminMainPage *adminMain = new AdminMainPage();
    QList<Project*>* projects = storage->getAllProjects();
    adminMain->setProjects(projects);
    adminMain->setMain(this);
    this->setCentralWidget(adminMain);
}

// Hussam's
void MainWindow::checkAdminLogin(QString userName)
{
    admin = new Administrator();
    admin = storage->getAdminByUsername(userName);
    if(admin->getUsername() == "unknown" ){
        admin->setUsername(userName);
        storage->insertAdministrator(admin);
    }else{
    admin->setUsername(userName);
    }
    handleNewPage(ADMIN_MAIN_PAGE);
}

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
