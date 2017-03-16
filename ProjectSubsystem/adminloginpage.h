#ifndef ADMINLOGINPAGE_H
#define ADMINLOGINPAGE_H

#include <QWidget>
#include "mainwindow.h"
#include "projectmanager.h"
class ProjectManager;
class MainWindow;
/* administrator login page boundary class */
namespace Ui {
class AdminLoginPage;
}

class AdminLoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLoginPage(QWidget *parent = 0);
    ~AdminLoginPage();
    void setManager(ProjectManager*);
    QString getUsername();

private slots:
    void on_submitButton_clicked();

    void on_backButton_clicked();

private:
    Ui::AdminLoginPage *ui;
    ProjectManager* projectManager;
};

#endif // ADMINLOGINPAGE_H
