#include "algorithmmanager.h"
#include <QTextStream>

AlgorithmManager::AlgorithmManager(Storage* storage, MainWindow* main)
{
    this->storage = storage;
    this->mainWindow = main;
}

void AlgorithmManager::runAlgorithm(Project* project, QList<StudentProfile*>* studentsInProject){
    pid = project->getID();
    int numStudents = studentsInProject->size();
    int maxSize = project->getMaxTeamSize();
    int minSize = project->getMinTeamSize();

    //get teams list with sizes
    QList<QMap<QString, int>*>* initialTeams = preventiveMeasures(minSize, maxSize, numStudents);


    //get individual score lists
    QList<QMap<int, QMap<int,int>*>*>* individualScoreList;
    individualScoreList = step1(studentsInProject);

    //get list of final scores between each pair
    QList<QList<int>*>* finalList = step2(individualScoreList);


    qDebug() << "------------------------------------------------------------------------------------------\n";
    qDebug() << "                FINAL SCORE LIST\n";
    qDebug() << "------------------------------------------------------------------------------------------\n";
    for(int i = 0; i < finalList->size() ; ++i){
        qDebug() << "Student 1:" << finalList->at(i)->at(0) << "  " << "Student 2:" << finalList->at(i)->at(1) << "Score:" << (float)finalList->at(i)->at(2)/100 ;
        qDebug() << "------------------------------------------------------------------------------------------";
    }

    //get the list of student ids
    QList<int>* stuIdList = idList(studentsInProject);
    qDebug() << "------------------------------------------------------------------------------------------";
    qDebug() << "                STUDENT IDS";
    qDebug() << "------------------------------------------------------------------------------------------";
    for(int i = 0; i < stuIdList->size() ; ++i){
        qDebug() << stuIdList->at(i);
    }

    //create teams
    output = step3(initialTeams,finalList, stuIdList);


    algoPage = new AlgorithmSummary();
    algoPage->setManager(this);
    algoPage->setAllOutput(initialTeams);
    initialTeams2 = initialTeams;

    mainWindow->setCentralWidget(algoPage);



}

Storage* AlgorithmManager::getStorage(){
    return storage;
}

QList<QMap<QString, int>*>* AlgorithmManager::preventiveMeasures(int minSize, int maxSize, int numStudents){
    QList<QMap<QString, int>*>* teams = new QList<QMap<QString, int>*>();
    qDebug() << "Preventive Measures START";
    //initial test
    int remainder = numStudents % maxSize;
    int numFullTeams = qFloor(numStudents / maxSize);
    if(remainder == 0){
        int numTeams = numStudents / maxSize;
        for(int i=0 ; i<numTeams ; ++i){
            QMap<QString, int>* team = new QMap<QString, int>();
            team->insert("size", maxSize);
            team->insert("remaining", maxSize);
            teams->append(team);
        }
        qDebug() << "Preventive Measures END";
        return teams;
    }else{
        numFullTeams -= 1;
        int noTeamStus = remainder + maxSize;
        int divider = 2;
        while(qFloor(noTeamStus/divider) < minSize){
            numFullTeams -= 1;
            noTeamStus += maxSize;
            divider += 1;
        }

        remainder = noTeamStus % divider;

        //Adding full teams
        for(int i=0 ; i<numFullTeams ; ++i){
            QMap<QString, int>* team = new QMap<QString, int>();
            team->insert("size", maxSize);
            team->insert("remaining", maxSize);
            teams->append(team);
        }

        //Adding team with the extra student
        QMap<QString, int>* team = new QMap<QString, int>();
        team->insert("size", (qFloor(noTeamStus/divider)+remainder));
        team->insert("remaining", (qFloor(noTeamStus/divider)+remainder));
        teams->append(team);

        //Adding the rest
        for(int i=0 ; i<divider-1 ; ++i){
            QMap<QString, int>* team = new QMap<QString, int>();
            team->insert("size", (qFloor(noTeamStus/divider)));
            team->insert("remaining", (qFloor(noTeamStus/divider)));
            teams->append(team);
        }
        qDebug() << "Preventive Measures END";
        return teams;
    }
}


