#ifndef STUDENTLOGINPAGE_H
#define STUDENTLOGINPAGE_H

#include <QWidget>

namespace Ui {
class StudentLoginPage;
}

class StudentLoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentLoginPage(QWidget *parent = 0);
    ~StudentLoginPage();

private:
    Ui::StudentLoginPage *ui;
};

#endif // STUDENTLOGINPAGE_H
