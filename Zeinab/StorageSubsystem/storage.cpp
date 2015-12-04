#include "storage.h"
#include <QList>
#include <unistd.h>

Storage::Storage()
{
    QString test = __FILE__;
    QString test2 = test.left(test.length() - 11);
    QString final_path = test2.append("cupid_DB.db");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(final_path);

    db.open();

    query = new QSqlQuery(db);
}

// Student Profile
void Storage::createStudentProfile(){
    stuProfile = new StudentProfile();
}

StudentProfile* createNewStudentProfile(){
    StudentProfile* profile = new StudentProfile();
    return profile;
}

StudentProfile* Storage::getStudentProfile(){
	return stuProfile;
}

int Storage::getProfileID(){
	return stuProfile->getID();
}
QString Storage::getProfileName(){
	return stuProfile->getName();
}

QList<int>* Storage::getOwnQ(){
	return stuProfile->getOwnQ();
}

QList<int>* Storage::getPartnerQ(){
	return stuProfile->getPartnerQ();
}

//Qlist<Team*> Storage::getTeams();
QList<Project*> Storage::getProjects(){
	return stuProfile->getProjects();
}
void Storage::setUsername(QString n){
    stuProfile->setUsername(n);
}
void Storage::setProfileName(QString n){
	stuProfile->setName(n);
}

void Storage::setProfileID(int id){
	stuProfile->setID(id);
}
void Storage::setOwnQ(QList<int>* list){
	stuProfile->setOwnQ(list);
}
void  Storage::setPartnerQ(QList<int>* list){
    stuProfile->setPartnerQ(list);;
}

//void Storage::setTeams(Team*);
void Storage::addProject(Project* pro){
	stuProfile->addProject(pro);
}

void Storage::setProjects(QList<Project*> pro){
    stuProfile->setProjects(pro);
}
void Storage::setStudentProfile(StudentProfile* profile){
	stuProfile = profile;
}	

//Student functions
void Storage::createStudent(){
    stu = new Student();
}

Student* Storage::createNewStudent(){
	Student* s = new Student();
	return s;
}
Student* Storage::getStudent(){
	return stu;
}
void Storage::setStudent(Student* s){
	stu = s;
}

void Storage::setOwnProfile(StudentProfile* stuPro){
    stu->setStudentProfile(stuPro);
}

StudentProfile* Storage::getOwnProfile(){
    return stu->getStudentProfile();
}


//Admin functions

void Storage::createAdministrator(){
    admin = new Administrator();
}

Administrator* Storage::getAdministrator(){
	return admin;
}
void Storage::setAdministrator(Administrator* a){
	admin = a;
}
void Storage::addNewProject(Project* pro){
	admin->addProject(pro);
}

//Project functions
Project* Storage::getProject(){
	return project;
}

void Storage::createProject(){
    project = new Project();
}

Project* Storage::createNewProject(){
	Project* pro = new Project();
	return pro;
}
int Storage::getProjectID(){
	return project->getID();
}
QString Storage::getProjectName(){
	return project->getName();
}
int Storage::getMinTeamSize(){
	return project->getMinTeamSize();
}
int Storage::getMaxTeamSize(){
	return project->getMaxTeamSize();
}
QString Storage::getDescription(){
	return project->getDescription();
}
QString Storage::getStatus(){
	return project->getStatus();
}
void Storage::setProject(Project* pro){
	project = pro;
}
void Storage::setProjectID(int id){
	project->setID(id);
}
void Storage::setProjectName(QString n){
	project->setName(n);
}
void Storage::setMinTeamSize(int min){
	project->setMinTeamSize(min);
}
void Storage::setMaxTeamSize(int max){
	project->setMaxTeamSize(max);
}
void Storage::setDescription(QString desc){
	project->setDescription(desc);
}
void Storage::setStatus(QString s){
	project->setStatus(s);
}

//Team functions
void Storage::setTeam(Team* t){
	team = t;
}
Team* Storage::getTeam(){
	return team;
}
Team* Storage::createTeam(){
	Team* t = new Team();
	return t;
}
void Storage::setTeamName(QString n){
	team->setTeamName(n);
}
QString	Storage::getTeamName(){
	return team->getTeamName();
}
void Storage::setSize(int s){
	team->setSize(s);
}
int	Storage::getSize(){
	return team->getSize();
}
void Storage::setStudentIds(QList<int> stu){
	team->setStudentIds(stu);
}
QList<int> Storage::getStudentIds(){
	return team->getStudentIds();
}
void Storage::setTeamInfo(QString info){
	team->setTeamInfo(info);
}
QString Storage::getTeamInfo(){
	return team->getTeamInfo();
}
bool Storage::addStudent(int id){
    return team->addStudent(id);
}
void Storage::removeStudent(int id){
    return team->removeStudent(id);
}


