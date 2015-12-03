#include "ProfileSubsystem/welcomepage.h"
#include "ui_welcomepage.h"

WelcomePage::WelcomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomePage)
{
    ui->setupUi(this);
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::setMain(MainWindow* newMain){
    manager->getMainWindow() = newMain;
}

void WelcomePage::on_adminButton_2_clicked()
{
    manager->getMainWindow()->handleNewPage(ADMIN_LOGIN);
}

void WelcomePage::on_studentButton_2_clicked()
{
    manager->getMainWindow()->handleNewPage(STUDENT_LOGIN);
}
