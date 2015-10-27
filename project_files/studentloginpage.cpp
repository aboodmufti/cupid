#include "studentloginpage.h"
#include "ui_studentloginpage.h"

StudentLoginPage::StudentLoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentLoginPage)
{
    ui->setupUi(this);
}

StudentLoginPage::~StudentLoginPage()
{
    delete ui;
}
