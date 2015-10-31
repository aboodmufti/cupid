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

void EditProjectPage::setMain(MainWindow* newMain){
    main = newMain;
}

void EditProjectPage::on_pushButton_clicked()
{
    main->handleNewPage(PROJECT);
}

void EditProjectPage::on_pushButton_2_clicked()
{
    main->handleNewPage(PROJECT);
}
