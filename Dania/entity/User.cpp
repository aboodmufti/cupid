#include "User.h"
#include <QString>

User::User()
{
    username = "unknown";
}


void User::setUsername(QString username)
{
    this->username = username;
}

QString User::getUsername()
{
    return username;
}
