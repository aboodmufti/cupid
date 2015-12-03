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

void EditProjectPage::on_pushButton_clicked() // save
{
    if(ui->newNameLineEdit->text().trimmed() == ""  ){
        ui->errorLabel->setText("Please don't leave name field blank");
        return;
    }
    main->updateProject(getProject());
    main->openProject(pid);
   // main->handleNewPage(PROJECT);
}

void EditProjectPage::on_pushButton_2_clicked() // cancel
{
    main->openProject(pid);
    //main->openProject(newID);
    //main->handleNewPage(PROJECT);
}

Project* EditProjectPage::getProject()
{
    Project* project = new Project();

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
