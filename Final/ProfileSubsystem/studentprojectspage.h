#ifndef STUDENTPROJECTSPAGE_H
#define STUDENTPROJECTSPAGE_H

#include <QWidget>
#include "ProfileSubsystem/profilemanager.h"
#include "mainwindow.h"
/* student projects page boundary class */
class MainWindow;
class ProfileManager;
namespace Ui {
class StudentProjectsPage;
}

class StudentProjectsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProjectsPage(QWidget *parent = 0);
    ~StudentProjectsPage();
    //void setMain(MainWindow*);
    void setManager(ProfileManager*);
    void setProjects(QList<QList<QString>*>*);

private slots:
    void on_pushButton_clicked();
    void joinButtonClicked(int pid);

private:
    Ui::StudentProjectsPage *ui;
    MainWindow *main;
    ProfileManager *manager;
};

#endif // STUDENTPROJECTSPAGE_H
