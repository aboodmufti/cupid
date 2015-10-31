#ifndef EDITPROJECTPAGE_H
#define EDITPROJECTPAGE_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class EditProjectPage;
}

class EditProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit EditProjectPage(QWidget *parent = 0);
    ~EditProjectPage();
    void setMain(MainWindow*);
    Project* getProject();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditProjectPage *ui;
    MainWindow *main;
};

#endif // EDITPROJECTPAGE_H