QList<QMap<int, QMap<int,int>*>*>* AlgorithmManager::step1(QList<StudentProfile*>* studentsInProject){
    QList<QMap<int, QMap<int,int>*>*>* individualScoreList = new QList<QMap<int, QMap<int,int>*>*>();
    int totalStuNum = studentsInProject->size();

    for(int i = 0 ; i < totalStuNum; ++i){
        StudentProfile* currStu = studentsInProject->at(i);
        QMap<int, QMap<int,int>*>* currStuList = new QMap<int, QMap<int,int>*>();
        QMap<int,int>* scores = new QMap<int,int>();

        for(int z = 0 ; z < totalStuNum; ++z){
            StudentProfile* comparedStu = studentsInProject->at(z);
            if(comparedStu->getID() == currStu->getID()){
                continue;
            }
            int sumOfDiffs = 0;
            for(int y = 1 ; y < 14; ++y){
                QList<int>* currStuPartnerQ = currStu->getPartnerQ();
                QList<int>* comparedStuOwnQ = comparedStu->getPartnerQ();

                sumOfDiffs += qFabs(currStuPartnerQ->at(y) - comparedStuOwnQ->at(y));
            }
            scores->insert(comparedStu->getID(),sumOfDiffs);
        }
        currStuList->insert(currStu->getID(), scores);
        individualScoreList->append(currStuList);
    }

    return individualScoreList;

}


QList<QList<int>*>* AlgorithmManager::step2(QList<QMap<int, QMap<int,int>*>*>* individualScoreList){
    QList<QList<int>*>* finalList = new QList<QList<int>*>();

    for(int i = 0 ; i < individualScoreList->size(); ++i){
        QList<int> keysList = (individualScoreList->at(i))->keys();
        int currStuID = keysList.at(0);

        QMap<int,int>* scores = (individualScoreList->at(i))->value(currStuID);
        QList<int> keysList2 = scores->keys();

        for(int z = 0 ; z < keysList2.size(); ++z){
            int comparedStuID = keysList2[z];
            int score1 = scores->take(comparedStuID);

            for(int y = 0 ; y < individualScoreList->size(); ++y){
                if((individualScoreList->at(y))->contains(comparedStuID)){
                    QMap<int,int>* scores2 = (individualScoreList->at(y))->value(comparedStuID);
                    int score2 = scores2->take(currStuID);
                    int average = ((float)(score1+score2)/2)*100;
                    QList<int>* finalScore = new QList<int>();
                    finalScore->append(currStuID);
                    finalScore->append(comparedStuID);
                    finalScore->append(average);
                    finalList->append(finalScore);
                }
            }

        }


    }
    return finalList;

}



