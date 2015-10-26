#include "User.h"
#include <QString>

User::User()
{
}

User::User(QString username)
{
    this->username = username;
}

void User::setUsername(QString username)
{
    this->username = username;
}

QString User::getUsername()
{
    return username;
}