QSqlQuery* Storage::getQueryObject()
{
    return query;
}

int Storage::insertProject(Project *proj)
{
   /* bool exec_ok = query->exec("INSERT INTO Project (P_NAME, P_TEAM_SIZE_MAX, "
                               "P_TEAM_SIZE_MIN, P_DESCRIPTION, P_STATUS) VALUES "
                               "('"+ proj->getName() +"', "+ proj->getMaxTeamSize() +", "
                               ""+ proj->getMinTeamSize() +", '"+ proj->getDescription() +"', "
                               "'"+ proj->getStatus() +"' );");
                               */
    query->prepare("INSERT INTO Project (P_NAME, P_TEAM_SIZE_MAX, P_TEAM_SIZE_MIN, P_DESCRIPTION, P_STATUS) VALUES (:name, :maxTeamSize, :minTeamSize, :description, :status);");
    query->bindValue(":name", proj->getName());
    query->bindValue(":maxTeamSize", proj->getMaxTeamSize());
    query->bindValue(":minTeamSize", proj->getMinTeamSize());
    query->bindValue(":description", proj->getDescription());
    query->bindValue(":status", proj->getStatus());

    query->exec();
    return query->lastInsertId().toInt();
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
    query2->bindValue(":grade2404", GRADE_2404);
    query2->bindValue(":grade2042", GRADE_2402);
    query2->bindValue(":punctuality", PUNCTUALITY);
    query2->bindValue(":technicality", TECHNICALITY);
    query2->bindValue(":groupWork", GROUP_WORK);
    query2->bindValue(":workHours", WORK_HOURS);
    query2->bindValue(":flexibility", FLEXIBILITY);
    query2->bindValue(":gradeGoal", GRADE_GOAL);
    query2->bindValue(":meetingTopics", MEETING_TOPICS);
    query2->bindValue(":leadership",LEADERSHIP );
    query2->bindValue(":weekend", WEEKEND);
    query2->bindValue(":courseLoad", COURSE_LOAD);
    query2->bindValue(":projects", PROJECTS);
    query2->exec();
    return query2->lastInsertId().toInt();
}

bool Storage::addStudentProject(int projId, int stuId)
{
    //bool exec_ok = query->exec("INSERT INTO Project_Student (P_ID, S_ID) VALUES ('"+ projId +"', '"+ stuId +"');");
    query->prepare("INSERT INTO Project_Student (P_ID, S_ID) VALUES (:pid, :sid);");
    query->bindValue(":pid", projId);
    query->bindValue(":sid", stuId);
    return query->exec();
}

bool Storage::addAdminProject(int projId, QString adminUsername)
{
    /*
    bool exec_ok = query->exec("INSERT INTO Admin_Project (P_ID, A_USERNAME) "
                               "VALUES (" + projId + " , '" + adminUsername + "');");
    */
    query->prepare("INSERT INTO Admin_Project (P_ID, A_USERNAME) VALUES (:pid, :aUsername);");
    query->bindValue(":pid", projId);
    query->bindValue(":aUsername", adminUsername);

    return query->exec();
}

Administrator* Storage::getAdminByUsername(QString adminUsername)
{
    Administrator *admin = new Administrator();
    query->exec("select * from Admin where A_USERNAME = '"+adminUsername+"';");

    if(query->first()){
            admin->setUsername(query->value(0).toString());
    }
    return admin;
}

QList<Project*>* Storage::getAllProjects()
{

    QList<Project*>* listOfProjects = new QList<Project*>();
    query->exec("select * from Project;");

    if(query->first()){
        do{
            Project *project = new Project();
            project->setID(query->value(0).toInt());
            project->setName(query->value(1).toString());
            project->setMaxTeamSize(query->value(2).toInt());
            project->setMinTeamSize(query->value(3).toInt());
            project->setDescription(query->value(4).toString());
            project->setStatus(query->value(5).toString());

            (*listOfProjects) += project;
        }while(query->next());
    }
    return listOfProjects;
}



