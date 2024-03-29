#include "ProfileSubsystem/studentloginpage.h"
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
/*
void StudentLoginPage::setMain(MainWindow* newMain){
    manager->getMainWindow() = newMain;
}
*/
void StudentLoginPage::setManager(ProfileManager* mngr)
{
    manager = mngr;
}

void StudentLoginPage::on_submitButton_clicked()
{
    //main->handleNewPage(STUDENT_PROFILE);
    if(ui->usernameTextEdit->toPlainText().trimmed() == "" ){
        ui->errorLabel->setText("This is a required field");
        return;
    }
    manager->checkStudentLogin(ui->usernameTextEdit->toPlainText()); // added hussam
}

void StudentLoginPage::on_backButton_clicked()
{
    //manager->getMainWindow()->handleNewPage(WELCOME_PAGE);
    manager->getMainWindow()->initialize();
}

QString StudentLoginPage::getUsername()
{
    return ui->usernameTextEdit->toPlainText();
}
