#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include "Project.h"
#include <QString>
#include <QList>

class Administrator : public User
{
    public:
        Administrator();
        void addProject(Project*);

    private:
        QList<Project*> projects;
};

#endif // ADMINISTRATOR_H
