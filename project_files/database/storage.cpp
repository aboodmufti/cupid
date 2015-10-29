#include "storage.h"
#include <QList>

Storage::Storage()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./cupid_DB.db");                            //FIX

    bool db_ok = db.open();

    query = new QSqlQuery(db);
}



bool Storage::insertProject(Project *proj)
{
    bool exec_ok = query->exec("INSERT INTO Project (P_NAME, P_TEAM_SIZE_MAX, "
                               "P_TEAM_SIZE_MIN, P_DESCRIPTION, P_STATUS) VALUES "
                               "('"+ proj->getName() +"', '"+ proj->getMaxTeamSize() +"', "
                               "'"+ proj->getMinTeamSize() +"', '"+ proj->getDescription() +"', "
                               "'"+ proj->getStatus() +"' );");


    return exec_ok;
}

bool Storage::insertAdministrator(Administrator *admin)
{
    bool exec_ok = query->exec("INSERT INTO Admin (A_USERNAME) VALUES ('"+ admin->getUsername() +"');");

    return exec_ok;
}

bool Storage::insertStudent(StudentProfile *stuProfile)
{
    int stuOwnQ = insertQualifications(stuProfile->getOwnQ());
    int stuPartnerQ = insertQualifications(stuProfile->getPartnerQ());

    query->prepare("INSERT INTO Student (S_ID, S_NAME, S_USERNAME, S_Own_Q, S_PARTNER_Q) VALUES (:id, :name, :username, :ownQ, :partnerQ );");
    //("+stuProfile->getID() +", '"+stuProfile->getName()+"', '"+stuProfile->getUsername()+"', "+stuOwnQ+", "+stuPartnerQ+")
    query->bindValue(":id",stuProfile->getID());
    query->bindValue(":name",stuProfile->getName());
    query->bindValue(":username",stuProfile->getUsername());
    query->bindValue(":ownQ",stuOwnQ);
    query->bindValue(":partnerQ",stuPartnerQ);
    bool exec_ok = query->exec();


    return exec_ok;
}

int Storage::insertQualifications(QList<int> *qualifications)
{
    int GRADE_2404 = (*(qualifications))[1];
    int GRADE_2402 = (*(qualifications))[2];
    int PUNCTUALITY = (*(qualifications))[3];
    int TECHNICALITY = (*(qualifications))[4];
    int GROUP_WORK = (*(qualifications))[5];
    int WORK_HOURS = (*(qualifications))[6];
    int FLEXIBILITY = (*(qualifications))[7];
    int GRADE_GOAL = (*(qualifications))[8];
    int MEETING_TOPICS = (*(qualifications))[9];
    int LEADERSHIP = (*(qualifications))[10];
    int WEEKEND = (*(qualifications))[11];
    int COURSE_LOAD = (*(qualifications))[12];
    int PROJECTS = (*(qualifications))[13];

    QSqlQuery *query2 = new QSqlQuery(db);

    /*
    bool exec_ok = query2->exec("INSERT INTO Qualifications"
                               "(GRADE_2404, GRADE_2402, PUNCTUALITY,"
                               "TECHNICALITY, GROUP_WORK, WORK_HOURS, "
                               "FLEXIBILITY, GRADE_GOAL, MEETING_TOPICS, "
                               "LEADERSHIP, WEEKEND, COURSE_LOAD, PROJECTS) "
                               "VALUES ("+ GRADE_2404 +", "+ GRADE_2402 +", "+ PUNCTUALITY +", "
                               " "+ TECHNICALITY +", "+ GROUP_WORK +", "+ WORK_HOURS +", "
                               " "+ FLEXIBILITY +", "+ GRADE_GOAL +", "+ MEETING_TOPICS +", "
                               " "+ LEADERSHIP +", "+ WEEKEND +", "+ COURSE_LOAD +", "+ PROJECTS +");");
    */

    query2->prepare("INSERT INTO Qualifications (GRADE_2404, GRADE_2402, PUNCTUALITY, TECHNICALITY, GROUP_WORK, WORK_HOURS, FLEXIBILITY, GRADE_GOAL, MEETING_TOPICS,  LEADERSHIP, WEEKEND, COURSE_LOAD, PROJECTS) "
                   " VALUES(:grade2404, :grade2042, :punctuality, :technicality, :groupWork, :workHours, :flexibility, :gradeGoal, :meetingTopics, :leadership, :weekend, :courseLoad, :projects)");
    query2->bindValue("grade2404", GRADE_2404);
    query2->bindValue("grade2042", GRADE_2402);
    query2->bindValue("punctuality", PUNCTUALITY);
    query2->bindValue("technicality", TECHNICALITY);
    query2->bindValue("groupWork", GROUP_WORK);
    query2->bindValue("workHours", WORK_HOURS);
    query2->bindValue("flexibility", FLEXIBILITY);
    query2->bindValue("gradeGoal", GRADE_GOAL);
    query2->bindValue("meetingTopics", MEETING_TOPICS);
    query2->bindValue("leadership",LEADERSHIP );
    query2->bindValue("weekend", WEEKEND);
    query2->bindValue("courseLoad", COURSE_LOAD);
    query2->bindValue("projects", PROJECTS);
    query2->exec();
    return query2->lastInsertId().toInt();
}