Project* Storage::getProjectById(int id){
    //query->exec("select * from Project where P_ID = "+id+" ;");
    query->prepare("select * from Project where P_ID = :pid ;");
    query->bindValue(":pid", id);
    query->exec();
    Project *project = new Project();

    if(query->first()){

        project->setID(query->value(0).toInt());
        project->setName(query->value(1).toString());
        project->setMaxTeamSize(query->value(3).toInt());
        project->setMinTeamSize(query->value(2).toInt());
        project->setDescription(query->value(4).toString());
        project->setStatus(query->value(5).toString());
    }

    return project;
}

bool Storage::updateProject(Project* project){

    int id = project->getID();
    QString name = project->getName();
    int maxTeamSize = project->getMaxTeamSize();
    int minTeamSize = project->getMinTeamSize();
    QString description = project->getDescription();
    QString status = project->getStatus();

    /*return query->exec("UPDATE Project SET P_NAME = '"+name+"', P_TEAM_SIZE_MAX ="+ maxTeamSize+", "
                       "P_TEAM_SIZE_MIN ="+ minTeamSize + ", P_DESCRIPTION ='"+ description+ "',P_STATUS = '"+status+
                       "' WHERE P_ID = "+id+" ;");*/
    query->prepare("UPDATE Project SET P_NAME = :name, P_TEAM_SIZE_MAX = :maxTeamSize, "
                   "P_TEAM_SIZE_MIN = :minTeamSize , P_DESCRIPTION = :description ,P_STATUS = :status "
                   " WHERE P_ID = :pid ;");
    query->bindValue(":pid", id);
    query->bindValue(":name", name);
    query->bindValue(":maxTeamSize", maxTeamSize);
    query->bindValue(":minTeamSize", minTeamSize);
    query->bindValue(":description", description);
    query->bindValue(":status", status);

    return query->exec();
}

bool Storage::publishProject(int id ){
    //return query->exec("UPDATE Project SET P_STATUS= PUBLISHED WHERE P_ID = "+id+" ;");
    query->prepare("UPDATE Project SET P_STATUS = 'PUBLISHED' WHERE P_ID = :pid ;");
    query->bindValue(":pid", id);

    return query->exec();
}


StudentProfile* Storage::getStudentProfile(int id){

    //query->exec("select * from Student where S_ID = "+id+" ;");
    query->prepare("select * from Student where S_ID =  :sid ;");
    query->bindValue(":sid", id);

    query->exec();
    StudentProfile *stu = new StudentProfile();

    if(query->first()){

        stu->setID(query->value(0).toInt());
        stu->setName(query->value(1).toString());
        stu->setUsername(query->value(2).toString());

        int ownQID = query->value(3).toInt();
        int partnerQID = query->value(4).toInt();

        QList<int>* ownQ = getQualifications(ownQID);
        QList<int>* partnerQ = getQualifications(partnerQID);

        stu->setOwnQ(ownQ);
        stu->setPartnerQ(partnerQ);
    }
    return stu;
}


// inside getStudentProfile()
QList<int>* Storage::getQualifications(int id){
    QSqlQuery *query4 = new QSqlQuery(db);

   // query4->exec("select * from Qualifications where Q_ID = "+id+" ;");
    query4->prepare("select * from Qualifications where Q_ID =:qid ; ");
    query4->bindValue(":qid", id);

    query4->exec();
    QList<int>* qualifications = new QList<int>();

    if(query4->first()){
        for(int i=0; i<14 ; ++i){
            (*(qualifications)) += query4->value(i).toInt();
        }
    }

    return qualifications;
}

QList<QList<QString>*>* Storage::getStudentProjects(int studentID){

    query->exec("select P_ID, P_NAME from Project where P_STATUS = 'PUBLISHED';");
    QList<QList<QString>*>* projects = new QList<QList<QString>*>;

    if(query->first()){
        do{
            QList<QString>* project = new QList<QString>();
            (*(project)) += query->value(0).toString();  //id
            (*(project)) += query->value(1).toString();  //name
            bool joined = studentJoinedProject(query->value(0).toInt(),studentID); //joined

            if(joined){
                (*(project)) += "TRUE";
            }else{
                (*(project)) += "FALSE";
            }
            (*projects) += project;
        }while (query->next());
    }
    return projects;
}

