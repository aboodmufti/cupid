#include "ProfileSubsystem/editprofilepage.h"
#include "ui_editprofilepage.h"

EditProfilePage::EditProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProfilePage)
{
    ui->setupUi(this);
    newStu = 1;
    ownQID = -1;
    partnerQID = -1;

}

EditProfilePage::~EditProfilePage()
{
    delete ui;
}
/*
void EditProfilePage::setMain(MainWindow* newMain){
    manager->getMainWindow() = newMain;
}
*/
void EditProfilePage::setManager(ProfileManager* mngr)
{
    manager = mngr;
}

void EditProfilePage::on_pushButton_2_clicked()
{
    //manager->getMainWindow()->handleNewPage(STUDENT_PROFILE);
    manager->setStudentProfilePage();
}

//Save button
void EditProfilePage::on_pushButton_clicked()
{
    if(ui->nameTextEdit->toPlainText().trimmed() == ""  || ui->studentIDTextEdit->toPlainText().trimmed() == "" ){
        ui->errorLabel->setText("Please don't leave any field empty");
        return;
    }

    /*StudentProfile *stuProfile = new StudentProfile();
    stuProfile->setName(ui->nameTextEdit->toPlainText());
    stuProfile->setUsername(username);*/

    StudentProfile *stuProfile = manager->getStorage()->createNewStudentProfile();
    stuProfile->setName(ui->nameTextEdit->toPlainText());
    stuProfile->setUsername(username);
    /*
    manager->getStorage()->createStudentProfile();
    manager->getStorage()->setProfileName(ui->nameTextEdit->toPlainText());
    manager->getStorage()->setUsername(username);
    */
    QList<int>* ownQ= new QList<int>();
    (*ownQ) += ownQID;
    (*ownQ) += ((ui->own->currentIndex())+1);
    (*ownQ) += ((ui->own_2->currentIndex())+1);
    (*ownQ) += ((ui->own_3->currentIndex())+1);
    (*ownQ) += ((ui->own_4->currentIndex())+1);
    (*ownQ) += ((ui->own_5->currentIndex())+1);
    (*ownQ) += ((ui->own_6->currentIndex())+1);
    (*ownQ) += ((ui->own_7->currentIndex())+1);
    (*ownQ) += ((ui->own_8->currentIndex())+1);
    (*ownQ) += ((ui->own_9->currentIndex())+1);
    (*ownQ) += ((ui->own_10->currentIndex())+1);
    (*ownQ) += ((ui->own_11->currentIndex())+1);
    (*ownQ) += ((ui->own_12->currentIndex())+1);
    (*ownQ) += ((ui->own_13->currentIndex())+1);


    QList<int>* partnerQ= new QList<int>();
    (*partnerQ) += partnerQID;
    (*partnerQ) += ((ui->partner->currentIndex())+1);
    (*partnerQ) += ((ui->partner_2->currentIndex())+1);
    (*partnerQ) += ((ui->partner_3->currentIndex())+1);
    (*partnerQ) += ((ui->partner_4->currentIndex())+1);
    (*partnerQ) += ((ui->partner_5->currentIndex())+1);
    (*partnerQ) += ((ui->partner_6->currentIndex())+1);
    (*partnerQ) += ((ui->partner_7->currentIndex())+1);
    (*partnerQ) += ((ui->partner_8->currentIndex())+1);
    (*partnerQ) += ((ui->partner_9->currentIndex())+1);
    (*partnerQ) += ((ui->partner_10->currentIndex())+1);
    (*partnerQ) += ((ui->partner_11->currentIndex())+1);
    (*partnerQ) += ((ui->partner_12->currentIndex())+1);
    (*partnerQ) += ((ui->partner_13->currentIndex())+1);
/*
    manager->getStorage()->setOwnQ(ownQ);
    manager->getStorage()->setPartnerQ(partnerQ);*/
    stuProfile->setOwnQ(ownQ);
    stuProfile->setPartnerQ(partnerQ);
    if(newStu == 1){
        QRegExp re("\\d*");
        if (!re.exactMatch(ui->studentIDTextEdit->toPlainText())){
            ui->errorLabel->setText("Student ID should only contain numbers");
            return;
        }
        if(manager->getStudentbyID(ui->studentIDTextEdit->toPlainText().toInt())){
            ui->errorLabel->setText("Student ID already exists");
            return;
        }

        //manager->getStorage()->setProfileID((ui->studentIDTextEdit->toPlainText()).toInt());
        stuProfile->setID((ui->studentIDTextEdit->toPlainText()).toInt());
        manager->editProfileSubmit(newStu, stuProfile);
       //manager->editProfileSubmit(newStu, manager->getStorage()->getOwnProfile());
    }else if(newStu == 0){
        stuProfile->setID(stuID);
        //manager->getStorage()->setProfileID(stuID);
        //manager->editProfileSubmit(newStu, manager->getStorage()->getOwnProfile());
        manager->editProfileSubmit(newStu, stuProfile);
    }

}

void EditProfilePage::setStudentProfile(StudentProfile* stuProfile){
    username = stuProfile->getUsername();
    if(stuProfile->getName() == "unknown"){
        newStu = 1;
        ui->studentIDTextEdit->setReadOnly(false);
    }
    else{
        newStu = 0;
        stuID = stuProfile->getID();

        ui->nameTextEdit->setPlainText(stuProfile->getName());
        //ui->idLabel->setText(QString::number(stuProfile->getID()));
        ui->studentIDTextEdit->setPlainText(QString::number(stuProfile->getID()));
        ui->studentIDTextEdit->setReadOnly(true);
        QList<int> ownQ= (*(stuProfile->getOwnQ()));
        ownQID = ownQ[0];
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
        partnerQID = partnerQ[0];
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

}
