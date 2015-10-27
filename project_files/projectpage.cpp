#include "projectpage.h"
#include "ui_projectpage.h"

ProjectPage::ProjectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectPage)
{
    ui->setupUi(this);
}

ProjectPage::~ProjectPage()
{
    delete ui;
}

void ProjectPage::setMain(MainWindow* newMain){
    main = newMain;
}

void ProjectPage::on_pushButton_clicked()
{
    main->handleNewPage(ADMIN_MAIN_PAGE);
}

void ProjectPage::on_pushButton_3_clicked()
{
    main->handleNewPage(ADMIN_MAIN_PAGE);
}

void ProjectPage::on_pushButton_4_clicked()
{
    main->handleNewPage(EDIT_PROJECT);
}
