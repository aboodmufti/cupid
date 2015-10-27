#include "adminmainpage.h"
#include "ui_adminmainpage.h"

AdminMainPage::AdminMainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminMainPage)
{
    ui->setupUi(this);
}

AdminMainPage::~AdminMainPage()
{
    delete ui;
}
