#ifndef STORAGE_H
#define STORAGE_H
#include <QList>
#include <QtSql>

#include "EntityDef.h"

#include <string>
#include <QString>
#include "Algorithm/algorithmmanager.h"
#include "mainwindow.h"
#include "ProjectSubsystem/projectmanager.h"
#include "ProfileSubsystem/profilemanager.h"
class ProfileManager;
class ProjectManager;
class StudentProfile;
/* class storage contains all the functions that would apply the database commands*/
using namespace std;

class Storage
{
    public:

        Storage();

        //Student profile functions
        void 		createStudentProfile();
        StudentProfile*    createNewStudentProfile();
        StudentProfile* 		getStudentProfile();
        int 				getProfileID();
        QString 			getProfileName();
        QList<int>*     	        getOwnQ();
    	QList<int>*       		getPartnerQ();
        //Qlist<Team*>     		getTeams();
    	QList<Project*>  	        getProjects();
        void            		setUsername(QString);
    	void            		setProfileName(QString);
    	void           			setProfileID(int);
    	void             		setOwnQ(QList<int>*);
    	void              		setPartnerQ(QList<int>*);
    	//void             		setTeams(Team*);
        void              		addProject(Project*);
    	void             	        setProjects(QList<Project*>);
        void 				setStudentProfile(StudentProfile* profile);

        //Student functions
        void			createStudent();
        Student*         createNewStudent();
        Student*			getStudent();
        void				setStudent(Student*);
        void                setOwnProfile(StudentProfile*);
        StudentProfile*      getOwnProfile();

        //Admin functions
        void			createAdministrator();
        Administrator*			getAdministrator();
        void				setAdministrator(Administrator*);
        void 				addNewProject(Project*);

        //Project functions
        Project*			 getProject();
        void			 createProject();
        Project*             createNewProject();
        int        			 getProjectID();
        QString   			 getProjectName();
        int     		         getMinTeamSize();
        int     			 getMaxTeamSize();
        QString   			 getDescription();
        QString   			 getStatus();
        void				 setProject(Project*);
        void       			 setProjectID(int);
        void     			 setProjectName(QString);
        void   			         setMinTeamSize(int);
        void     			 setMaxTeamSize(int);
        void  			         setDescription(QString);
        void   				 setStatus(QString);

        //Team functions
        Team*               createNewTeam();
        void				setTeam(Team*);
        Team*				getTeam();
        Team*				createTeam();
    	void 				setTeamName(QString);
        QString				getTeamName();
    	void 				setSize(int);
    	int				getSize();
    	void				setStudentIds(QList<int>);
        QList<int>			getStudentIds();
    	void 				setTeamInfo(QString);
    	QString 			getTeamInfo();
        bool 				addStudent(int);
        void				removeStudent(int);

        //Profile manager functions
        bool                            insertStudent(StudentProfile*); 
        int                             insertQualifications(QList<int>*); 
        bool                            addStudentProject(int, int);        
        StudentProfile*                 getStudentProfile(int);     
        QList<int>*                     getQualifications(int);
        QList<QList<QString>*>*         getStudentProjects(int);    
        bool                            studentJoinedProject(int,int);
        bool                            updateStudentProfile(StudentProfile*); 
        bool                            updateQualifications(QList<int>*);
        StudentProfile*                 getStudentByUsername(QString);
        bool                            setUpStudentTable();
        bool                            setUpQualificationsTable();
        bool                            setUpProjectStudentTable(); 
        QList<StudentProfile*>*         getStudentsInProject2(int pid);


        //Project management functions
        int                             insertProject(Project*);
        bool                            insertAdministrator(Administrator*);
        bool                            addAdminProject(int projId, QString);
        Administrator*                  getAdminByUsername(QString);
        QList<Project*>*                getAllProjects();          
        Project*                        getProjectById(int);        
        bool                            updateProject(Project*);
        bool                            publishProject(int);  
        bool                            setUpAdministratorTable();
        bool                            setUpAdminProjectTable();
        bool                            setUpProjectTable();

        //Algorithm management functions
        void                            executeAlgorithm(Project*, QList<StudentProfile*>*,MainWindow* main);
        void                            goToProject(int pid, int err);

        //other storage functions
        QSqlQuery*			getQueryObject();

        //WelcomePage functions
        void goToAdminLogin(MainWindow* main);
        void goToStudentLogin(MainWindow* main);

    private:
        QSqlQuery                       *query;
        QSqlDatabase                     db;
        StudentProfile                   *stuProfile;
        Administrator    	*admin;
        Project				*project;
        Student 			*stu;
        Team 				*team;
        ProjectManager*     projectManager;
        ProfileManager*     profileManager;
};

#endif // STORAGE_H
