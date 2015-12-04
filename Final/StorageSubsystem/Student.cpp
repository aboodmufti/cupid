#include "Student.h"
#include <QString>

Student::Student() : User() {}


void Student::setStudentProfile(StudentProfile* stu){
    stuProfile = stu;
}

StudentProfile* Student::getStudentProfile(){
    //qDebug() << "DEBUG 18";
    return stuProfile;
}
