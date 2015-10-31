#ifndef ADMINLOGINPAGE_H
#define ADMINLOGINPAGE_H

#include <QWidget>
#include <QString>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class AdminLoginPage;
}

class AdminLoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLoginPage(QWidget *parent = 0);
    ~AdminLoginPage();
    void setMain(MainWindow*);
    QString getUsername(); // added hussam

private slots:
    void on_submitButton_clicked();

private:
    Ui::AdminLoginPage *ui;
    MainWindow *main;
};

#endif // ADMINLOGINPAGE_H
