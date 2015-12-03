#include "Team.hpp"

// constructors and destructors
Team::Team(){
    teamName = "NOT DECIDED";
    size = 0;
    teamInfo = "NO INFORMATION AVAILABLE";
}

Team::Team(QString name, int s){
    teamName = name;
    size = s;
    teamInfo = "NO INFORMATION AVAILABLE";
}
Team::Team(QString name, int s, QList<int> stu, QString info){
    teamName = name;
    size = s;
    studentIds = stu;
    teamInfo = info;
}


//getters and setters
void Team::setTeamName(QString name){
    teamName = name;
}

QString Team::getTeamName(){
    return teamName;
}

void Team::setSize(int s){
    size = s;
}

int Team::getSize(){
    return size;
}

void Team::setStudentIds(QList<int> stu){
    studentIds = stu;
}

QList<int> Team::getStudentIds(){
    return studentIds;
}

void Team::setTeamInfo(QString info){
    teamInfo = info;
}

QString Team::getTeamInfo(){
    return teamInfo;
}

//member functions
bool Team::addStudent(int id){
    if (studentIds.size() < size){
        studentIds.push_back(id);
        return true;
    }
    return false;
}

void Team::removeStudent(int id){
    studentIds.remove(id);
}


//operator overload
Team& Team::operator+=(int id){
    this->addStudent(id);
    return *this;
}

Team& Team::operator-=(int id){
    this->removeStudent(id);
    return *this;
}

ostream& operator<<(ostream& out, Team& t)
{
    out << t.teamInfo << endl;
    return out;
}
