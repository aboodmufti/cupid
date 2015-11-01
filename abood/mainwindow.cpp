#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storage = new Storage();
    qDebug() << "adminTable " << storage->setUpAdministratorTable();
    qDebug() << "adminProjectTable " << storage->setUpAdminProjectTable();
    qDebug() << "ProjectStudentTable " << storage->setUpProjectStudentTable();
    qDebug() << "projectTable " << storage->setUpProjectTable();
    qDebug() << "Q table " << storage->setUpQualificationsTable();
    qDebug() << "student table " << storage->setUpStudentTable();
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
            StudentLoginPage *newPage2 = new StudentLoginPage();
            newPage2->setMain(this);
            this->setCentralWidget(newPage2);
        }
            break;
        case ADMIN_LOGIN:
        {
            AdminLoginPage *newPage3 = new AdminLoginPage();
            newPage3->setMain(this);
            this->setCentralWidget(newPage3);
        }
            break;
        case STUDENT_PROFILE:
        {
            StudentProfilePage *newPage4 = new StudentProfilePage();
            //StudentProfile* stuProfile = storage->getStudentByUsername(student->getUsername());
            //student->setStudentProfile(stuProfile);  //if coming from editProfile
            newPage4->setStudentProfile(student->getStudentProfile());
            newPage4->setMain(this);
            this->setCentralWidget(newPage4);
        }
            break;
        case EDIT_PROFILE:
        {
          EditProfilePage *newPage5 = new EditProfilePage();
          newPage5->setStudentProfile(student->getStudentProfile());
          newPage5->setMain(this);
          this->setCentralWidget(newPage5);
        }
          break;
        case STUDENT_PROJECT_LIST:
        {
          StudentProjectsPage *newPage6 = new StudentProjectsPage();
          QList<QList<QString>*>* projects = storage->getStudentProjects(student->getStudentProfile()->getID())  ;
          newPage6->setProjects(projects);
          newPage6->setMain(this);
          this->setCentralWidget(newPage6);
        }
          break;
        case ADMIN_MAIN_PAGE:
        {
          AdminMainPage *newPage7 = new AdminMainPage();
          newPage7->setMain(this);
          this->setCentralWidget(newPage7);
        }
          break;
        case CREATE_PROJECT:
        {
          createProjectPage *newPage8 = new createProjectPage();
          newPage8->setMain(this);
          this->setCentralWidget(newPage8);
        }
          break;
        case PROJECT:
        {
          ProjectPage *newPage9 = new ProjectPage();
          newPage9->setMain(this);
          this->setCentralWidget(newPage9);
        }
          break;
        case EDIT_PROJECT:
        {
          EditProjectPage *newPage10 = new EditProjectPage();
          newPage10->setMain(this);
          this->setCentralWidget(newPage10);
        }
          break;
        default:
          break;
    }

}


void MainWindow::editProfileSubmit(int newStu, StudentProfile* stuProfile){

    if(newStu == 1){
        storage->insertStudent(stuProfile);
    }else if(newStu == 0){
        storage->updateStudentProfile(stuProfile);
    }
    student->setStudentProfile(stuProfile);
    handleNewPage(STUDENT_PROFILE);

}

void MainWindow::joinProject(int pid){
    storage->studentJoinedProject(pid, student->getStudentProfile()->getID());
    handleNewPage(STUDENT_PROJECT_LIST);
}