bool Storage::addStudentProject(int projId, int stuId)
{
    bool exec_ok = query->exec("INSERT INTO Project_Student (P_ID, S_ID) VALUES ('"+ projId +"', '"+ stuId +"');");
    query->prepare("INSERT INTO Project_Student (P_ID, S_ID) VALUES (:pid, :sid);");
    query->bindValue();

    return exec_ok;
}

bool Storage::addAdminProject(int projId, QString adminUsername)
{

    bool exec_ok = query->exec("INSERT INTO Admin_Project (P_ID, A_USERNAME) "
                               "VALUES (" + projId + " , '" + adminUsername + "');");


    return exec_ok;
}

Administrator* Storage::getAdminByUsername(QString adminUsername)
{
    Administrator *admin = new Administrator();
    query->exec("select * from Admin where A_USERNAME = "+adminUsername+";");

    query->next();
    admin->setUsername(query->value(0).toString());

    return admin;
}

QList<Project*>* Storage::getAllProjects()
{

    QList<Project*>* listOfProjects = new QList<Project*>();
    query->exec("select * from Project;");

    while(query->next())
    {
        Project *project = new Project();
        project->setID(query->value(0).toInt());
        project->setName(query->value(1).toString());
        project->setMaxTeamSize(query->value(2).toInt());
        project->setMinTeamSize(query->value(3).toInt());
        project->setDescription(query->value(4).toString());
        project->setStatus(query->value(5).toString());

        (*listOfProjects) += project;
    }

    return listOfProjects;
}



Project* Storage::getProjectById(int id){
    query->exec("select * from Project where P_ID = "+id+" ;");
    Project *project = new Project();

    query->next();

    project->setID(query->value(0).toInt());
    project->setName(query->value(1).toString());
    project->setMaxTeamSize(query->value(2).toInt());
    project->setMinTeamSize(query->value(3).toInt());
    project->setDescription(query->value(4).toString());
    project->setStatus(query->value(5).toString());


    return project;
}

