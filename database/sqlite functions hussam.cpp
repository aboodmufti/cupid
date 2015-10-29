Student getStudentByUsername(String username)
{
  query->exec("SELECT * FROM STUDENT WHERE S_USERNAME = "++username++";");
  StudentProfile *s = new StudentProfile();
  while(query->next()){
    s->setID(query->value(0).toInt());
    s->setName(query->value(1).toString());
    s->setUsername(query->value(2).toString());
    
    int ownQ = query->value(3).toInt();
    int partnerQ = query->value(4).toInt();

   QList<int> oQ = getQualifications(ownQ);
   QList<int> pQ = getQualifications(partnerQ);

   s->setOwnQualifications(oQ);
   s->setPartnerQualifications(pQ);
  }
   return s;
}

bool setUpProjectTable()
{
 bool exec_ok = return query->exec("create table if not exists PROJECT (P_ID INTEGER PRIMARY KEY AUTOINCREMENT, P_NAME varchar(96), P_TEAM_SIZE_MIN INT, P_TEAM_SIZE_MAX INT, P_DESCRIPTION varchar(500), P_STATUS varchar(50));");
}

bool setUpStudentTable()
{
 bool exec_ok = return query->exec("create table if not exists STUDENT (S_ID INTEGER PRIMARY KEY, S_NAME varchar(96), S_USERNAME varchar(64), S_OWN_Q INTEGER, S_PARTNER_Q INTEGER);");
}

bool setUpQualificationsTable()
{
 bool exec_ok = return query->exec("create table if not exists QUALIFICATIONS (Q_ID INTEGER PRIMARY KEY AUTOINCREMENT, GRADE_2404 INT, GRADE_2402 INT, PUNCTUALITY INT, TECHNICALITY INT, GROUP_WORK INT, WORK_HOURS INT, FLEXIBILITY INT, GRADE_GOAL INT, MEETING_TOPICS INT, LEADERSHIP INT, WEEKEND INT, COURSE_LOAD INT, PROJECTS INT);");
}

bool setUpProjectStudentTable()
{
 bool exec_ok = return query->exec("create table if not exists PROJECT_STUDENT (P_ID INTEGER, S_ID INTEGER, FOREIGN KEY (P_ID) REFERENCES PROJECT(P_ID), FOREIGN KEY (S_ID) REFERENCES STUDENT(S_ID));");
}

bool setUpAdministratorTable()
{
 bool exec_ok = return query->exec("create table if not exists ADMIN (A_USERNAME varchar(96) PRIMARY KEY);");
}

bool setUpAdminProjectTable()
{
 bool exec_ok = return query->exec("create table if not exists ADMIN_PROJECT (P_ID INTEGER, A_USERNAME varchar(96), FOREIGN KEY (P_ID) REFERENCES PROJECT(P_ID), FOREIGN KEY (A_USERNAME) REFERENCES ADMIN(A_USERNAME));");
}

Student getStudentsInProject(int pid)
{
  query->exec("(SELECT S_ID FROM PROJECT_STUDENT WHERE P_ID = "++pid++") NATURAL JOIN (SELECT * FROM STUDENT);");
  StudentProfile *s = new StudentProfile();
  while(query->next()){
    s->setID(query->value(0).toInt());
    s->setName(query->value(1).toString());
    s->setUsername(query->value(2).toString());
    
    int ownQ = query->value(3).toInt();
    int partnerQ = query->value(4).toInt();

    QList<int> oQ = getQualifications(ownQ);
    QList<int> pQ = getQualifications(partnerQ);

    s->setOwnQualifications(oQ);
    s->setPartnerQualifications(pQ);
  }
  return s;
}
