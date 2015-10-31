#ifndef ADMINMAINPAGE_H
#define ADMINMAINPAGE_H

#include <QWidget>
#include <QList>
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


private slots:
    void on_createButton_2_clicked();
    void on_logoutButton_2_clicked();

private:
    Ui::AdminMainPage *ui;
    MainWindow *main;
    QList<Project*> *projects;
};

#endif // ADMINMAINPAGE_H
