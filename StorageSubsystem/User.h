#ifndef USER_H
#define USER_H

#include <QString>
using namespace std;
/*entity class user that happens to be a parent of student and administrator*/
class User
{
    protected:
        QString username;
    public:
        User();
        void setUsername(QString);
        QString getUsername();
};

#endif // USER_H
