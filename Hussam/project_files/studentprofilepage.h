#ifndef STUDENTPROFILEPAGE_H
#define STUDENTPROFILEPAGE_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class StudentProfilePage;
}

class StudentProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProfilePage(QWidget *parent = 0);
    ~StudentProfilePage();
    void setMain(MainWindow*);

private slots:
    void on_pushButton_3_clicked();

    void on_projectsButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::StudentProfilePage *ui;
    MainWindow *main;
};

#endif // STUDENTPROFILEPAGE_H
