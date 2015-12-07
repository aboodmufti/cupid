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

void EditProjectPage::setManager(ProjectManager* pm){
    projectManager = pm;
}

void EditProjectPage::on_pushButton_clicked() // save
{
    int newMin = ui->newMinTeamSpinBox->text().toInt();
    int newMax = ui->newMaxTeamSpinBox->text().toInt();
    qDebug()<< newMin;
    if(ui->newNameLineEdit->text().trimmed() == ""  ){
        ui->errorLabel->setText("Please don't leave name field blank");
        return;
    }
    if(newMin < 2){
        ui->errorLabel->setText("Minimum team size cannot be less than two");
        return;
    }
    if(newMax <= newMin){
        ui->errorLabel->setText("Maximum team size cannot be less than or equal to the minimum size");
        return;
    }
    projectManager->updateProject(getProject());
    projectManager->openProject(pid,1);
}

void EditProjectPage::on_pushButton_2_clicked() // cancel
{
    projectManager->openProject(pid,1);

}

Project* EditProjectPage::getProject()
{
    Project* project = projectManager->getStorage()->createNewProject();

    // We need to get 'project Id' and 'project status' to
    // pass project into 'updateProject(project)'
    project->setID(pid);

    project->setName(ui->newNameLineEdit->text());
    project->setMinTeamSize(ui->newMinTeamSpinBox->value());
    project->setMaxTeamSize(ui->newMaxTeamSpinBox->value());
    project->setDescription(ui->newDesriptionTextEdit->toPlainText());
    return project;
}

// To display the project info that has already been set before
void EditProjectPage::setProject(Project* proj)
{
    pid = proj->getID();
    ui->projectNameLabel->setText(proj->getName());
    ui->newNameLineEdit->setText(proj->getName());
    ui->newMinTeamSpinBox->setValue(proj->getMinTeamSize());
    ui->newMaxTeamSpinBox->setValue(proj->getMaxTeamSize());
    ui->newDesriptionTextEdit->setPlainText(proj->getDescription());
}
