#ifndef CREATEPROJECTPAGE_H
#define CREATEPROJECTPAGE_H

#include <QWidget>
#include "mainwindow.h"
#include "entity/EntityDef.h"
/* administrator create project page boundary class */
class MainWindow;

namespace Ui {
class createProjectPage;
}

class createProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit createProjectPage(QWidget *parent = 0);
    ~createProjectPage();
    void setMain(MainWindow*);
    Project* getProject();

private slots:
    void on_pushButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::createProjectPage *ui;
    MainWindow *main;
};

#endif // CREATEPROJECTPAGE_H
