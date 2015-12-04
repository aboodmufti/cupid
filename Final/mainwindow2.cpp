#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "welcomepage.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::initialize(Storage* storage){
    //this->handleNewPage(WELCOME_PAGE);
    qDebug()<< "DEBUG 1";
    welcomePage = new WelcomePage();
    qDebug()<< "DEBUG 2";
    welcomePage->setMain(this,storage);
    qDebug()<< "DEBUG 3";
    WelcomePage* welcome = new WelcomePage();
    this->setCentralWidget(welcome);
    qDebug()<< "DEBUG 4";
}

void MainWindow2::initialize(){

    this->setCentralWidget(welcomePage);
}
