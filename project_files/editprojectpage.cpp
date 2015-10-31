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

Project* EditProjectPage::getProject()
{
    Project* project = new Project();

    // We need to get 'project Id' and 'project status' to
    // pass project into 'updateProject(project)'
    project->setName(ui->newNameLineEdit->text());
    project->setMinTeamSize(ui->newMinTeamSpinBox->value());
    project->setMaxTeamSize(ui->newMaxTeamSpinBox->value());
    project->setDescription(ui->newDesriptionTextEdit->toPlainText());
    return project;
}
