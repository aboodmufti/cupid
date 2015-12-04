#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include "StorageSubsystem/storage.h"
#include "welcomepage.h"
#include "ProjectSubsystem/adminloginpage.h"
/* control class for the whole program */
class WelcomePage;
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initialize(Storage* storage);
    void initialize();


private:
    Ui::MainWindow *ui;
    WelcomePage* welcomePage;
    Storage* storage;
};

#endif // MainWindow2_H
