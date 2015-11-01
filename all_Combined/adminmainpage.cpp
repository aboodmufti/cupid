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
    qDebug() <<"DEBUG1 ";
    projId = ((*(projects))[row])->getID();
    qDebug() <<"DEBUG2 ";
    main->openProject(projId);
    qDebug() <<"DEBUG3 ";

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
            QColor * red = new QColor(204, 0, 0);
            projStatus->setTextColor(*red);
        }
        projStatus->setFlags(projStatus->flags() ^ Qt::ItemIsEditable);
        ui->projectsTable->setItem(i, 0, projName);
        ui->projectsTable->setItem(i, 1, projStatus);
        connect(ui->projectsTable, SIGNAL(cellClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
    }
}
