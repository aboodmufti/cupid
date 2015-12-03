#include "ProfileSubsystem/studentprofilepage.h"
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
    manager->getMainWindow() = newMain;
}

void StudentProfilePage::on_pushButton_3_clicked()
{
    manager->getMainWindow()->handleNewPage(WELCOME_PAGE);
}

void StudentProfilePage::on_projectsButton_clicked()
{
    if(manager->getStorage()->getProfileName() == "unknown"){
        ui->errorLabel->setText("Please fill in your profile to be able to view projects");
        return;
    }
    manager->getMainWindow()->handleNewPage(STUDENT_PROJECT_LIST);
}

void StudentProfilePage::on_pushButton_clicked()
{
    manager->getMainWindow()->handleNewPage(EDIT_PROFILE);
}

void StudentProfilePage::setStudentProfile(StudentProfile* stuProfile){
    // create a student profile through the facade class
    //StudentProfile* studentProfile = manager->getStorage()->createStudentProfile();
    //studentProfile = stuProfile;

    manager->getStorage()->setStudentProfile(stuProfile);

    if(manager->getStorage()->getProfileName() != "unknown"){
        ui->stuNameLabel->setText(manager->getStorage()->getProfileName());
        ui->stuIdLabel->setText(QString::number(manager->getStorage()->getProfileID()));

        QColor *blue = new QColor(0, 84, 167);
        QBrush *blueBrush = new QBrush(*blue);
        ui->ownQList->setWordWrap(true);
        ui->ownQList->setTextElideMode(Qt::ElideLeft);

        ui->ownQList->addItem("1. What is your grade in COMP 2404?");
        ui->ownQList->addItem(convertQ(1,(*(manager->getStorage()->getOwnQ()))[1])); //convert to actual answer: from int to meaningful string
        ui->ownQList->addItem("");
        //ui->ownQList->addItem(new QComboBox());
        ui->ownQList->addItem("2. What is your grade in COMP 2402?");
        ui->ownQList->addItem(convertQ(2,(*(manager->getStorage()->getOwnQ()))[2]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("3. Are you punctual?");
        ui->ownQList->addItem(convertQ(3,(*(manager->getStorage()->getOwnQ()))[3]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("4. Are you technical?");
        ui->ownQList->addItem(convertQ(4,(*(manager->getStorage()->getOwnQ()))[4]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("5. Do you prefer working during group meetings or by yourself?");
        ui->ownQList->addItem(convertQ(5,(*(manager->getStorage()->getOwnQ()))[5]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("6. How many hours per week do you usually dedicate for school work?");
        ui->ownQList->addItem(convertQ(6,(*(manager->getStorage()->getOwnQ()))[6]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("7. How flexible are you in handling emergency situations (e.g. doing other team member's work in case of emergency)?");
        ui->ownQList->addItem(convertQ(7,(*(manager->getStorage()->getOwnQ()))[7]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("8. What grade are you aiming for in this course?");
        ui->ownQList->addItem(convertQ(8,(*(manager->getStorage()->getOwnQ()))[8]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("9. During group meetings, how strict are you when it comes to discussion topics? (i.e. is it alright to discuss nonrelated project topics?)");
        ui->ownQList->addItem(convertQ(9,(*(manager->getStorage()->getOwnQ()))[9]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("10. Would you prefer being a group leader?");
        ui->ownQList->addItem(convertQ(10,(*(manager->getStorage()->getOwnQ()))[10]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("11. Would you mind meeting with the group on weekends?");
        ui->ownQList->addItem(convertQ(11,(*(manager->getStorage()->getOwnQ()))[11]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("12. How many courses are you currently taking?");
        ui->ownQList->addItem(convertQ(12,(*(manager->getStorage()->getOwnQ()))[12]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("13. How many personal projects have you worked on?");
        ui->ownQList->addItem(convertQ(13,(*(manager->getStorage()->getOwnQ()))[13]));
        ui->ownQList->addItem("");



        for(int z =0 ; z < 39; z+=3){
            ui->ownQList->item(z)->setForeground(*blueBrush);
        }

        ui->partnerQList->setWordWrap(true);
        ui->partnerQList->setTextElideMode(Qt::ElideLeft);

        ui->partnerQList->addItem("1. What grade would you prefer your partner has in COMP 2404?");
        ui->partnerQList->addItem(convertQ(1,(*(manager->getStorage()->getPartnerQ()))[1]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("2. What grade would you prefer your partner has in COMP 2402?");
        ui->partnerQList->addItem(convertQ(2,(*(manager->getStorage()->getPartnerQ()))[2]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("3. Does your partner have to be punctual?");
        ui->partnerQList->addItem(convertQ(3,(*(manager->getStorage()->getPartnerQ()))[3]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("4. Does your partner have to be technical?");
        ui->partnerQList->addItem(convertQ(4,(*(manager->getStorage()->getPartnerQ()))[4]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("5. Do you prefer that your partner works during group meetings or by themselves?");
        ui->partnerQList->addItem(convertQ(5,(*(manager->getStorage()->getPartnerQ()))[5]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("6. How many hours per week do you prefer that your partner dedicates for school work?");
        ui->partnerQList->addItem(convertQ(6,(*(manager->getStorage()->getPartnerQ()))[6]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("7. How flexible should your partner be in handling emergency situations?");
        ui->partnerQList->addItem(convertQ(7,(*(manager->getStorage()->getPartnerQ()))[7]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("8. What is the minimum grade that you prefer your partner to be aiming for in this course?");
        ui->partnerQList->addItem(convertQ(8,(*(manager->getStorage()->getPartnerQ()))[8]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("9. During group meetings, how strict should your partner be when it comes to discussion topics?");
        ui->partnerQList->addItem(convertQ(9,(*(manager->getStorage()->getPartnerQ()))[9]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("10. Would you prefer that your partner takes group leadership?");
        ui->partnerQList->addItem(convertQ(10,(*(manager->getStorage()->getPartnerQ()))[10]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("11. Would you prefer that your partner is capable of meeting on weekends?");
        ui->partnerQList->addItem(convertQ(11,(*(manager->getStorage()->getPartnerQ()))[11]));
        ui->partnerQList->addItem(""); //How many courses are you currently taking?

        ui->partnerQList->addItem("12. How many courses would you prefer that your partner is currently taking?");
        ui->partnerQList->addItem(convertQ(12,(*(manager->getStorage()->getPartnerQ()))[12]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("13. How many personal projects do you prefer your partner has worked on?");
        ui->partnerQList->addItem(convertQ(13,(*(manager->getStorage()->getPartnerQ()))[13]));
        ui->partnerQList->addItem("");

        for(int z =0 ; z < 39; z+=3){
            ui->partnerQList->item(z)->setForeground(*blueBrush);
        }
    }
}

QString StudentProfilePage::convertQ(int qid,int valueID ){
    switch(qid){
        case 1:{
            switch(valueID){
                case 1:{
                    return "A";
                }
                break;
                case 2:{
                    return "B";
                }
                break;
                case 3:{
                    return "C";
                }
                break;
                case 4:{
                    return "D";
                }
                break;
            }
        }
        break;
        case 2:{
            switch(valueID){
                case 1:{
                    return "A";
                }
                break;
                case 2:{
                    return "B";
                }
                break;
                case 3:{
                    return "C";
                }
                break;
                case 4:{
                    return "D";
                }
                break;
            }
        }
        break;
        case 3:{
            switch(valueID){
                case 1:{
                    return "No";
                }
                break;
                case 2:{
                    return "Yes";
                }
                break;
            }
        }
        break;
        case 4:{
            switch(valueID){
                case 1:{
                    return "No";
                }
                break;
                case 2:{
                    return "Yes";
                }
                break;
            }
        }
        break;
        case 5:{
            switch(valueID){
                case 1:{
                    return "By myself";
                }
                break;
                case 2:{
                    return "Sometimes by myself and sometimes with the group";
                }
                break;
                case 3:{
                    return "With the group";
                }
                break;
            }
        }
        break;
        case 6:{
            switch(valueID){
                case 1:{
                    return "1-3 hours per week";
                }
                break;
                case 2:{
                    return "4-7 hours per week";
                }
                break;
                case 3:{
                    return "8 or more hours per week";
                }
                break;
            }
        }
        break;
        case 7:{
            switch(valueID){
                case 1:{
                    return "Very inflexible";
                }
                break;
                case 2:{
                    return "Somewhat inflexible";
                }
                break;
                case 3:{
                    return "Neither flexible nor inflexible";
                }
                break;
                case 4:{
                    return "Somewhat flexible";
                }
                break;
                case 5:{
                    return "Very flexible";
                }
                break;
            }
        }
        break;
        case 8:{
            switch(valueID){
                case 1:{
                    return "A";
                }
                break;
                case 2:{
                    return "B";
                }
                break;
                case 3:{
                    return "C";
                }
                break;
                case 4:{
                    return "D";
                }
                break;
            }
        }
        break;
        case 9:{
            switch(valueID){
                case 1:{
                    return "Not at all strict";
                }
                break;
                case 2:{
                    return "Somewhat strict";
                }
                break;
                case 3:{
                    return "Very strict";
                }
                break;
            }
        }
        break;
        case 10:{
            switch(valueID){
                case 1:{
                    return "No";
                }
                break;
                case 2:{
                    return "Yes";
                }
                break;
            }
        }
        break;
        case 11:{
            switch(valueID){
                case 1:{
                    return "No";
                }
                break;
                case 2:{
                    return "Yes";
                }
                break;
            }
        }
        break;
        case 12:{
            switch(valueID){
                case 1:{
                    return "1";
                }
                break;
                case 2:{
                    return "2";
                }
                break;
                case 3:{
                    return "3";
                }
                break;
                case 4:{
                    return "4";
                }
                break;
                case 5:{
                    return "5 or more";
                }
                break;

            }
        }
        break;
        case 13:{
            switch(valueID){
                case 1:{
                    return "3 or less";
                }
                break;
                case 2:{
                    return "More than 3";
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
