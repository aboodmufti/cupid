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

void StudentLoginPage::setMain(MainWindow* newMain){
    main = newMain;
}

void StudentLoginPage::on_submitButton_clicked()
{
    //main->handleNewPage(STUDENT_PROFILE);
    if(ui->usernameTextEdit->toPlainText().trimmed() == "" ){
        ui->errorLabel->setText("Please don't leave it blank");
        return;
    }
    main->checkStudentLogin(ui->usernameTextEdit->toPlainText()); // added hussam

}

void StudentLoginPage::on_backButton_clicked()
{
    main->handleNewPage(WELCOME_PAGE);
}

QString StudentLoginPage::getUsername()
{
    return ui->usernameTextEdit->toPlainText();
}
