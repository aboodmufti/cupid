#ifndef PROJECTPAGE_H
#define PROJECTPAGE_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class ProjectPage;
}

class ProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectPage(QWidget *parent = 0);
    ~ProjectPage();
    void setMain(MainWindow*);
    void setProject(Project*, QList<StudentProfile*>*);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void tableItemClicked(int row , int column);

private:
    Ui::ProjectPage *ui;
    MainWindow *main;
    int pid;
    int sid;
    QList<StudentProfile*>* studentsInProjectList;
};

#endif // PROJECTPAGE_H
