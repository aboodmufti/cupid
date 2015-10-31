#ifndef EDITPROFILEPAGE_H
#define EDITPROFILEPAGE_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class EditProfilePage;
}

class EditProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit EditProfilePage(QWidget *parent = 0);
    ~EditProfilePage();
    void setMain(MainWindow*);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::EditProfilePage *ui;
    MainWindow *main;
};

#endif // EDITPROFILEPAGE_H
