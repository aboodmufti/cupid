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

void AdminLoginPage::setMain(MainWindow* newMain){
    main = newMain;
}

void AdminLoginPage::on_submitButton_clicked()
{
   //main->handleNewPage(ADMIN_MAIN_PAGE);
    main->checkAdminLogin(ui->usernameTextEdit->toPlainText()); // added hussam

}

QString AdminLoginPage::getUsername(){
    return ui->usernameTextEdit->toPlainText();
}
