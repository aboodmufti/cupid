#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = 0);
    ~WelcomePage();
    void setMain(MainWindow*);

private slots:
    void on_adminButton_clicked();

    void on_studentButton_clicked();

private:
    Ui::WelcomePage *ui;
    MainWindow *main;
};

#endif // WELCOMEPAGE_H



