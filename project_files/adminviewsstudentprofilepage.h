#ifndef ADMINVIEWSSTUDENTPROFILEPAGE_H
#define ADMINVIEWSSTUDENTPROFILEPAGE_H

#include <QWidget>

namespace Ui {
class AdminViewsStudentProfilePage;
}

class AdminViewsStudentProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminViewsStudentProfilePage(QWidget *parent = 0);
    ~AdminViewsStudentProfilePage();

private:
    Ui::AdminViewsStudentProfilePage *ui;
};

#endif // ADMINVIEWSSTUDENTPROFILEPAGE_H
