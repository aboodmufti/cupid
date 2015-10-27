#include "adminloginpage.h"
#include "ui_adminloginpage.h"

AdminLoginPage::AdminLoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminLoginPage)
{
    ui->setupUi(this);
}

AdminLoginPage::~AdminLoginPage()
{
    delete ui;
}
