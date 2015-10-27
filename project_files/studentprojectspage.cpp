#include "studentprojectspage.h"
#include "ui_studentprojectspage.h"

StudentProjectsPage::StudentProjectsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProjectsPage)
{
    ui->setupUi(this);
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
