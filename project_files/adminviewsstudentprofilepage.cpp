#include "adminviewsstudentprofilepage.h"
#include "ui_adminviewsstudentprofilepage.h"

AdminViewsStudentProfilePage::AdminViewsStudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminViewsStudentProfilePage)
{
    ui->setupUi(this);
}

AdminViewsStudentProfilePage::~AdminViewsStudentProfilePage()
{
    delete ui;
}
