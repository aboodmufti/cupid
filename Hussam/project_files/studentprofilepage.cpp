#include "studentprofilepage.h"
#include "ui_studentprofilepage.h"

StudentProfilePage::StudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProfilePage)
{
    ui->setupUi(this);
}

StudentProfilePage::~StudentProfilePage()
{
    delete ui;
}

void StudentProfilePage::setMain(MainWindow* newMain){
    main = newMain;
}

void StudentProfilePage::on_pushButton_3_clicked()
{
    main->handleNewPage(WELCOME_PAGE);
}

void StudentProfilePage::on_projectsButton_clicked()
{
    main->handleNewPage(STUDENT_PROJECT_LIST);
}

void StudentProfilePage::on_pushButton_clicked()
{
    main->handleNewPage(EDIT_PROFILE);
}
