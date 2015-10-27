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


void AdminMainPage::setMain(MainWindow* newMain){
    main = newMain;
}

void AdminMainPage::on_createButton_2_clicked()
{
    main->handleNewPage(CREATE_PROJECT);
}

void AdminMainPage::on_logoutButton_2_clicked()
{
    main->handleNewPage(WELCOME_PAGE);
}
