#ifndef ADMINLOGINPAGE_H
#define ADMINLOGINPAGE_H

#include <QWidget>

namespace Ui {
class AdminLoginPage;
}

class AdminLoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLoginPage(QWidget *parent = 0);
    ~AdminLoginPage();

private:
    Ui::AdminLoginPage *ui;
};

#endif // ADMINLOGINPAGE_H
