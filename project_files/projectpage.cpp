#include "projectpage.h"
#include "ui_projectpage.h"

ProjectPage::ProjectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectPage)
{
    ui->setupUi(this);
}

ProjectPage::~ProjectPage()
{
    delete ui;
}

void ProjectPage::setMain(MainWindow* newMain){
    main = newMain;
}

void ProjectPage::on_pushButton_clicked()
{
    main->handleNewPage(ADMIN_MAIN_PAGE);
}

void ProjectPage::on_pushButton_3_clicked()  //publish button
{
    main->handleNewPage(ADMIN_MAIN_PAGE);
}

void ProjectPage::on_pushButton_4_clicked()
{
     main->editProject(pid);
    //main->editProject(newID);
    //main->handleNewPage(PROJECT);
    //main->handleNewPage(EDIT_PROJECT);//openP function
}

void ProjectPage::setProject(Project* project)
{
    //Project* temProject = project;
    pid = project->getID();
    ui->projectNameLabel->setText(project->getName());
    ui->minTeamSize->setText(QString::number(project->getMinTeamSize()));
    //ui->minTeamSize->setNum(project->getMinTeamSize());
    //ui->maxTeamSize->setNum(project->getMaxTeamSize());
    ui->maxTeamSize->setText(QString::number(project->getMaxTeamSize()));
    ui->description->setText(project->getDescription());
    //ui->numOfStudents->setNum(project->);
}
