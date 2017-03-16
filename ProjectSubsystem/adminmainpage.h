#ifndef ADMINMAINPAGE_H
#define ADMINMAINPAGE_H

#include <QWidget>
#include <QList>
#include <QTableWidget>
#include "projectmanager.h"
#include "StorageSubsystem/EntityDef.h"
/* administrator main page boundary class */
class ProjectManager;

namespace Ui {
class AdminMainPage;
}

class AdminMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainPage(QWidget *parent = 0);
    ~AdminMainPage();
    void setManager(ProjectManager*);
    void setProjects(QList<Project*>*);
    int getProjectId();
    void setProject(Project*);


private slots:
    void on_createButton_2_clicked();
    void on_logoutButton_2_clicked();
    void tableItemClicked(int, int);
    //void tableItemClicked(int, int, Project*);

private:
    Ui::AdminMainPage *ui;
    ProjectManager *projectManager;
    QList<Project*> *projects;
    int projId;
    //QTableWidget* projects;
};

#endif // ADMINMAINPAGE_H
