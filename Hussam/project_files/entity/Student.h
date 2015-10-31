#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include "User.h"
#include "StudentProfile.h"

class Student: public User
{
    public:
        Student();
        void setStudentProfile(StudentProfile*);

    private:
        StudentProfile *stuProfile;

};
#endif // STUDENT_H
