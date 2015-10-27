#include "studentprofilepage.h"
#include "ui_studentprofilepage.h"

StudentProfilePage::StudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProfilePage)
{
    ui->setupUi(this);
}

StudentProfilePage::~StudentProfilePage()
{
    delete ui;
}
