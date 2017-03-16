#ifndef Team_hpp
#define Team_hpp

#include <stdio.h>
#include <iostream>
#include <QList>

using namespace std;

class Team{
friend ostream& operator<<(ostream&, Team&);
public:
    // constructors and destructors
    Team();
    Team(QString, int);
    Team(QString, int, QList<int>, QString);
    
    //getters and setters
    void setTeamName(QString);
    QString getTeamName();
    void setSize(int);
    int getSize();
    void setStudentIds(QList<int>);
    QList<int> getStudentIds();
    void setTeamInfo(QString);
    QString getTeamInfo();
    
    //member functions
    bool addStudent(int);
    void removeStudent(int);
    
    
    //operator overload
    Team& operator+=(int);
    Team& operator-=(int);
    
private:
    QString      teamName;
    int         size;
    QList<int>  studentIds;
    QString      teamInfo;
};


#endif