bool Storage::updateProject(Project* project){

    int id = project->getID();
    QString name = project->getName();
    int maxTeamSize = project->getMaxTeamSize();
    int minTeamSize = project->getMinTeamSize();
    QString description = project->getDescription();
    QString status = project->getStatus();

    return query->exec("UPDATE Project SET P_NAME = '"+name+"', P_TEAM_SIZE_MAX ="+ maxTeamSize+", "
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

    QList<int>* ownQ = getQualifications(ownQID);
    QList<int>* partnerQ = getQualifications(partnerQID);

    stu->setOwnQ(ownQ);
    stu->setPartnerQ(partnerQ);

    return stu;
}

// inside getStudentProfile()
QList<int>* Storage::getQualifications(int id){
    QSqlQuery *query4 = new QSqlQuery(db);

    query4->exec("select * from Qualifications where Q_ID = "+id+" ;");
    QList<int>* qualifications = new QList<int>();

    query4->next();

    for(int i=0; i<14 ; ++i){
        (*(qualifications))[i] = query4->value(i).toInt();
    }


    return qualifications;
}

QList<QList<QString>*>* Storage::getStudentProjects(int studentID){

    query->exec("select P_ID, P_NAME from Projects where P_STATUS = 'PUBLISHED';");
    QList<QList<QString>*>* projects = new QList<QList<QString>*>;

    while (query->next()) {
        QList<QString>* project = new QList<QString>();
        (*(project))[0] = query->value(0).toString();
        (*(project))[1] = query->value(1).toString();
        bool joined = studentJoinedProject(query->value(0).toInt(),studentID);
        if(joined){
            (*(project))[2] = "TRUE";
        }else{
            (*(project))[2] = "FALSE";
        }
        (*projects) += project;
    }

    return projects;
}

bool Storage::studentJoinedProject(int projectId,int studentID){
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
    QList<int>* ownQ = stu->getOwnQ();
    QList<int>* partnerQ = stu->getPartnerQ();

    updateQualifications(ownQ);
    updateQualifications(partnerQ);

    return query->exec("UPDATE Project SET "
                       " S_NAME = '"+name+"' "
                       ", S_USERNAME = '"+username+"' "
                       " WHERE P_ID = "+id+" ;");

}

bool Storage::updateQualifications(QList<int>* list){
    QSqlQuery *query3 = new QSqlQuery(db);

    int Q_ID = (*(list))[0];
    int GRADE_2404  = (*(list))[1];
    int GRADE_2402 = (*(list))[2];
    int PUNCTUALITY = (*(list))[3];
    int TECHNICALITY = (*(list))[4];
    int GROUP_WORK = (*(list))[5];
    int WORK_HOURS  = (*(list))[6];
    int FLEXIBILITY  = (*(list))[7];
    int GRADE_GOAL = (*(list))[8];
    int MEETING_TOPICS = (*(list))[9];
    int LEADERSHIP = (*(list))[10];
    int WEEKEND  = (*(list))[11];
    int COURSE_LOAD  = (*(list))[12];
    int PROJECTS  = (*(list))[13];

    return query3->exec("UPDATE Qualifications SET"
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



StudentProfile* Storage::getStudentByUsername(QString username)
{
    query->exec("SELECT * FROM Student WHERE S_USERNAME = '"+username+"';");

    StudentProfile *s = new StudentProfile();

    query->next();
    s->setID(query->value(0).toInt());
    s->setName(query->value(1).toString());
    s->setUsername(query->value(2).toString());

    int ownQ = query->value(3).toInt();
    int partnerQ = query->value(4).toInt();

    QList<int>* oQ = getQualifications(ownQ);
    QList<int>* pQ = getQualifications(partnerQ);

    s->setOwnQ(oQ);
    s->setPartnerQ(pQ);

   return s;
}

bool Storage::setUpProjectTable()
{
    return query->exec("create table if not exists Project (P_ID INTEGER PRIMARY KEY AUTOINCREMENT, P_NAME varchar(96), P_TEAM_SIZE_MIN INT, P_TEAM_SIZE_MAX INT, P_DESCRIPTION varchar(500), P_STATUS varchar(50));");
}

bool Storage::setUpStudentTable()
{
    return query->exec("create table if not exists Student (S_ID INTEGER PRIMARY KEY, S_NAME varchar(96), S_USERNAME varchar(64), S_OWN_Q INTEGER, S_PARTNER_Q INTEGER);");
}

bool Storage::setUpQualificationsTable()
{
    return query->exec("create table if not exists Qualifications (Q_ID INTEGER PRIMARY KEY AUTOINCREMENT, GRADE_2404 INT, GRADE_2402 INT, PUNCTUALITY INT, TECHNICALITY INT, GROUP_WORK INT, WORK_HOURS INT, FLEXIBILITY INT, GRADE_GOAL INT, MEETING_TOPICS INT, LEADERSHIP INT, WEEKEND INT, COURSE_LOAD INT, PROJECTS INT);");
}

bool Storage::setUpProjectStudentTable()
{
    return query->exec("create table if not exists Project_Student (P_ID INTEGER, S_ID INTEGER, FOREIGN KEY (P_ID) REFERENCES Project(P_ID), FOREIGN KEY (S_ID) REFERENCES Student(S_ID));");
}

bool Storage::setUpAdministratorTable()
{
    return query->exec("create table if not exists Admin (A_USERNAME varchar(96) PRIMARY KEY );");
}

bool Storage::setUpAdminProjectTable()
{
    return query->exec("create table if not exists Admin_Project (P_ID INTEGER, A_USERNAME varchar(96), FOREIGN KEY (P_ID) REFERENCES Project(P_ID), FOREIGN KEY (A_USERNAME) REFERENCES Admin(A_USERNAME));");
}

StudentProfile* Storage::getStudentsInProject(int pid)
{
  query->exec("SELECT * FROM (SELECT S_ID FROM Project_Student WHERE P_ID = "+ pid +") NATURAL JOIN (SELECT * FROM Student);");
  StudentProfile *s = new StudentProfile();
  while(query->next()){
    s->setID(query->value(0).toInt());
    s->setName(query->value(1).toString());
    s->setUsername(query->value(2).toString());

    int ownQ = query->value(3).toInt();
    int partnerQ = query->value(4).toInt();

    QList<int>* oQ = getQualifications(ownQ);
    QList<int>* pQ = getQualifications(partnerQ);

    s->setOwnQ(oQ);
    s->setPartnerQ(pQ);
  }

  return s;
}
