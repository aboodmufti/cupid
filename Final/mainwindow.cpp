#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize(Storage* storage){
    //this->handleNewPage(WELCOME_PAGE);
    welcomePage = new WelcomePage();
    welcomePage->setMain(this,storage);
    this->storage = storage;
    this->setCentralWidget(welcomePage);
}

void MainWindow::initialize(){
    WelcomePage* welcome = new WelcomePage();
    welcome->setMain(this,this->storage);
    this->setCentralWidget(welcome);
}


