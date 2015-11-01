#include "studentprojectspage.h"
#include "ui_studentprojectspage.h"

StudentProjectsPage::StudentProjectsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProjectsPage)
{
    ui->setupUi(this);

    ui->projectsTable->setColumnCount(2);
    ui->projectsTable->setRowCount(5);
    //set columns width
    //set columns unresizeable
    //set header names
    //set cells uneditable
    //qsignalmapper
    /*for(int i=0;i<5;++i){
        QTableWidgetItem* name = new QTableWidgetItem();
        name->setText("Abood");
        ui->projectsTable->setItem(i,0,name);

        QTableWidgetItem* status = new QTableWidgetItem();
        status->setText("Joined");
        ui->projectsTable->setItem(i,1,status);
    }*/
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

void StudentProjectsPage::joinButtonClicked(int pid){
    main->joinProject(pid);
}

void StudentProjectsPage::setProjects(QList<QList<QString>*>* projects){
    QList<QList<QString>*> projects2 = *projects;

    ui->projectsTable->setColumnCount(2);
    ui->projectsTable->setRowCount(projects2.size());
    ui->projectsTable->setColumnWidth(0, 642);
    ui->projectsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->projectsTable->setHorizontalHeaderLabels(QString("Project Name;Status").split(";"));

    QSignalMapper* mapper = new QSignalMapper();
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(joinButtonClicked(int)));

    for(int i=0;i<projects2.size();++i){
        QTableWidgetItem* name = new QTableWidgetItem();
        name->setText((*(projects2[i]))[1]);\
        name->setFlags(name->flags() ^ Qt::ItemIsEditable);
        ui->projectsTable->setItem(i,0,name);

        QString joinStat = (*(projects2[i]))[2];
        if(joinStat == "Joined"){
            QTableWidgetItem* status = new QTableWidgetItem();
            status->setText(joinStat);
            status->setFlags(status->flags() ^ Qt::ItemIsEditable);
            ui->projectsTable->setItem(i,1,status);

        }else{
            QPushButton* joinButton = new QPushButton();
            joinButton->setText("Join");
            connect(joinButton, SIGNAL(clicked()), mapper, SLOT(map()));
            mapper->setMapping(joinButton,((*(projects2[i]))[0]).toInt() );
            ui->projectsTable->setCellWidget(i,1,joinButton);
        }

    }

}
