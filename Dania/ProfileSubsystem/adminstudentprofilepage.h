#ifndef ADMINSTUDENTPROFILEPAGE_H
#define ADMINSTUDENTPROFILEPAGE_H

#include <QWidget>
#include "mainwindow.h"
#include "ProfileSubsystem/profilemanager.h"
/* administrator profile page boundary class */
class MainWindow;

namespace Ui {
class AdminStudentProfilePage;
}

class AdminStudentProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminStudentProfilePage(QWidget *parent = 0);
    ~AdminStudentProfilePage();
    void setMain(MainWindow*);
    void setStudentProfile(StudentProfile*,int);
    QString convertQ(int qid,int valueID);

private slots:
    void on_backButton_clicked();

private:
    Ui::AdminStudentProfilePage *ui;
    MainWindow *main;
    StudentProfile* studentProfile;
    int pid;
    ProfileManager *manager;
};

#endif // ADMINSTUDENTPROFILEPAGE_H
