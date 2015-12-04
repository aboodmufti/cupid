#ifndef STUDENTPROFILEPAGE_H
#define STUDENTPROFILEPAGE_H

#include <QWidget>
#include "ProfileSubsystem/profilemanager.h"
#include "mainwindow.h"
/* student profile page boundary class */
class MainWindow;
class StudentProfile;
class ProfileManager;

namespace Ui {
class StudentProfilePage;
}

class StudentProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProfilePage(QWidget *parent = 0);
    ~StudentProfilePage();
    //void setMain(MainWindow*);
    void setManager(ProfileManager*);
    void setStudentProfile(StudentProfile*);
    QString convertQ(int qid,int valueID);

private slots:
    void on_pushButton_3_clicked();

    void on_projectsButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentProfilePage *ui;
    MainWindow *main;
    StudentProfile* studentProfile;

    ProfileManager *manager;
};

#endif // STUDENTPROFILEPAGE_H
