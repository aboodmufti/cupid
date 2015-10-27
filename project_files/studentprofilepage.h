#ifndef STUDENTPROFILEPAGE_H
#define STUDENTPROFILEPAGE_H

#include <QWidget>

namespace Ui {
class StudentProfilePage;
}

class StudentProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProfilePage(QWidget *parent = 0);
    ~StudentProfilePage();

private:
    Ui::StudentProfilePage *ui;
};

#endif // STUDENTPROFILEPAGE_H
