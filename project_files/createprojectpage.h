#ifndef CREATEPROJECTPAGE_H
#define CREATEPROJECTPAGE_H

#include <QWidget>

namespace Ui {
class createProjectPage;
}

class createProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit createProjectPage(QWidget *parent = 0);
    ~createProjectPage();

private:
    Ui::createProjectPage *ui;
};

#endif // CREATEPROJECTPAGE_H
