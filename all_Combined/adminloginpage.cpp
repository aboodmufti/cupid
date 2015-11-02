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

    if(ui->usernameTextEdit->toPlainText().trimmed() == "" ){
        ui->errorLabel->setText("This is a required field");
        return;
    }
    main->checkAdminLogin(ui->usernameTextEdit->toPlainText()); // added hussam
}

void AdminLoginPage::on_backButton_clicked()
{
    main->handleNewPage(WELCOME_PAGE);
}

QString AdminLoginPage::getUsername()
{
    return ui->usernameTextEdit->toPlainText();
}



