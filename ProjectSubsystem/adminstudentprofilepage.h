#ifndef ADMINSTUDENTPROFILEPAGE_H
#define ADMINSTUDENTPROFILEPAGE_H

#include <QWidget>
#include "projectmanager.h"
/* administrator profile page boundary class */
class ProjectManager;

namespace Ui {
class AdminStudentProfilePage;
}

class AdminStudentProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminStudentProfilePage(QWidget *parent = 0);
    ~AdminStudentProfilePage();
    void setManager(ProjectManager*);
    void setStudentProfile(StudentProfile*,int);
    QString convertQ(int qid,int valueID);

private slots:
    void on_backButton_clicked();

private:
    Ui::AdminStudentProfilePage *ui;
    ProjectManager *projectManager;
    StudentProfile* studentProfile;
    int pid;
};

#endif // ADMINSTUDENTPROFILEPAGE_H