QString AlgorithmManager::step3(QList<QMap<QString, int>*>* initialTeams, QList<QList<int>*>* finalList, QList<int>* listOfIds){
    QList<QList<int>*>* copyList = new QList<QList<int>*>();
    (*copyList)= (*finalList);

    QString details = "";

    for(int i = 0 ; i < initialTeams->size(); ++i){
        int size = ((initialTeams->at(i))->value("size"));
        int count = 0 ;

        float lowestAvrg = (float)copyList->at(0)->at(2) / 100;
        int s1 = copyList->at(0)->at(0);
        int s2 = copyList->at(0)->at(1);
        for(int z = 0 ; z < copyList->size(); ++z){
            if(((float)copyList->at(z)->at(2) / 100) < lowestAvrg){
                lowestAvrg = (float)copyList->at(z)->at(2) / 100;
                s1 = copyList->at(z)->at(0);
                s2 = copyList->at(z)->at(1);
            }
        }


        QList<int>* stusInTeam = new QList<int>();

        (initialTeams->at(i))->insert("s1",s1);
        (initialTeams->at(i))->insert("s2",s2);
        (initialTeams->at(i))->insert("avrg1",qFloor(lowestAvrg*100));
        count = 2;
        size -= 2;
        stusInTeam->append(s1);
        stusInTeam->append(s2);
        listOfIds->removeOne(s1);
        listOfIds->removeOne(s2);


        QMutableListIterator<QList<int>*> it((*copyList));
        while (it.hasNext()) {
            QList<int>* currElement = it.next();
            if (currElement->at(0) == s1 || currElement->at(1) == s1 || currElement->at(0) == s2  || currElement->at(1) == s2){
                it.remove();
                //qDebug() << "REMOVED";
            }
        }


        details += "\n\n\n\t\t    ------------------------------------------------------------------------------------------\n";
        details += "\t\t                                       TEAM "+QString::number(i+1)+" (Team size = "+QString::number((initialTeams->at(i))->value("size"))+")\n";
        details += "\t\t    ------------------------------------------------------------------------------------------\n\n";
        details += "\t\t    ------------------------------------------------------------------------------------------\n";
        details += "\t\t                                         FIRST 2 IN THE TEAM\n";
        details += "\t\t    ------------------------------------------------------------------------------------------\n";
        details += "\t\t    Student 1: " +  storage->getStudentProfile(s1)->getName() + "  \n\t\t    Student 2: " + storage->getStudentProfile(s2)->getName() + "  \n\t\t    Score: " + QString::number(lowestAvrg) + " <-- lowest score\n";
        details += "\t\t    Number of students in the team: " + QString::number(count) +"\n";
        details += "\t\t    ------------------------------------------------------------------------------------------\n";
        //details += "\t\t                                      List of IDs on this team\n";
        details += "\t\t                                   List of Students on this team\n";
        details += "\t\t    ------------------------------------------------------------------------------------------\n\t\t    ";
        for(int c = 0 ;c < stusInTeam->size(); ++c){
            details += storage->getStudentProfile(stusInTeam->at(c))->getName()+ "\n\t\t    ";
        }
        details += "------------------------------------------------------------------------------------------\n";

        qDebug() << "------------------------------------------------------------------------------------------";
        qDebug() << "                INSIDE STEP3";
        qDebug() << "------------------------------------------------------------------------------------------";
           qDebug() << "****FIRST 2 IN TEAM****";
           qDebug() << "Student 1:" << s1 << "  " << "Student 2:" << s2 << "Score:" << lowestAvrg << "count:" << count << "size:" << size ;
           qDebug() << "------------------------------------------------------------------------------------------";
           qDebug() << "                list of ids(not on a team)";
        for(int c = 0 ;c < listOfIds->size(); ++c){
            qDebug() << listOfIds->at(c);
        }
        qDebug() << "------------------------------------------------------------------------------------------";

        qDebug() << "                list of ids(ON THIS TEAM)";
        for(int c = 0 ;c < stusInTeam->size(); ++c){
             qDebug() << stusInTeam->at(c);
        }
        qDebug() << "------------------------------------------------------------------------------------------";
        /*
        qDebug() << "                final score list (MODIFIED) size: "<<copyList->size();
        for(int c = 0 ;c < copyList->size(); ++c){
             qDebug() << "Student 1:" << copyList->at(c)->at(0) << "  " << "Student 2:" << copyList->at(c)->at(1) << "Score:" << copyList->at(c)->at(2);
        }
        qDebug() << "------------------------------------------------------------------------------------------";
        qDebug() << "                final score list (ORIGINAL) size: "<<finalList->size();
        for(int c = 0 ;c < finalList->size(); ++c){
             qDebug() << "Student 1:" << finalList->at(c)->at(0) << "  " << "Student 2:" << finalList->at(c)->at(1) << "Score:" << finalList->at(c)->at(2);
        }
        qDebug() << "------------------------------------------------------------------------------------------";
        */
        while(size > 0 ){
            QList<QList<int>*>* candidateStus = new QList<QList<int>*>();
            for(int z = 0 ; z < listOfIds->size(); ++z){
                int candidateId = listOfIds->at(z);
                float sum = 0;
                for(int y = 0 ; y < stusInTeam->size(); ++y){
                    int idInTeam = stusInTeam->at(y);
                    for(int x = 0 ; x < finalList->size(); ++x){
                        if((finalList->at(x)->at(0) == idInTeam && finalList->at(x)->at(1) == candidateId )
                            ||
                           (finalList->at(x)->at(0) == candidateId && finalList->at(x)->at(1) == idInTeam )){
                            sum += (float)finalList->at(x)->at(2) / 100;
                            break;
                        }
                    }

                }
                float avrg = (float)sum / stusInTeam->size();
                QList<int>* oneStu = new QList<int>();
                oneStu->append(candidateId);
                oneStu->append(qFloor(avrg*100));
                candidateStus->append(oneStu);

            }
            details += "\n\t\t    ------------------------------------------------------------------------------------------\n";
            details += "\t\t                                 CHOOSING THE NEXT STUDENT\n";
            details += "\t\t    ------------------------------------------------------------------------------------------\n\n";
            details += "\t\t    ------------------------------------------------------------------------------------------\n";
            details += "\t\t                                    List of Candidate Students\n";
            details += "\t\t    ------------------------------------------------------------------------------------------\n";
            //QTextStream ss(&details);
            //ss << left << qSetFieldWidth(25) << "\t\t    Student ID: " << left << qSetFieldWidth(10) << " Score: " << endl;
            for(int c = 0 ;c < candidateStus->size(); ++c){
                 details += "\t\t       Student ID: " + storage->getStudentProfile(candidateStus->at(c)->at(0))->getName() + "        Score: " + QString::number((float)candidateStus->at(c)->at(1)/100) +"\n";
                 //details += QString("\t\t       Student ID: %1 Score: %2\n").arg(storage->getStudentProfile(candidateStus->at(c)->at(0))->getName(),6).arg(QString::number((float)candidateStus->at(c)->at(1)/100), 10);
                 //QTextStream ss(&details);
                 //ss << left << qSetFieldWidth(18) << "\t\t    Student ID: " << right << qSetFieldWidth(7) << " Score: " << endl;
                 //ss << left << qSetFieldWidth(18) << "\t\t    Student ID: " << storage->getStudentProfile(candidateStus->at(c)->at(0))->getName() << right << qSetFieldWidth(7) << " Score: " << QString::number((float)candidateStus->at(c)->at(1)/100) << endl;
                 //ss << left << qSetFieldWidth(25) << "\t\t    " << storage->getStudentProfile(candidateStus->at(c)->at(0))->getName() << left << qSetFieldWidth(10) << " " << QString::number((float)candidateStus->at(c)->at(1)/100) << endl;
                 //qDebug() << (qPrintable(details));
            }
            details += "\t\t    ------------------------------------------------------------------------------------------\n";
            qDebug() << "                candidate students";
            for(int c = 0 ;c < candidateStus->size(); ++c){
                 qDebug() << "Student ID:" << candidateStus->at(c)->at(0) << "Score:" << (float)candidateStus->at(c)->at(1)/100;
            }
            qDebug() << "------------------------------------------------------------------------------------------";

            float lowestAvrg2 = (float)candidateStus->at(0)->at(1) / 100;
            int s3 = candidateStus->at(0)->at(0);
            for(int z = 0 ; z < candidateStus->size(); ++z){
                if(((float)candidateStus->at(z)->at(1) / 100) < lowestAvrg2){
                    lowestAvrg2 = (float)candidateStus->at(z)->at(1) / 100;
                    s3 = candidateStus->at(z)->at(0);
                }
            }

            for(int z = 0 ; z < copyList->size(); ++z){
                if(copyList->at(z)->at(0) == s3 || copyList->at(z)->at(1) == s3 ){
                    copyList->removeAt(z);
                }
            }

            count += 1 ;
            (initialTeams->at(i))->insert("s"+QString::number(count),s3);
            (initialTeams->at(i))->insert("avrg"+QString::number(count),qFloor(lowestAvrg2*100));
            size -= 1;
            stusInTeam->append(s3);
            listOfIds->removeOne(s3);

            QMutableListIterator<QList<int>*> it((*copyList));
            while (it.hasNext()) {
                QList<int>* currElement = it.next();
                if (currElement->at(0) == s3 || currElement->at(1) == s3 ){
                    it.remove();
                    //qDebug() << "REMOVED 2";
                }
            }

            details += "\t\t    ------------------------------------------------------------------------------------------\n";
            details += "\t\t                                           CHOSEN STUDENT\n";
            details += "\t\t    ------------------------------------------------------------------------------------------\n";
            details += "\t\t    Student: " + storage->getStudentProfile(s3)->getName() + " \n\t\t    Score with the rest of the team: " + QString::number(lowestAvrg2) + " <-- lowest score\n";
            details += "\t\t    Number of students in the team: " + QString::number(count) +"\n";
            details += "\t\t    ------------------------------------------------------------------------------------------\n";
            details += "\t\t                           List of Students on the team (updated)\n";
            details += "\t\t    ------------------------------------------------------------------------------------------\n\t\t    ";
            for(int c = 0 ;c < stusInTeam->size(); ++c){
                 details += storage->getStudentProfile(stusInTeam->at(c))->getName()+"\n\t\t    ";
            }
            details += "------------------------------------------------------------------------------------------\n";
            qDebug() << "                CHOSEN STUDENT";
                 qDebug() << "Student ID:" << s3 << "Score:" << (float)lowestAvrg2 << "count:" << count << "size:" << size ;
            qDebug() << "------------------------------------------------------------------------------------------";

                 qDebug() << "                list of ids(ON THIS TEAM) UPDATED WITH NEW STUDENT";
                 for(int c = 0 ;c < stusInTeam->size(); ++c){
                      qDebug() << stusInTeam->at(c);
                 }
                 qDebug() << "------------------------------------------------------------------------------------------";
        }

    }

    return details;


}



