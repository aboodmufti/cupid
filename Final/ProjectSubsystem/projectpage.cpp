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

void ProjectPage::setManager(ProjectManager* pm){
    projectManager = pm;
}

void ProjectPage::on_pushButton_clicked()  // back button
{
    projectManager->adminMainPage();
}

void ProjectPage::on_pushButton_3_clicked()  // publish button
{
    projectManager->publishProject(pid);
    projectManager->viewProjects();
}

void ProjectPage::on_pushButton_4_clicked()  // edit button
{
     projectManager->editProject(pid);
}

void ProjectPage::tableItemClicked(int row , int column)
{
    sid = ((*(studentsInProjectList))[row])->getID();
    projectManager->displayStudentProfile(sid,pid);
}

void ProjectPage::setError(QString errorMessage){
    ui->errorLabel->setText(errorMessage);
}

void ProjectPage::setProject(Project* project,QList<StudentProfile*>* list)
{
    pid = project->getID();
    ui->projectNameLabel->setText(project->getName());
    ui->minTeamSize->setText(QString::number(project->getMinTeamSize()));
    ui->maxTeamSize->setText(QString::number(project->getMaxTeamSize()));
    ui->description->setText(project->getDescription());

    // Need to get Number of Students in a Project
    //ui->numOfStudents->setNum(project->);
    //studentsInProjectList = main->getStudentsInProject(pid);
    studentsInProjectList = list;
    int numOfStudentsInProject = studentsInProjectList->size();
    ui->numOfStudents->setNum(numOfStudentsInProject);
    ui->studentsInProjectTable->setRowCount(numOfStudentsInProject);
    ui->studentsInProjectTable->setColumnCount(2);
    ui->studentsInProjectTable->setColumnWidth(0, 600);
    //ui->studentsInProjectTable->setColumnWidth(1, 160);
    ui->studentsInProjectTable->horizontalHeader()->setStretchLastSection(true);
    ui->studentsInProjectTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->studentsInProjectTable->setHorizontalHeaderLabels(QString("Student Name;Student ID").split(";"));
    for(int i=0; i<numOfStudentsInProject; ++i)
    {
        StudentProfile *stuProfile = (*(studentsInProjectList))[i];
        QTableWidgetItem *studentName = new QTableWidgetItem(stuProfile->getName());
        QTableWidgetItem *studentId = new QTableWidgetItem(QString::number(stuProfile->getID()));
        ui->studentsInProjectTable->setItem(i, 0, studentName);
        ui->studentsInProjectTable->setItem(i, 1, studentId);

        connect(ui->studentsInProjectTable, SIGNAL(cellClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
    }
}

void ProjectPage::on_pushButton_2_clicked() //algorithm Button
{
    ui->errorLabel->setText("");
    int min = ui->minTeamSize->text().toInt();
    int max = ui->maxTeamSize->text().toInt();
    int total = ui->numOfStudents->text().toInt();
    if(total < min){
        ui->errorLabel->setText("The mininimum team size cannot be larger than the total number of students!");
    }else if(max > total){
        ui->errorLabel->setText("The maximum team size cannot be larger than the total number of students!");

    }else{
        projectManager->executeAlgorithm();
    }
}
