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

void createProjectPage::setManager(ProjectManager* pm)
{
    projectManager = pm;
}

void createProjectPage::on_pushButton_clicked()
{
    if(ui->projNameEdit->text().trimmed() == ""  ){
        ui->errorLabel->setText("Please don't leave name field blank");
        return;
    }
    int newID = projectManager->createProject(getProject());
    projectManager->openProject(newID);
}

Project* createProjectPage::getProject()
{
    Project* project = projectManager->getStorage()->createProject();
    project->setName(ui->projNameEdit->text());
    project->setMinTeamSize(ui->minTeamSizeSpinBox->value());
    project->setMaxTeamSize(ui->maxTeamSizeSpinBox->value());
    project->setDescription(ui->descriptionEdit->toPlainText());
    return project;
}

void createProjectPage::on_cancelButton_clicked()
{
    projectManager->adminMainPage();
}