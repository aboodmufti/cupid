#include "studentprojectspage.h"
#include "ui_studentprojectspage.h"

StudentProjectsPage::StudentProjectsPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProjectsPage)
{
    ui->setupUi(this);
}

StudentProjectsPage::~StudentProjectsPage()
{
    delete ui;
}
