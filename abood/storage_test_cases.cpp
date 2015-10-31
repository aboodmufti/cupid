/*
Storage* storage = new Storage();

qDebug() << "adminTable " << storage->setUpAdministratorTable();
qDebug() << "adminProjectTable " << storage->setUpAdminProjectTable();
qDebug() << "ProjectStudentTable " << storage->setUpProjectStudentTable();
qDebug() << "projectTable " << storage->setUpProjectTable();
qDebug() << "Q table " << storage->setUpQualificationsTable();
qDebug() << "student table " << storage->setUpStudentTable();


//INSERT PROJECT

Project* proj1 = new Project();
proj1->setName("IOS APP");
proj1->setDescription("this project is about making a cool iOS app");
proj1->setMaxTeamSize(4);
proj1->setMinTeamSize(2);

Project* proj2 = new Project();
proj2->setName("android APP");
proj2->setDescription("this project is about making a cool android app");
proj2->setMaxTeamSize(8);
proj2->setMinTeamSize(4);


qDebug() << "insert project: " << storage->insertProject(proj1);
qDebug() << "insert project: " << storage->insertProject(proj2);

//insert student

StudentProfile* stu = new StudentProfile();
QList<int>* ownq = new QList<int>();

(*(ownq)) += 1;
(*(ownq)) += 1;
(*(ownq)) += 2;
(*(ownq)) += 3;
(*(ownq)) += 4;
(*(ownq)) += 5;
(*(ownq)) += 6;
(*(ownq)) += 6;
(*(ownq)) += 7;
(*(ownq)) += 8;
(*(ownq)) += 9;
(*(ownq)) += 12;
(*(ownq)) += 14;
(*(ownq)) += 19;


stu->setID(10023492);
stu->setName("Hussam");

stu->setOwnQ(ownq);
stu->setPartnerQ(ownq);

stu->setUsername("hussamabubaker");

qDebug() << "insert student " << storage->insertStudent(stu);

//get all projects
QList<Project*>* projects = storage->getAllProjects();
Project* project1 = (*(projects))[0];
Project* project2 = (*(projects))[1];

qDebug() << "project1 name: " << project1->getName();
qDebug() << "project2 name: " << project2->getName();


//add student to project

qDebug() << "add student to project: " << storage->addStudentProject(project1->getID(),stu->getID());

//publish project
//FIX PUBLISHED FUNCTION ADD QUOTATIONS
//INITIALIZE PROJECT STATUS IN CONSTRUCTOR

qDebug() << "publish project: " << storage->publishProject(project1->getID());
qDebug() << "publish project status : " << storage->getProjectById(project1->getID())->getStatus();

// get students' projects
//FIX BELOW FUNCTION TO PROJECT NOT PROJECTS
//FIX LIST ADDING
QList<QList<QString>*>* projectList = storage->getStudentProjects(stu->getID());
//qDebug() << "get student projects : " << storage->getQueryObject()->lastError().text();


// get student by id

StudentProfile* studentBack = storage->getStudentProfile(stu->getID());


qDebug() << "student name: " << studentBack->getName();
qDebug() << "projects for that student: " ;
qDebug() << "             Project name: " << (*((*(projectList))[0]))[1];
qDebug() << "           Student Joined: " << (*((*(projectList))[0]))[2];           //DEREFERENCE TWICE

//update student profile
studentBack->setName("Abood");

//FIX BELOW FUNCTION: SQL STATMENT WRONG
qDebug() << "update student name : " << storage->updateStudentProfile(studentBack);
qDebug() << "update student ERROR : " << storage->getQueryObject()->lastError().text();
qDebug() << "new student name : " << storage->getStudentProfile(studentBack->getID())->getName();

//get students in project
qDebug() << "get students in project : " << (*(storage->getStudentsInProject(project1->getID())))[0]->getName();

//FIX GET admin by username: add quotations
//FIX last function
*/
