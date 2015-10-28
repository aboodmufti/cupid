#include "storage.h"
#include <QList>

Storage::Storage()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/Desktop/project_files/cupid_DB.db");

    bool db_ok = db.open();

    query = new QSqlQuery(db);
}

Project* Storage::getProjectById(int id){
    query->exec("select * from Project where P_ID = "+id+" ;");
    Project *project = new Project();

    while (query->next()) {
        project->setID(query->value(0).toInt());
        project->setName(query->value(1).toString());
        project->setMaxTeamSize(query->value(2).toInt());
        project->setMinTeamSize(query->value(3).toInt());
        project->setDescription(query->value(4).toString());
        project->setStatus(query->value(5).toString());
        //qDebug() << "id: " << id << "name: " << name << "own: " << own << "partner: " << partner;
    }

    return project;
}

bool Storage::updateProject(Project* project){
    int id = project->getID();
    QString name = project->getName();
    QString maxTeamSize = project->getMaxTeamSize();
    QString minTeamSize = project->getMinTeamSize();
    QString description = project->getDescription();
    QString status = project->getStatus();

    return query->exec("UPDATE Project SET P_NAME = '"+name+"', P_TEAM_SIZE_MAX ="+ maxTeamSize+", "+
                       "P_TEAM_SIZE_MIN ="+ minTeamSize + ", P_DESCRIPTION ='"+ description+ "',P_STATUS = '"+status+
                       "' WHERE P_ID = "+id+" ;");

}

bool Storage::publishProject(int id ){
    return query->exec("UPDATE Project SET P_STATUS= PUBLISHED WHERE P_ID = "+id+" ;");
}

StudentProfile* Storage::getStudentProfile(int id){
    query->exec("select * from Student where S_ID = "+id+" ;");
    StudentProfile *stu = new StudentProfile();

    query->next();

    stu->setID(query->value(0).toInt());
    stu->setName(query->value(1).toString());
    stu->setUsername(query->value(2).toString());

    int ownQID = query->value(3).toInt();
    int partnerQID = query->value(4).toInt();

    QList<int> ownQ = getQualifications(ownQID);
    QList<int> partnerQ = getQualifications(partnerQID);

    stu->setOwnQ(ownQ);
    stu->setPartnerQ(partnerQ);

    return stu;
}

// inside getStudentProfile()
QList<int>* Storage::getQualifications(int id){
    QSqlQuery *query4 = new QSqlQuery(db);

    query4->exec("select * from Qualifications where Q_ID = "+id+" ;");
    QList<int> qualifications = new QList<int>();

    while (query4->next()) {
        for(int i=0; i<14 ; ++i){
            qualifications[i] = query4->value(i).toInt();
        }
    }

    return qualifications;
}

QList<QList<QString>*> Storage::getStudentProjects(int studentID){
    query->exec("select P_ID, P_NAME from Projects where P_STATUS = 'PUBLISHED';");
    QList<Project> projects ;

    while (query->next()) {
        QList<QString> project = new QList<QString>();
        project[0] = query->value(0).toString();
        project[1] = query->value(1).toString();
        bool joined = StudentJoinedProject(query->value(0).toInt(),studentID);
        if(joined){
            project[2] = "TRUE";
        }else{
            project[2] = "FALSE";
        }
        projects += project;
    }

    return projects;
}

bool Storage::StudentJoinedProject(int projectId,int studentID){
    QSqlQuery *query2 = new QSqlQuery(db);

    query2->exec("select * from Project_Student where P_ID = "+projectId+" AND S_ID = "+studentID+" ;");

    if(query2->next()){
        return true;
    }

    return false;
}

bool Storage::updateStudentProfile(StudentProfile* stu){
    int id = stu->getID();
    QString name = stu->getName();
    QString username = stu->getUsername();
    QList<int> ownQ = stu->getOwnQ();
    QList<int> partnerQ = stu->getPartnerQ();

    updateQualifications(ownQ);
    updateQualifications(partnerQ);

    return query->exec("UPDATE Project SET "+
                       " S_NAME = '"+name+"' "+
                       ", S_USERNAME = '"+username+"' " +
                       " WHERE P_ID = "+id+" ;");

}

bool Storage::updateQualifications(QList<int>* list){
    QSqlQuery *query3 = new QSqlQuery(db);

    int Q_ID = list[0];
    int GRADE_2404  = list[1];
    int GRADE_2402 = list[2];
    int PUNCTUALITY = list[3];
    int TECHNICALITY = list[4];
    int GROUP_WORK = list[5];
    int WORK_HOURS  = list[6];
    int FLEXIBILITY  = list[7];
    int GRADE_GOAL = list[8];
    int MEETING_TOPICS = list[9];
    int LEADERSHIP = list[10];
    int WEEKEND  = list[11];
    int COURSE_LOAD  = list[12];
    int PROJECTS  = list[13];

    return query3->exec("UPDATE Qualifications SET"+
                 " GRADE_2404 ="+ GRADE_2404 +
                 ", GRADE_2402 ="+ GRADE_2402 +
                 ", PUNCTUALITY ="+PUNCTUALITY +
                 ", TECHNICALITY="+TECHNICALITY +
                 ", GROUP_WORK="+ GROUP_WORK +
                 ", WORK_HOURS="+ WORK_HOURS +
                 ", FLEXIBILITY="+ FLEXIBILITY +
                 ", GRADE_GOAL="+ GRADE_GOAL +
                 ", MEETING_TOPICS="+ MEETING_TOPICS +
                 ", LEADERSHIP="+ LEADERSHIP +
                 ", WEEKEND="+ WEEKEND +
                 ", COURSE_LOAD="+ COURSE_LOAD +
                 ", PROJECTS="+ PROJECTS +
                 " WHERE Q_ID = "+Q_ID+" ;");

}
