#include "editprofilepage.h"
#include "ui_editprofilepage.h"

EditProfilePage::EditProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProfilePage)
{
    ui->setupUi(this);


}

EditProfilePage::~EditProfilePage()
{
    delete ui;
}

void EditProfilePage::setMain(MainWindow* newMain){
    main = newMain;
}

void EditProfilePage::on_pushButton_2_clicked()
{
    main->handleNewPage(STUDENT_PROFILE);
}

void EditProfilePage::on_pushButton_clicked()
{
    main->handleNewPage(STUDENT_PROFILE);
}

void EditProfilePage::setStudentProfile(StudentProfile* stuProfile){
    ui->nameTextEdit->toPlainText();
    ui->nameTextEdit->setPlainText(stuProfile->getName());
    ui->idLabel->setText(QString::number(stuProfile->getID()));

    QList<int> ownQ= (*(stuProfile->getOwnQ()));

    ui->own->setCurrentIndex(ownQ[1]-1);
    ui->own_2->setCurrentIndex(ownQ[2]-1);
    ui->own_3->setCurrentIndex(ownQ[3]-1);
    ui->own_4->setCurrentIndex(ownQ[4]-1);
    ui->own_5->setCurrentIndex(ownQ[5]-1);
    ui->own_6->setCurrentIndex(ownQ[6]-1);
    ui->own_7->setCurrentIndex(ownQ[7]-1);
    ui->own_8->setCurrentIndex(ownQ[8]-1);
    ui->own_9->setCurrentIndex(ownQ[9]-1);
    ui->own_10->setCurrentIndex(ownQ[10]-1);
    ui->own_11->setCurrentIndex(ownQ[11]-1);
    ui->own_12->setCurrentIndex(ownQ[12]-1);
    ui->own_13->setCurrentIndex(ownQ[13]-1);

    QList<int> partnerQ= (*(stuProfile->getPartnerQ()));

    ui->partner->setCurrentIndex(partnerQ[1]-1);
    ui->partner_2->setCurrentIndex(partnerQ[2]-1);
    ui->partner_3->setCurrentIndex(partnerQ[3]-1);
    ui->partner_4->setCurrentIndex(partnerQ[4]-1);
    ui->partner_5->setCurrentIndex(partnerQ[5]-1);
    ui->partner_6->setCurrentIndex(partnerQ[6]-1);
    ui->partner_7->setCurrentIndex(partnerQ[7]-1);
    ui->partner_8->setCurrentIndex(partnerQ[8]-1);
    ui->partner_9->setCurrentIndex(partnerQ[9]-1);
    ui->partner_10->setCurrentIndex(partnerQ[10]-1);
    ui->partner_11->setCurrentIndex(partnerQ[11]-1);
    ui->partner_12->setCurrentIndex(partnerQ[12]-1);
    ui->partner_13->setCurrentIndex(partnerQ[13]-1);


}
