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

void createProjectPage::setMain(MainWindow* newMain)
{
    main = newMain;
}

void createProjectPage::on_pushButton_clicked()
{
    main->handleNewPage(PROJECT);
}

Project* createProjectPage::getProject()
{
    Project* project = new Project();
    project->setName(ui->projNameEdit->text());
    project->setMinTeamSize(ui->minTeamSizeSpinBox->value());
    project->setMaxTeamSize(ui->maxTeamSizeSpinBox->value());
    project->setDescription(ui->descriptionEdit->toPlainText());
    return project;
}
