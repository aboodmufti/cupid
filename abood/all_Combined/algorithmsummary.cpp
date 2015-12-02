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
