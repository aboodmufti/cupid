#ifndef STUDENTPROJECTSPAGE_H
#define STUDENTPROJECTSPAGE_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class StudentProjectsPage;
}

class StudentProjectsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProjectsPage(QWidget *parent = 0);
    ~StudentProjectsPage();
    void setMain(MainWindow*);
    void setProjects(QList<QList<QString>*>*);

private slots:
    void on_pushButton_clicked();

private:
    Ui::StudentProjectsPage *ui;
    MainWindow *main;
};

#endif // STUDENTPROJECTSPAGE_H
