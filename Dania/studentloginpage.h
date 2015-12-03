#ifndef STUDENTLOGINPAGE_H
#define STUDENTLOGINPAGE_H

#include <QWidget>
#include "mainwindow.h"
/* student login page boundary class */
class MainWindow;

namespace Ui {
class StudentLoginPage;
}

class StudentLoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentLoginPage(QWidget *parent = 0);
    ~StudentLoginPage();
    void setMain(MainWindow*);
    QString getUsername();

private slots:
    void on_submitButton_clicked();

    void on_backButton_clicked();

private:
    Ui::StudentLoginPage *ui;
    MainWindow *main;
};

#endif // STUDENTLOGINPAGE_H


