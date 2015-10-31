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

void EditProfilePage::setMain(MainWindow* newMain){
    main = newMain;
}

void EditProfilePage::on_pushButton_2_clicked()
{
    main->handleNewPage(STUDENT_PROFILE);
}

void EditProfilePage::on_pushButton_clicked()
{
    main->handleNewPage(STUDENT_PROFILE);
}
