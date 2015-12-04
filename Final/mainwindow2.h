#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "StorageSubsystem/storage.h"
#include "welcomepage.h"
class Storage;
class WelcomePage;

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
    void initialize(Storage* storage);
    void initialize();
private:
    Ui::MainWindow2 *ui;
    WelcomePage* welcomePage;
};

#endif // MAINWINDOW_H
