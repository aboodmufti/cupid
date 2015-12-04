#include "ProfileSubsystem/studentprojectspage.h"
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
    manager->getMainWindow() = newMain;
}

void StudentProjectsPage::setManager(ProfileManager* mngr)
{
    manager = mngr;
}

void StudentProjectsPage::on_pushButton_clicked()
{
    //manager->getMainWindow()->handleNewPage(STUDENT_PROFILE);
    manager->setStudentProfilePage();
}

void StudentProjectsPage::joinButtonClicked(int pid){
    manager->joinProject(pid);
}

void StudentProjectsPage::setProjects(QList<QList<QString>*>* projects){
    QList<QList<QString>*> projects2 = *projects;

    ui->projectsTable->setColumnCount(2);
    ui->projectsTable->setRowCount(projects2.size());
    ui->projectsTable->setColumnWidth(0, 642);
    ui->projectsTable->horizontalHeader()->setStretchLastSection(true);
    ui->projectsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->projectsTable->setHorizontalHeaderLabels(QString("Project Name;Status").split(";"));

    QSignalMapper* mapper = new QSignalMapper();
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(joinButtonClicked(int)));

    for(int i=0;i<projects2.size();++i){
        QTableWidgetItem* name = new QTableWidgetItem();
        name->setText((*(projects2[i]))[1]);
        name->setFlags(name->flags() ^ Qt::ItemIsEditable);
        ui->projectsTable->setItem(i,0,name);

        QString joinStat = (*(projects2[i]))[2];
        if(joinStat == "TRUE"){
            QTableWidgetItem* status = new QTableWidgetItem();
            status->setText("Joined");
            QColor * green = new QColor(84, 167, 0);
            status->setTextColor(*green);
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
