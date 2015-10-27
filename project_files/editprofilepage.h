#ifndef EDITPROFILEPAGE_H
#define EDITPROFILEPAGE_H

#include <QWidget>

namespace Ui {
class EditProfilePage;
}

class EditProfilePage : public QWidget
{
    Q_OBJECT

public:
    explicit EditProfilePage(QWidget *parent = 0);
    ~EditProfilePage();

private:
    Ui::EditProfilePage *ui;
};

#endif // EDITPROFILEPAGE_H
