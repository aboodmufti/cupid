#include "detailedresults.h"
#include "ui_detailedresults.h"

DetailedResults::DetailedResults(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailedResults)
{
    ui->setupUi(this);
}

DetailedResults::~DetailedResults()
{
    delete ui;
}


void DetailedResults::setManager(AlgorithmManager* _manager){
    this->manager = _manager;
}

void DetailedResults::on_pushButton_clicked()
{
    manager->goToSummary();
}


void DetailedResults::setOutput(QString output){
    ui->outputBrowser->setText(output);

}
