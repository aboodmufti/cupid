#include "projectpage.h"
#include "ui_projectpage.h"

ProjectPage::ProjectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectPage)
{
    ui->setupUi(this);
    studentsInProjectList = new QList<StudentProfile*>();
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

void ProjectPage::tableItemClicked(int row , int column)
{
    sid = ((*(studentsInProjectList))[row])->getID();
    main->displayStudentProfile(sid,pid);
}

void ProjectPage::setProject(Project* project,QList<StudentProfile*>* list)
{
    pid = project->getID();
    qDebug()<< "proj id :" << pid;
    ui->projectNameLabel->setText(project->getName());
    ui->minTeamSize->setText(QString::number(project->getMinTeamSize()));
    ui->maxTeamSize->setText(QString::number(project->getMaxTeamSize()));
    ui->description->setText(project->getDescription());

    // Need to get Number of Students in a Project
    //ui->numOfStudents->setNum(project->);
    qDebug() <<"DEBUG9 ";
    //studentsInProjectList = main->getStudentsInProject(pid);
    studentsInProjectList = list;
    qDebug() <<"DEBUG10 ";
    int numOfStudentsInProject = studentsInProjectList->size();
    ui->numOfStudents->setNum(numOfStudentsInProject);
    qDebug() <<"DEBUG11 ";
    ui->studentsInProjectTable->setRowCount(numOfStudentsInProject);
    ui->studentsInProjectTable->setColumnCount(2);
    ui->studentsInProjectTable->setColumnWidth(0, 600);
    ui->studentsInProjectTable->setColumnWidth(1, 160);
    ui->studentsInProjectTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->studentsInProjectTable->setHorizontalHeaderLabels(QString("Student Name;Student ID").split(";"));
    qDebug() <<"DEBUG12 ";
    for(int i=0; i<numOfStudentsInProject; ++i)
    {
        StudentProfile *stuProfile = (*(studentsInProjectList))[i];
        QTableWidgetItem *studentName = new QTableWidgetItem(stuProfile->getName());
        QTableWidgetItem *studentId = new QTableWidgetItem(QString::number(stuProfile->getID()));
        qDebug() <<"Stu id:" << stuProfile->getID();
        ui->studentsInProjectTable->setItem(i, 0, studentName);
        ui->studentsInProjectTable->setItem(i, 1, studentId);

        connect(ui->studentsInProjectTable, SIGNAL(cellClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
    }
    qDebug() <<"DEBUG13 ";
}
