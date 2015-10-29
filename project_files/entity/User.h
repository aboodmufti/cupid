#ifndef USER_H
#define USER_H

#include <QString>
using namespace std;

class User
{
    private:
        QString username;
    public:
        User();
        void setUsername(QString);
        QString getUsername();
};

#endif // USER_H
