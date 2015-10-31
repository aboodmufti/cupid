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
      main->checkStudentLogin(ui->usernameTextEdit->toPlainText()); // added hussam

}

QString StudentLoginPage::getUsername(){
    return ui->usernameTextEdit->toPlainText();
}
