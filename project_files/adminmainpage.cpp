#include "adminmainpage.h"
#include "ui_adminmainpage.h"

AdminMainPage::AdminMainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMainPage)
{
    ui->setupUi(this);
    projects = new QList<Project*>();
}

AdminMainPage::~AdminMainPage()
{
    delete ui;
}


void AdminMainPage::setMain(MainWindow* newMain){
    main = newMain;
}

void AdminMainPage::on_createButton_2_clicked()
{
    main->handleNewPage(CREATE_PROJECT);
}

void AdminMainPage::on_logoutButton_2_clicked()
{
    main->handleNewPage(WELCOME_PAGE);
}

void AdminMainPage::setProjects(QList<Project*> *proj)
{
    projects = proj;
    int numOfPojects = projects->size();

    ui->projectsTable->setRowCount(numOfPojects);
    ui->projectsTable->setColumnCount(2);

    for(int i=0; i<numOfPojects; ++i)
    {
        Project *project = (*(projects))[i];
        ui->projectsTable->setItem(i, 0, new QTableWidgetItem(project->getName()));
        ui->projectsTable->setItem(i, 1, new QTableWidgetItem(project->getStatus()));
    }
}
