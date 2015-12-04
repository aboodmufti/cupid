#ifndef EDITPROJECTPAGE_H
#define EDITPROJECTPAGE_H

#include <QWidget>
#include "projectmanager.h"
/* administrator edit project page boundary class */
class ProjectManager;
class Project;
namespace Ui {
class EditProjectPage;
}

class EditProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit EditProjectPage(QWidget *parent = 0);
    ~EditProjectPage();
    void setManager(ProjectManager*);
    Project* getProject();
    void setProject(Project*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditProjectPage *ui;
    ProjectManager *projectManager;
    int pid;
};

#endif // EDITPROJECTPAGE_H



