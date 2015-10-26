#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <QString>

class Student: public User
{
    private:
        //StudentProfile *stuProfile;
    public:
        Student(QString);

};
#endif // STUDENT_H
