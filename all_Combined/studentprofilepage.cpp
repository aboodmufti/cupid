#include "studentprofilepage.h"
#include "ui_studentprofilepage.h"

StudentProfilePage::StudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentProfilePage)
{
    ui->setupUi(this);
    /*ui->stuNameLabel->setText("Abood Mufti");
    ui->stuIdLabel->setText("100884076");
    for(int i = 0; i<20; ++i){
        ui->ownQList->addItem(i,"Abooddd");
    }*/
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

        QColor *blue = new QColor(0, 84, 167);
        QBrush *blueBrush = new QBrush(*blue);
        ui->ownQList->setWordWrap(true);
        ui->ownQList->setTextElideMode(Qt::ElideLeft);

        ui->ownQList->addItem("Your grade in COMP 2404?");
        ui->ownQList->addItem(convertQ(1,(*(studentProfile->getOwnQ()))[1])); //convert to actual answer: from int to meaningful string
        ui->ownQList->addItem("");
        //ui->ownQList->addItem(new QComboBox());
        ui->ownQList->addItem("Your grade in COMP 2402?");
        ui->ownQList->addItem(convertQ(2,(*(studentProfile->getOwnQ()))[2]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("Are you Punctual?");
        ui->ownQList->addItem(convertQ(3,(*(studentProfile->getOwnQ()))[3]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("How technical are you?");
        ui->ownQList->addItem(convertQ(4,(*(studentProfile->getOwnQ()))[4]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("You prefer doing most of the work during group meetings or by yourself?");
        ui->ownQList->addItem(convertQ(5,(*(studentProfile->getOwnQ()))[5]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("How many hours per week do you dedicate for school work?");
        ui->ownQList->addItem(convertQ(6,(*(studentProfile->getOwnQ()))[6]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("How flexible are you for handling emergency situations(e.g. do other team memeber's work in case of emergency)?");
        ui->ownQList->addItem(convertQ(7,(*(studentProfile->getOwnQ()))[7]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("What is the grade you are aiming for in this course?");
        ui->ownQList->addItem(convertQ(8,(*(studentProfile->getOwnQ()))[8]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("During group meetings, do you like to strictly talk about the project or is it ok to talk about other subjects too?");
        ui->ownQList->addItem(convertQ(9,(*(studentProfile->getOwnQ()))[9]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("Would you like to be a group leader?");
        ui->ownQList->addItem(convertQ(10,(*(studentProfile->getOwnQ()))[10]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("Would you mind meeting with the group during the weekend?");
        ui->ownQList->addItem(convertQ(11,(*(studentProfile->getOwnQ()))[11]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("How many courses are you currently taking?");
        ui->ownQList->addItem(convertQ(12,(*(studentProfile->getOwnQ()))[12]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("How many personal projects have you done?");
        ui->ownQList->addItem(convertQ(13,(*(studentProfile->getOwnQ()))[13]));
        ui->ownQList->addItem("");



        for(int z =0 ; z < 39; z+=3){
            ui->ownQList->item(z)->setForeground(*blueBrush);
        }

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(1,(*(studentProfile->getPartnerQ()))[1]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(2,(*(studentProfile->getPartnerQ()))[2]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(3,(*(studentProfile->getPartnerQ()))[3]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(4,(*(studentProfile->getPartnerQ()))[4]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(5,(*(studentProfile->getPartnerQ()))[5]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(6,(*(studentProfile->getPartnerQ()))[6]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(7,(*(studentProfile->getPartnerQ()))[7]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(8,(*(studentProfile->getPartnerQ()))[8]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(9,(*(studentProfile->getPartnerQ()))[9]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(10,(*(studentProfile->getPartnerQ()))[10]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(11,(*(studentProfile->getPartnerQ()))[11]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(12,(*(studentProfile->getPartnerQ()))[12]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("Qualification question....");
        ui->partnerQList->addItem(convertQ(13,(*(studentProfile->getPartnerQ()))[13]));
        ui->partnerQList->addItem("");

        for(int z =0 ; z < 39; z+=3){
            ui->partnerQList->item(z)->setForeground(*blueBrush);
        }

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
      default:
        return "ERROR!";
        break;

    }
    return "ERROR!";
}
