#include "adminstudentprofilepage.h"
#include "ui_adminstudentprofilepage.h"

AdminStudentProfilePage::AdminStudentProfilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminStudentProfilePage)
{
    ui->setupUi(this);
}

AdminStudentProfilePage::~AdminStudentProfilePage()
{
    delete ui;
}

void AdminStudentProfilePage::on_backButton_clicked()
{
     main->openProject(pid);
    //main->handleNewPage(PROJECT);
}

void AdminStudentProfilePage::setMain(MainWindow* newMain){
    main = newMain;
}

void AdminStudentProfilePage::setStudentProfile(StudentProfile* stuProfile,int newpid){
    pid = newpid;
    studentProfile = stuProfile;
    if(studentProfile->getName() != "unknown"){
        ui->stuNameLabel->setText(studentProfile->getName());
        ui->stuIdLabel->setText(QString::number(studentProfile->getID()));

        QColor *blue = new QColor(0, 84, 167);
        QBrush *blueBrush = new QBrush(*blue);
        ui->ownQList->setWordWrap(true);
        ui->ownQList->setTextElideMode(Qt::ElideLeft);

        ui->ownQList->addItem("1. What is your grade in COMP 2404?");
        ui->ownQList->addItem(convertQ(1,(*(studentProfile->getOwnQ()))[1])); //convert to actual answer: from int to meaningful string
        ui->ownQList->addItem("");
        //ui->ownQList->addItem(new QComboBox());
        ui->ownQList->addItem("2. What is your grade in COMP 2402?");
        ui->ownQList->addItem(convertQ(2,(*(studentProfile->getOwnQ()))[2]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("3. Are you Punctual?");
        ui->ownQList->addItem(convertQ(3,(*(studentProfile->getOwnQ()))[3]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("4. Are you technical?");
        ui->ownQList->addItem(convertQ(4,(*(studentProfile->getOwnQ()))[4]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("5. Do you prefer working during group meetings or by yourself?");
        ui->ownQList->addItem(convertQ(5,(*(studentProfile->getOwnQ()))[5]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("6. How many hours per week do you usually dedicate for school work?");
        ui->ownQList->addItem(convertQ(6,(*(studentProfile->getOwnQ()))[6]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("7. How flexible are you in handling emergency situations (e.g. doing other team member's work in case of emergency)?");
        ui->ownQList->addItem(convertQ(7,(*(studentProfile->getOwnQ()))[7]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("8. What grade are you aiming for in this course?");
        ui->ownQList->addItem(convertQ(8,(*(studentProfile->getOwnQ()))[8]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("9. During group meetings, how strict are you when it comes to discussion topics? (i.e. is it alright to discuss nonrelated project topics?)");
        ui->ownQList->addItem(convertQ(9,(*(studentProfile->getOwnQ()))[9]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("10. Would you prefer being a group leader?");
        ui->ownQList->addItem(convertQ(10,(*(studentProfile->getOwnQ()))[10]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("11. Would you mind meeting with the group on weekends?");
        ui->ownQList->addItem(convertQ(11,(*(studentProfile->getOwnQ()))[11]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("12. How many courses are you currently taking?");
        ui->ownQList->addItem(convertQ(12,(*(studentProfile->getOwnQ()))[12]));
        ui->ownQList->addItem("");

        ui->ownQList->addItem("13. How many personal projects have you worked on?");
        ui->ownQList->addItem(convertQ(13,(*(studentProfile->getOwnQ()))[13]));
        ui->ownQList->addItem("");



        for(int z =0 ; z < 39; z+=3){
            ui->ownQList->item(z)->setForeground(*blueBrush);
        }

        ui->partnerQList->setWordWrap(true);
        ui->partnerQList->setTextElideMode(Qt::ElideLeft);

        ui->partnerQList->addItem("1. What grade would you prefer your partner has in COMP 2404?");
        ui->partnerQList->addItem(convertQ(1,(*(studentProfile->getPartnerQ()))[1]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("2. What grade would you prefer your partner has in COMP 2402?");
        ui->partnerQList->addItem(convertQ(2,(*(studentProfile->getPartnerQ()))[2]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("3. Does your partner have to be punctual?");
        ui->partnerQList->addItem(convertQ(3,(*(studentProfile->getPartnerQ()))[3]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("4. Does your partner have to be technical?");
        ui->partnerQList->addItem(convertQ(4,(*(studentProfile->getPartnerQ()))[4]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("5. Do you prefer that your partner works during group meetings or by themselves?");
        ui->partnerQList->addItem(convertQ(5,(*(studentProfile->getPartnerQ()))[5]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("6. How many hours per week do you prefer that your partner dedicates for school work?");
        ui->partnerQList->addItem(convertQ(6,(*(studentProfile->getPartnerQ()))[6]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("7. How flexible should your partner be in handling emergency situations?");
        ui->partnerQList->addItem(convertQ(7,(*(studentProfile->getPartnerQ()))[7]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("8. What is the minimum grade that you prefer your partner to be aiming for in this course?");
        ui->partnerQList->addItem(convertQ(8,(*(studentProfile->getPartnerQ()))[8]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("9. During group meetings, how strict should your partner be when it comes to discussion topics?");
        ui->partnerQList->addItem(convertQ(9,(*(studentProfile->getPartnerQ()))[9]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("10. Would you prefer that your partner takes group leadership?");
        ui->partnerQList->addItem(convertQ(10,(*(studentProfile->getPartnerQ()))[10]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("11. Would you prefer that your partner is capable of meeting on weekends?");
        ui->partnerQList->addItem(convertQ(11,(*(studentProfile->getPartnerQ()))[11]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("12. How many courses would you prefer that your partner is currently taking?");
        ui->partnerQList->addItem(convertQ(12,(*(studentProfile->getPartnerQ()))[12]));
        ui->partnerQList->addItem("");

        ui->partnerQList->addItem("13. How many personal projects do you prefer your partner has worked on?");
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

QString AdminStudentProfilePage::convertQ(int qid,int valueID ){
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
