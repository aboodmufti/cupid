#include "algorithmsummary.h"
#include "ui_algorithmsummary.h"

AlgorithmSummary::AlgorithmSummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlgorithmSummary)
{
    ui->setupUi(this);
}

AlgorithmSummary::~AlgorithmSummary()
{
    delete ui;
}

void AlgorithmSummary::setOutput(QString output){
    ui->output->append(output);
}

void AlgorithmSummary::setManager(AlgorithmManager* manager){
    this->manager = manager;
}

void AlgorithmSummary::on_pushButton_clicked()
{
    manager->goToProject();
}


void AlgorithmSummary::on_detailedResults_clicked()
{
    manager->goToDetails();
}

