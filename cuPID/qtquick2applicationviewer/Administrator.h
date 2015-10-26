#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <QString>

class Administrator : public User
{
    public:
        Administrator(QString);
};

#endif // ADMINISTRATOR_H
