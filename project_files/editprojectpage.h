#ifndef EDITPROJECTPAGE_H
#define EDITPROJECTPAGE_H

#include <QWidget>

namespace Ui {
class EditProjectPage;
}

class EditProjectPage : public QWidget
{
    Q_OBJECT

public:
    explicit EditProjectPage(QWidget *parent = 0);
    ~EditProjectPage();

private:
    Ui::EditProjectPage *ui;
};

#endif // EDITPROJECTPAGE_H
