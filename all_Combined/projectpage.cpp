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

void ProjectPage::on_pushButton_clicked()  // back button
{
    main->handleNewPage(ADMIN_MAIN_PAGE);
}

void ProjectPage::on_pushButton_3_clicked()  // publish button
{
    main->publishProject(pid);
    main->viewProjects();
}

void ProjectPage::on_pushButton_4_clicked()  // edit button
{
     main->editProject(pid);
}

void ProjectPage::setProject(Project* project)
{
    pid = project->getID();
    ui->projectNameLabel->setText(project->getName());
    ui->minTeamSize->setText(QString::number(project->getMinTeamSize()));
    ui->maxTeamSize->setText(QString::number(project->getMaxTeamSize()));
    ui->description->setText(project->getDescription());

    // Need to get Number of Students in a Project
    //ui->numOfStudents->setNum(project->);
}
