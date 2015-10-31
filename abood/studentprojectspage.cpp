#include "studentprojectspage.h"
#include "ui_studentprojectspage.h"

StudentProjectsPage::StudentProjectsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProjectsPage)
{
    ui->setupUi(this);

    ui->projectsTable->setColumnCount(2);
    ui->projectsTable->setRowCount(5);

    for(int i=0;i<5;++i){
        QTableWidgetItem* name = new QTableWidgetItem();
        name->setText("Abood");
        name->
        ui->projectsTable->setItem(i,0,name);

        QTableWidgetItem* status = new QTableWidgetItem();
        status->setText("Joined");
        ui->projectsTable->setItem(i,1,status);
    }
}

StudentProjectsPage::~StudentProjectsPage()
{
    delete ui;
}

void StudentProjectsPage::setMain(MainWindow* newMain){
    main = newMain;
}

void StudentProjectsPage::on_pushButton_clicked()
{
    main->handleNewPage(STUDENT_PROFILE);
}


void StudentProjectsPage::setProjects(QList<QList<QString>*>* projects){
    QList<QList<QString>*> projects2 = *projects;

    ui->projectsTable->setColumnCount(2);
    ui->projectsTable->setRowCount(projects2.size());

    for(int i=0;i<projects2.size();++i){
        QTableWidgetItem* name = new QTableWidgetItem();
        name->setText((*(projects2[i]))[1]);
        ui->projectsTable->setItem(i,0,name);

        QTableWidgetItem* status = new QTableWidgetItem();
        status->setText((*(projects2[i]))[2]);
        ui->projectsTable->setItem(i,1,status);
    }

}