QList<int>* AlgorithmManager::idList(QList<StudentProfile*>* studentsInProject){
    QList<int>* listOfIds = new QList<int>();

    for(int z = 0 ; z < studentsInProject->size(); ++z){
        listOfIds->append(studentsInProject->at(z)->getID());
    }

    return listOfIds;
}


/*
void AlgorithmManager::step3(QList<QMap<QString, int>*>* initialTeams, QList<QList<int>*>* finalList, QList<int>* listOfIds){
    QList<QList<int>*>* copyList = new QList<QList<int>*>();
    (*copyList)= (*finalList);

    //adding 2 students in every team
    for(int i = 0 ; i < initialTeams->size(); ++i){
        int size = ((initialTeams->at(i))->value("size"));
        int remaining = ((initialTeams->at(i))->value("remaining"));
        int count = 0 ;

        float lowestAvrg = (float)copyList->at(0)->at(2) / 100;
        int s1 = copyList->at(0)->at(0);
        int s2 = copyList->at(0)->at(1);
        for(int z = 0 ; z < copyList->size(); ++z){
            if(((float)copyList->at(z)->at(2) / 100) < lowestAvrg){
                lowestAvrg = (float)copyList->at(z)->at(2) / 100;
                s1 = copyList->at(z)->at(0);
                s2 = copyList->at(z)->at(1);
            }
        }
        qDebug() << "------------------------------------------------------------------------------------------";
        qDebug() << "------------------------------------------------------------------------------------------";
        qDebug() << "s1: " << s1 << "  s2: " << s2;

        QMutableListIterator<QList<int>*> it((*copyList));
        while (it.hasNext()) {
            QList<int>* currElement = it.next();
            if (currElement->at(0) == s1 || currElement->at(1) == s1 || currElement->at(0) == s2  || currElement->at(1) == s2){
                it.remove();
                qDebug() << "REMOVED";
            }
        }

        qDebug() << "                final score list (MODIFIED) size: "<<copyList->size();
        for(int c = 0 ;c < copyList->size(); ++c){
             qDebug() << "Student 1:" << copyList->at(c)->at(0) << "  " << "Student 2:" << copyList->at(c)->at(1) << "Score:" << (float)copyList->at(c)->at(2)/100;
        }
        qDebug() << "------------------------------------------------------------------------------------------";
        qDebug() << "------------------------------------------------------------------------------------------";
        QList<int>* stusInTeam = new QList<int>();

        (initialTeams->at(i))->insert("s1",s1);
        (initialTeams->at(i))->insert("s2",s2);
        (initialTeams->at(i))->insert("avrg1",qFloor(lowestAvrg*100));
        count = 2;
        size -= 2;
        stusInTeam->append(s1);
        stusInTeam->append(s2);
        listOfIds->removeOne(s1);
        listOfIds->removeOne(s2);
        remaining -=2;
        (initialTeams->at(i))->insert("remaining",remaining);
    }
    while(listOfIds->size() != 0){
        for(int i = 0 ; i < initialTeams->size(); ++i){
            int remaining = ((initialTeams->at(i))->value("remaining"));
            QList<int>* stusInTeam = new QList<int>();

            QList<QString> keysList = initialTeams->at(i)->keys();
            for(int z = 0; z < keysList.size() ; ++z){
               if(keysList.at(z).contains("s") && !keysList.at(z).contains("size")){
                    //qDebug() << keysList.at(z) <<": " << (initialTeams->at(i)->value(keysList.at(z)));
                    stusInTeam->append((initialTeams->at(i)->value(keysList.at(z))));
               }
            }
            int count = stusInTeam->size();

            if(remaining > 0 ){
                QList<QList<int>*>* candidateStus = new QList<QList<int>*>();
                for(int z = 0 ; z < listOfIds->size(); ++z){
                    int candidateId = listOfIds->at(z);
                    float sum = 0;
                    for(int y = 0 ; y < stusInTeam->size(); ++y){
                        int idInTeam = stusInTeam->at(y);
                        for(int x = 0 ; x < finalList->size(); ++x){
                            if((finalList->at(x)->at(0) == idInTeam && finalList->at(x)->at(1) == candidateId )
                                ||
                               (finalList->at(x)->at(0) == candidateId && finalList->at(x)->at(1) == idInTeam )){
                                sum += (float)finalList->at(x)->at(2) / 100;
                                break;
                            }
                        }

                    }
                    float avrg = (float)sum / stusInTeam->size();
                    QList<int>* oneStu = new QList<int>();
                    oneStu->append(candidateId);
                    oneStu->append(qFloor(avrg*100));
                    candidateStus->append(oneStu);

                }


                float lowestAvrg2 = (float)candidateStus->at(0)->at(1) / 100;
                int s3 = candidateStus->at(0)->at(0);
                for(int z = 0 ; z < candidateStus->size(); ++z){
                    if(((float)candidateStus->at(z)->at(1) / 100) < lowestAvrg2){
                        lowestAvrg2 = (float)candidateStus->at(z)->at(1) / 100;
                        s3 = candidateStus->at(z)->at(0);
                    }
                }

                for(int z = 0 ; z < copyList->size(); ++z){
                    if(copyList->at(z)->at(0) == s3 || copyList->at(z)->at(1) == s3 ){
                        copyList->removeAt(z);
                    }
                }

                count += 1 ;
                (initialTeams->at(i))->insert("s"+QString::number(count),s3);
                (initialTeams->at(i))->insert("avrg"+QString::number(count),qFloor(lowestAvrg2*100));
                //size -= 1;
                stusInTeam->append(s3);
                listOfIds->removeOne(s3);
                --remaining;
                (initialTeams->at(i))->insert("remaining",remaining);
                if(remaining == 0){
                    QList<float>* listOfTeamAverages = new QList<float>();

                    QList<QString> keysList = initialTeams->at(i)->keys();
                    for(int n = 0; n < keysList.size() ; ++n){
                       if(keysList.at(n).contains("avrg")){
                            listOfTeamAverages->append((float)(initialTeams->at(i)->value(keysList.at(n))) / 100);
                       }
                    }

                    float sum = 0;
                    for(int n = 0; n < listOfTeamAverages->size() ; ++n){
                        sum += listOfTeamAverages->at(n);
                    }
                    float totalavrg = (float)sum / listOfTeamAverages->size();
                    (initialTeams->at(i))->insert("totalavrg",qFloor(totalavrg*100));
                }

            }

        }
    }
        /*
        while(size > 0 ){
            QList<QList<int>*>* candidateStus = new QList<QList<int>*>();
            for(int z = 0 ; z < listOfIds->size(); ++z){
                int candidateId = listOfIds->at(z);
                float sum = 0;
                for(int y = 0 ; y < stusInTeam->size(); ++y){
                    int idInTeam = stusInTeam->at(y);
                    for(int x = 0 ; x < finalList->size(); ++x){
                        if((finalList->at(x)->at(0) == idInTeam && finalList->at(x)->at(1) == candidateId )
                            ||
                           (finalList->at(x)->at(0) == candidateId && finalList->at(x)->at(1) == idInTeam )){
                            sum += (float)finalList->at(x)->at(2) / 100;
                            break;
                        }
                    }

                }
                float avrg = (float)sum / stusInTeam->size();
                QList<int>* oneStu = new QList<int>();
                oneStu->append(candidateId);
                oneStu->append(qFloor(avrg*100));
                candidateStus->append(oneStu);

            }


            float lowestAvrg2 = (float)candidateStus->at(0)->at(1) / 100;
            int s3 = candidateStus->at(0)->at(0);
            for(int z = 0 ; z < candidateStus->size(); ++z){
                if(((float)candidateStus->at(z)->at(1) / 100) < lowestAvrg2){
                    lowestAvrg2 = (float)candidateStus->at(z)->at(1) / 100;
                    s3 = candidateStus->at(z)->at(0);
                }
            }

            for(int z = 0 ; z < copyList->size(); ++z){
                if(copyList->at(z)->at(0) == s3 || copyList->at(z)->at(1) == s3 ){
                    copyList->removeAt(z);
                }
            }

            count += 1 ;
            (initialTeams->at(i))->insert("s"+QString::number(count),s3);
            (initialTeams->at(i))->insert("avrg"+QString::number(count),qFloor(lowestAvrg2*100));
            size -= 1;
            stusInTeam->append(s3);
            listOfIds->removeOne(s3);

        }

    //}

    qDebug() << "------------------------------------------------------------------------------------------";
    qDebug() << "                list of ids(not on a team)";
    for(int c = 0 ;c < listOfIds->size(); ++c){
        qDebug() << listOfIds->at(c);
    }
    qDebug() << "------------------------------------------------------------------------------------------";

}*/


void AlgorithmManager::goToProject(){
    qDebug() << "algo 3";
    storage->goToProject(pid);
    qDebug() << "GO TO PROJECT";
}


void AlgorithmManager::goToSummary(){
    algoPage = new AlgorithmSummary();
    algoPage->setManager(this);
    //algoPage->setOutput(output);
    algoPage->setAllOutput(initialTeams2);

    mainWindow->setCentralWidget(algoPage);
}



void AlgorithmManager::goToDetails(){
    DetailedResults* detailedPage = new DetailedResults();
    detailedPage->setManager(this);
    detailedPage->setOutput(output);
    mainWindow->setCentralWidget(detailedPage);

}