bool Storage::studentJoinedProject(int projectId,int studentId){
    QSqlQuery *query2 = new QSqlQuery(db);

    //query2->exec("select * from Project_Student where P_ID = "+projectId+" AND S_ID = "+studentID+" ;");
    query2->prepare("select * from Project_Student where P_ID = :pid AND S_ID = :sid ; ");
    query2->bindValue(":pid", projectId);
    query2->bindValue(":sid", studentId);
    query2->exec();

    if(query2->first()){
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


    query->prepare("UPDATE Student SET S_NAME = :sname,  S_USERNAME = :susername  WHERE S_ID = :sid; ");
    query->bindValue(":sid", id);
    query->bindValue(":sname", name);
    query->bindValue(":susername", username);
    return query->exec();
    /*
    return query->exec("UPDATE Project SET "
                       " S_NAME = '"+name+"' "
                       ", S_USERNAME = '"+username+"' "
                       " WHERE P_ID = "+id+" ;");
    */
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

    query3->prepare("UPDATE Qualifications SET"
                 " GRADE_2404 = :grade2404 "
                 ", GRADE_2402 = :grade2042 "
                 ", PUNCTUALITY = :punctuality "
                 ", TECHNICALITY= :technicality "
                 ", GROUP_WORK= :groupWork "
                 ", WORK_HOURS= :workHours "
                 ", FLEXIBILITY= :flexibility "
                 ", GRADE_GOAL= :gradeGoal "
                 ", MEETING_TOPICS= :meetingTopics "
                 ", LEADERSHIP= :leadership "
                 ", WEEKEND= :weekend "
                 ", COURSE_LOAD= :courseLoad "
                 ", PROJECTS= :projects "
                 " WHERE Q_ID =  :qid  ;");

    query3->bindValue(":grade2404", GRADE_2404);
    query3->bindValue(":grade2042", GRADE_2402);
    query3->bindValue(":punctuality", PUNCTUALITY);
    query3->bindValue(":technicality", TECHNICALITY);
    query3->bindValue(":groupWork", GROUP_WORK);
    query3->bindValue(":workHours", WORK_HOURS);
    query3->bindValue(":flexibility", FLEXIBILITY);
    query3->bindValue(":gradeGoal", GRADE_GOAL);
    query3->bindValue(":meetingTopics", MEETING_TOPICS);
    query3->bindValue(":leadership",LEADERSHIP );
    query3->bindValue(":weekend", WEEKEND);
    query3->bindValue(":courseLoad", COURSE_LOAD);
    query3->bindValue(":projects", PROJECTS);
    query3->bindValue(":qid", Q_ID);
    return query3->exec();

}



StudentProfile* Storage::getStudentByUsername(QString username)
{
    query->exec("SELECT * FROM Student WHERE S_USERNAME = '"+username+"';");


    StudentProfile *s = new StudentProfile();

    if(query->first()){

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


QList<StudentProfile*>* Storage::getStudentsInProject2(int pid)
{

  //query->exec("SELECT * FROM (SELECT S_ID FROM Project_Student WHERE P_ID = "+ pid +") NATURAL JOIN (SELECT * FROM Student);");

  query->prepare("SELECT * FROM (SELECT S_ID FROM Project_Student WHERE P_ID = :pid ) NATURAL JOIN (SELECT * FROM Student);");
  query->bindValue(":pid", pid);
  query->exec();
  QList<StudentProfile*>* studentsList = new QList<StudentProfile*>();


  if(query->first()){
      do{
        StudentProfile *s = new StudentProfile();
        s->setID(query->value(0).toInt());

        s->setName(query->value(1).toString());
        s->setUsername(query->value(2).toString());

        int ownQ = query->value(3).toInt();
        int partnerQ = query->value(4).toInt();

        QList<int>* oQ = getQualifications(ownQ);
        QList<int>* pQ = getQualifications(partnerQ);

        s->setOwnQ(oQ);
        s->setPartnerQ(pQ);
        (*studentsList) += s;

      }while(query->next());
  }

  return studentsList;

}

	//Algorithm management functions
void Storage::executeAlgorithm(Project* project, QList<StudentProfile*>* studentsInProject){
    AlgorithmManager     *algorithmManager = new AlgorithmManager();
    algorithmManager->runAlgorithm(project, studentsInProject);
}
void Storage::backToAdmin(){}

