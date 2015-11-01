#include "adminstudentprofilepage.h"
#include "ui_adminstudentprofilepage.h"

AdminStudentProfilePage::AdminStudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminStudentProfilePage)
{
    ui->setupUi(this);
}

AdminStudentProfilePage::~AdminStudentProfilePage()
{
    delete ui;
}

void AdminStudentProfilePage::on_backButton_clicked()
{
    main->handleNewPage(PROJECT);
}
