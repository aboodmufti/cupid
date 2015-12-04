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
    welcomePage = new WelcomePage();
    welcomePage->setMain(this,storage);
    WelcomePage* welcome = new WelcomePage();
    this->setCentralWidget(welcome);
}

void MainWindow2::initialize(){

    this->setCentralWidget(welcomePage);
}
