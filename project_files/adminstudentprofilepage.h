#ifndef ADMINSTUDENTPROFILEPAGE_H
#define ADMINSTUDENTPROFILEPAGE_H

#include <QWidget>
#include "mainwindow.h"
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

private slots:
    void on_backButton_clicked();

private:
    Ui::AdminStudentProfilePage *ui;
    MainWindow *main;
};

#endif // ADMINSTUDENTPROFILEPAGE_H
