#include "adminmainpage.h"
#include "ui_adminmainpage.h"

AdminMainPage::AdminMainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMainPage)//, projects(NULL)
{
    ui->setupUi(this);
    projects = new QList<Project*>();
    projId = -1;
    //projects = new QTableWidget(this);
    //connect(ui->projectsTable, );
}

AdminMainPage::~AdminMainPage()
{
    delete ui;
}

void AdminMainPage::tableItemClicked(int row , int column)
{
    //QTableWidgetItem *item = new QTableWidgetItem();
    //item = ui->projectsTable->item(row, column);
    // we need to get project ID from this item (project)

    projId = ((*(projects))[row])->getID();
    main->openProject(projId);

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

int AdminMainPage::getProjectId()
{
    return projId;
}

void AdminMainPage::setProjects(QList<Project*> *proj)
{
    projects = proj;
    int numOfPojects = projects->size();

    ui->projectsTable->setRowCount(numOfPojects);
    ui->projectsTable->setColumnCount(2);
    ui->projectsTable->setColumnWidth(0, 600);
    ui->projectsTable->setColumnWidth(1, 160);
    ui->projectsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->projectsTable->setHorizontalHeaderLabels(QString("Project Name;Status").split(";"));

    for(int i=0; i<numOfPojects; ++i)
    {
        Project *project = (*(projects))[i];
        QTableWidgetItem *projName = new QTableWidgetItem(project->getName());
        projName->setFlags(projName->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *projStatus = new QTableWidgetItem(project->getStatus());
        projStatus->setFlags(projStatus->flags() ^ Qt::ItemIsEditable);
        ui->projectsTable->setItem(i, 0, projName);
        ui->projectsTable->setItem(i, 1, projStatus);
        //change to 'cellClicked'
        connect(ui->projectsTable, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
    }
}
