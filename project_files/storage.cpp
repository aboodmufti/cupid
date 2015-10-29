#include "storage.h"
#include "Student.h"
#include "StudentProfile.h"
#include "Administrator.h"
#include <QString>

Storage::Storage()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/Desktop/cupid/project_files/cupid_DB.db");
    qDebug() << "/home/student/Desktop/project_files/cupid_DB.db";

    *query = new QSqlQuery(db);

}

bool Storage::insertProject(Project *proj)
{
    bool exec_ok = query->exec("INSERT INTO Project (P_NAME, P_TEAM_SIZE_MAX, " +
                               "P_TEAM_SIZE_MIN, P_DESCRIPTION, P_STATUS) VALUES " +
                               "('"+ proj->getName() +"', '"+ proj->getMaxTeamSize() +"', +
                               "'"+ proj->getMinTeamSize() +"', '"+ proj->getDescription() +"', " +
                               "'"+ proj->getStatus() +"' );");

    if(exec_ok == true)
        query->exec("select * from Project;");
    else
        qDebug() << "Error: INSERT | " << query->lastError().text();

    return exec_ok;
}

bool Storage::insertAdministrator(Administrator *admin)
{
    bool exec_ok = query->exec("INSERT INTO Admin (A_USERNAME) VALUES ('"+ admin->getUsername() +"');");

    if(exec_ok == true)
        query->exec("select * from Admin;");
    else
        qDebug() << "Error: INSERT | " << query->lastError().text();

    return exec_ok;
}

bool Storage::insertStudent(StudentProfile *stuProfile)
{
    int stuOwnQ = insertQualifications(stuProfile->getOwnQualifications());
    int stuPartnerQ = insertQualifications(stuProfile->getPartnerQualifications());

    bool exec_ok = query->exec("INSERT INTO Student (S_ID, S_NAME, S_USERNAME, " +
                               "S_Own_Q, S_PARTNER_Q) VALUES ("+stuProfile->getID()+", " +
                               "'"+stuProfile->getName()+"', '"+stuProfile->getUsername()+"', " +
                               ""+stuOwnQ+", "+stuPartnerQ+");");

    if(exec_ok == true)
        query->exec("select * from Student;");
    else
        qDebug() << "Error: INSERT | " << query->lastError().text();

    return exec_ok;
}

int Storage::insertQualifications(QList<int> *qualifications)
{
    int Q_ID = qualifications[0];
    int GRADE_2404 = qualifications[1];
    int GRADE_2402 = qualifications[2];
    int PUNCTUALITY = qualifications[3];
    int TECHNICALITY = qualifications[4];
    int GROUP_WORK = qualifications[5];
    int WORK_HOURS = qualifications[6];
    int FLEXIBILITY = qualifications[7];
    int GRADE_GOAL = qualifications[8];
    int MEETING_TOPICS = qualifications[9];
    int LEADERSHIP = qualifications[10];
    int WEEKEND = qualifications[11];
    int COURSE_LOAD = qualifications[12];
    int PROJECTS = qualifications[13];

    QSqlQuery *query2 = new QSqlQuery(db);

    bool exec_ok = query2->exec("INSERT INTO Qualifications" +
                               "(Q_ID, GRADE_2404, GRADE_2402, PUNCTUALITY," +
                               "TECHNICALITY, GROUP_WORK, WORK_HOURS, " +
                               "FLEXIBILITY, GRADE_GOAL, MEETING_TOPICS, " +
                               "LEADERSHIP, WEEKEND, COURSE_LOAD, PROJECTS) " +
                               "VALUES ("+Q_ID+", "+GRADE_2404+", "+GRADE_2402+", "+PUNCTUALITY+", " +
                               ""+TECHNICALITY+", "+GROUP_WORK+", "+WORK_HOURS+", "+
                               ""+FLEXIBILITY+", "+GRADE_GOAL+", "+MEETING_TOPICS+", " +
                               ""+LEADERSHIP+", "+WEEKEND+", "+COURSE_LOAD+", "+PROJECTS+");");

    if(exec_ok == true)
        query->exec("select * from Qualifications;");
    else
        qDebug() << "Error: INSERT | " << query->lastError().text();

    return Q_ID;
}

bool Storage::addStudentProject(int projId, int stuId)
{
    bool exec_ok = query->exec("INSERT INTO Project_Student (P_ID, S_ID) " +
                               "VALUES ("+projId+", "+stuId+");");

    if(exec_ok == true)
        query->exec("select * from Project_Student;");
    else
        qDebug() << "Error: INSERT | " << query->lastError().text();

    return exec_ok;
}

bool Storage::addAdminProject(int projId, QString adminUsername)
{
    bool exec_ok = query->exec("INSERT INTO Admin_Project (P_ID, A_USERNAME) " +
                               "VALUES ("+projId+", '"+adminUsername+"');");

    if(exec_ok == true)
        query->exec("select * from Admin_Project;");
    else
        qDebug() << "Error: INSERT | " << query->lastError().text();

    return exec_ok;
}

Administrator* Storage::getAdminByUsername(QString adminUsername)
{
    Administrator *admin = new Administrator();
    query->exec("select * from Admin where A_USERNAME = "+adminUsername+";");

    //query->next();
    admin->setUsername(query->value(0).toString());

    return admin;
}

QList<Project*> Storage::getAllProjects()
{
    Project *project = new Project();
    QList<Project*> listOfProjects = new QList<Project*>;
    query->exec("select * from Project;");

    while(query->next())
    {
        project->setID(query->value(0).toInt());
        project->setName(query->value(1).toString());
        project->setMaxTeamSize(query->value(2).toInt());
        project->setMinTeamSize(query->value(3).toInt());
        project->setDescription(query->value(4).toString());
        project->setStatus(query->value(5).toString());

        listOfProjects += project;
    }

    return listOfProjects;
}
