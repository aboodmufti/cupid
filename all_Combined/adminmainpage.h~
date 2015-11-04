#ifndef ADMINMAINPAGE_H
#define ADMINMAINPAGE_H

#include <QWidget>
#include <QList>
#include <QTableWidget>
#include "mainwindow.h"
#include "entity/EntityDef.h"

class MainWindow;

namespace Ui {
class AdminMainPage;
}

class AdminMainPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainPage(QWidget *parent = 0);
    ~AdminMainPage();
    void setMain(MainWindow*);
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
    MainWindow *main;
    QList<Project*> *projects;
    int projId;
    //QTableWidget* projects;
};

#endif // ADMINMAINPAGE_H
