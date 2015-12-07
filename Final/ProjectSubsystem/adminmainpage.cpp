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

    projectManager->openProject(projId,1);


}

void AdminMainPage::setManager(ProjectManager* pm){
    projectManager = pm;
}

void AdminMainPage::on_createButton_2_clicked()
{
    projectManager->createProjectPage2();
}

void AdminMainPage::on_logoutButton_2_clicked()
{
    projectManager->getMain()->initialize();
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
    ui->projectsTable->horizontalHeader()->setStretchLastSection(true);
    //ui->projectsTable->setColumnWidth(1, 160);
    ui->projectsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->projectsTable->setHorizontalHeaderLabels(QString("Project Name;Status").split(";"));

    for(int i=0; i<numOfPojects; ++i)
    {
        Project *project = (*(projects))[i];//check if status has changed
        QTableWidgetItem *projName = new QTableWidgetItem(project->getName());
        projName->setFlags(projName->flags() ^ Qt::ItemIsEditable);
        QString stat = project->getStatus();
        QTableWidgetItem *projStatus = new QTableWidgetItem(stat);
        if(stat == "PUBLISHED"){
            QColor * green = new QColor(84, 167, 0);
            projStatus->setTextColor(*green);
        }else{
            projStatus = new QTableWidgetItem("NOT PUBLISHED");
            QColor * red = new QColor(204, 0, 0);
            projStatus->setTextColor(*red);
        }
        projStatus->setFlags(projStatus->flags() ^ Qt::ItemIsEditable);
        ui->projectsTable->setItem(i, 0, projName);
        ui->projectsTable->setItem(i, 1, projStatus);
        connect(ui->projectsTable, SIGNAL(cellClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
    }
}
