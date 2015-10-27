#ifndef STUDENTPROJECTSPAGE_H
#define STUDENTPROJECTSPAGE_H

#include <QWidget>

namespace Ui {
class StudentProjectsPage;
}

class StudentProjectsPage : public QWidget
{
    Q_OBJECT

public:
    explicit StudentProjectsPage(QWidget *parent = 0);
    ~StudentProjectsPage();

private:
    Ui::StudentProjectsPage *ui;
};

#endif // STUDENTPROJECTSPAGE_H
