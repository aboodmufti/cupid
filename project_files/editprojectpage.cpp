#include "editprojectpage.h"
#include "ui_editprojectpage.h"

EditProjectPage::EditProjectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProjectPage)
{
    ui->setupUi(this);
}

EditProjectPage::~EditProjectPage()
{
    delete ui;
}
