#include "studentprofilepage.h"
#include "ui_studentprofilepage.h"

StudentProfilePage::StudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProfilePage)
{
    ui->setupUi(this);
    ui->stuNameLabel->setText("Abood Mufti");
    ui->stuIdLabel->setText("100884076");
    for(int i = 0; i<20; ++i){
        ui->ownQList->insertItem(i,"Abooddd");
    }
}

StudentProfilePage::~StudentProfilePage()
{
    delete ui;
}

void StudentProfilePage::setMain(MainWindow* newMain){
    main = newMain;
}

void StudentProfilePage::on_pushButton_3_clicked()
{
    main->handleNewPage(WELCOME_PAGE);
}

void StudentProfilePage::on_projectsButton_clicked()
{
    main->handleNewPage(STUDENT_PROJECT_LIST);
}

void StudentProfilePage::on_pushButton_clicked()
{
    main->handleNewPage(EDIT_PROFILE);
}

void StudentProfilePage::setStudentProfile(StudentProfile* stuProfile){
    studentProfile = stuProfile;
    if(studentProfile->getName() != "unknown"){
        ui->stuNameLabel->setText(studentProfile->getName());
        ui->stuIdLabel->setText(QString::number(studentProfile->getID()));

        ui->ownQList->insertItem(0,"Qualification question....");
        ui->ownQList->insertItem(1,convertQ(1,(*(studentProfile->getOwnQ()))[1])); //convert to actual answer: from int to meaningful string

        ui->ownQList->insertItem(2,"Qualification question....");
        ui->ownQList->insertItem(3,convertQ(2,(*(studentProfile->getOwnQ()))[2]));

        ui->ownQList->insertItem(4,"Qualification question....");
        ui->ownQList->insertItem(5,convertQ(3,(*(studentProfile->getOwnQ()))[3]));

        ui->ownQList->insertItem(6,"Qualification question....");
        ui->ownQList->insertItem(7,convertQ(4,(*(studentProfile->getOwnQ()))[4]));

        ui->ownQList->insertItem(8,"Qualification question....");
        ui->ownQList->insertItem(9,convertQ(5,(*(studentProfile->getOwnQ()))[5]));

        ui->ownQList->insertItem(10,"Qualification question....");
        ui->ownQList->insertItem(11,convertQ(6,(*(studentProfile->getOwnQ()))[6]));

        ui->ownQList->insertItem(12,"Qualification question....");
        ui->ownQList->insertItem(13,convertQ(7,(*(studentProfile->getOwnQ()))[7]));

        ui->ownQList->insertItem(14,"Qualification question....");
        ui->ownQList->insertItem(15,convertQ(8,(*(studentProfile->getOwnQ()))[8]));

        ui->ownQList->insertItem(16,"Qualification question....");
        ui->ownQList->insertItem(17,convertQ(9,(*(studentProfile->getOwnQ()))[9]));

        ui->ownQList->insertItem(18,"Qualification question....");
        ui->ownQList->insertItem(19,convertQ(10,(*(studentProfile->getOwnQ()))[10]));

        ui->ownQList->insertItem(20,"Qualification question....");
        ui->ownQList->insertItem(21,convertQ(11,(*(studentProfile->getOwnQ()))[11]));

        ui->ownQList->insertItem(22,"Qualification question....");
        ui->ownQList->insertItem(23,convertQ(12,(*(studentProfile->getOwnQ()))[12]));

        ui->ownQList->insertItem(24,"Qualification question....");
        ui->ownQList->insertItem(25,convertQ(13,(*(studentProfile->getOwnQ()))[13]));



        ui->partnerQList->insertItem(0,"Qualification question....");
        ui->partnerQList->insertItem(1,convertQ(1,(*(studentProfile->getPartnerQ()))[1])); //convert to actual answer: from int to meaningful string

        ui->partnerQList->insertItem(2,"Qualification question....");
        ui->partnerQList->insertItem(3,convertQ(2,(*(studentProfile->getPartnerQ()))[2]));

        ui->partnerQList->insertItem(4,"Qualification question....");
        ui->partnerQList->insertItem(5,convertQ(3,(*(studentProfile->getPartnerQ()))[3]));

        ui->partnerQList->insertItem(6,"Qualification question....");
        ui->partnerQList->insertItem(7,convertQ(4,(*(studentProfile->getPartnerQ()))[4]));

        ui->partnerQList->insertItem(8,"Qualification question....");
        ui->partnerQList->insertItem(9,convertQ(5,(*(studentProfile->getPartnerQ()))[5]));

        ui->partnerQList->insertItem(10,"Qualification question....");
        ui->partnerQList->insertItem(11,convertQ(6,(*(studentProfile->getPartnerQ()))[6]));

        ui->partnerQList->insertItem(12,"Qualification question....");
        ui->partnerQList->insertItem(13,convertQ(7,(*(studentProfile->getPartnerQ()))[7]));

        ui->partnerQList->insertItem(14,"Qualification question....");
        ui->partnerQList->insertItem(15,convertQ(8,(*(studentProfile->getPartnerQ()))[8]));

        ui->partnerQList->insertItem(16,"Qualification question....");
        ui->partnerQList->insertItem(17,convertQ(9,(*(studentProfile->getPartnerQ()))[9]));

        ui->partnerQList->insertItem(18,"Qualification question....");
        ui->partnerQList->insertItem(19,convertQ(10,(*(studentProfile->getPartnerQ()))[10]));

        ui->partnerQList->insertItem(20,"Qualification question....");
        ui->partnerQList->insertItem(21,convertQ(11,(*(studentProfile->getPartnerQ()))[11]));

        ui->partnerQList->insertItem(22,"Qualification question....");
        ui->partnerQList->insertItem(23,convertQ(12,(*(studentProfile->getPartnerQ()))[12]));

        ui->partnerQList->insertItem(24,"Qualification question....");
        ui->partnerQList->insertItem(25,convertQ(13,(*(studentProfile->getPartnerQ()))[13]));

    }
    else{
        ui->stuNameLabel->setText("New Student");
        ui->stuIdLabel->setText("New Student");
    }

}

QString StudentProfilePage::convertQ(int qid,int valueID ){
    switch(qid){
        case 1:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 2:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 3:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 4:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 5:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 6:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 7:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 8:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 9:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 10:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 11:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 12:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;
        case 13:{
            switch(valueID){
                case 1:{
                    return "text value";
                }
                break;
                case 2:{
                    return "text value";
                }
                break;
                case 3:{
                    return "text value";
                }
                break;
                case 4:{
                    return "text value";
                }
                break;
                case 5:{
                    return "text value";
                }
                break;
                case 6:{
                    return "text value";
                }
                break;
            }
        }
        break;

    }
    \
}
