#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include "User.h"
#include "StudentProfile.h"
/*student entity class*/
class Student: public User
{
    public:
        Student();
        void setStudentProfile(StudentProfile*);
        StudentProfile* getStudentProfile();
    private:
        StudentProfile *stuProfile;

};
#endif // STUDENT_H
