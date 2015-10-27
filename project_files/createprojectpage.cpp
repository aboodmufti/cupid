#include "createprojectpage.h"
#include "ui_createprojectpage.h"

createProjectPage::createProjectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createProjectPage)
{
    ui->setupUi(this);
}

createProjectPage::~createProjectPage()
{
    delete ui;
}

void createProjectPage::setMain(MainWindow* newMain){
    main = newMain;
}

void createProjectPage::on_pushButton_clicked()
{
    main->handleNewPage(PROJECT);
}
