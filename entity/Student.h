#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include "User.h"
#include "StudentProfile.h"

class Student: public User
{
    private:
        StudentProfile *stuProfile;
    public:
        Student(QString);

};
#endif // STUDENT_H
