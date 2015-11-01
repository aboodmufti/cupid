#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storage = new Storage();
    qDebug() << storage->setUpAdministratorTable();
    qDebug() << storage->setUpAdminProjectTable();
    qDebug() << storage->setUpProjectStudentTable();
    qDebug() << storage->setUpProjectTable();
    qDebug() << storage->setUpQualificationsTable();
    qDebug() << storage->setUpStudentTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize(){
    this->handleNewPage(WELCOME_PAGE);
}
void MainWindow::handleNewPage(View view){

    switch (view)
    {
        case WELCOME_PAGE:
        {
            WelcomePage *newPage1 = new WelcomePage();
            newPage1->setMain(this);
            this->setCentralWidget(newPage1);
        }
            break;
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
            newPage4->setMain(this);
            this->setCentralWidget(newPage4);
        }
            break;
        case EDIT_PROFILE:
        {
          EditProfilePage *newPage5 = new EditProfilePage();
          newPage5->setMain(this);
          this->setCentralWidget(newPage5);
        }
          break;
        case STUDENT_PROJECT_LIST:
        {
          StudentProjectsPage *newPage6 = new StudentProjectsPage();
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

void MainWindow::displayStudentProfile(int pid)
{
    StudentProfile *stuProfile = storage->getStudentProfile(pid);
    StudentProfilePage *studentProfilePage = new StudentProfilePage();

    studentProfilePage->setStudentProfile(stuProfile);
    studentProfilePage->setMain(this);
    this->centralWidget(studentProfilePage);
}

int MainWindow::createProject(Project* proj)
{
    return storage->insertProject(proj);
}

void MainWindow::openProject(int pid)
{
    Project* project = storage->getProjectById(pid);
    ProjectPage *projectPage = new ProjectPage();

    projectPage->setProject(project);
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

// added hussam
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
    }else{
    stu->setUsername(userName);
    stu->setStudentProfile(sP);
    }
    handleNewPage(STUDENT_PROFILE);
}

