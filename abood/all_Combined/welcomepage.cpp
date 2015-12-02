#include "welcomepage.h"
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
    main = newMain;
}

void WelcomePage::on_adminButton_2_clicked()
{
    main->handleNewPage(ADMIN_LOGIN);
}

void WelcomePage::on_studentButton_2_clicked()
{
    main->handleNewPage(STUDENT_LOGIN);
}
