#ifndef ALGORITHMSUMMARY_H
#define ALGORITHMSUMMARY_H

#include <QWidget>

namespace Ui {
class AlgorithmSummary;
}

class AlgorithmSummary : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmSummary(QWidget *parent = 0);
    ~AlgorithmSummary();

private:
    Ui::AlgorithmSummary *ui;
};

#endif // ALGORITHMSUMMARY_H
