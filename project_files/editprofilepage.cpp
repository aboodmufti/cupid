#include "editprofilepage.h"
#include "ui_editprofilepage.h"

EditProfilePage::EditProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProfilePage)
{
    ui->setupUi(this);
}

EditProfilePage::~EditProfilePage()
{
    delete ui;
}
