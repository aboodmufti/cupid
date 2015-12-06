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

void AdminLoginPage::setManager(ProjectManager* pm){
    projectManager = pm;
}

void AdminLoginPage::on_submitButton_clicked()
{
   //main->handleNewPage(ADMIN_MAIN_PAGE);

    if(ui->usernameTextEdit->toPlainText().trimmed() == "" ){
        ui->errorLabel->setText("This is a required field");
        return;
    }
    projectManager->checkAdminLogin(ui->usernameTextEdit->toPlainText()); // added hussam
}

void AdminLoginPage::on_backButton_clicked()
{
    //projectManager->handleNewPage(WELCOME_PAGE);
    projectManager->getMain()->initialize();
}

QString AdminLoginPage::getUsername()
{
    return ui->usernameTextEdit->toPlainText();
}



