#ifndef DETAILEDRESULTS_H
#define DETAILEDRESULTS_H

#include <QWidget>
#include "algorithmmanager.h"

class AlgorithmManager;

namespace Ui {
class DetailedResults;
}

class DetailedResults : public QWidget
{
    Q_OBJECT

public:
    explicit DetailedResults(QWidget *parent = 0);
    ~DetailedResults();
    void setManager(AlgorithmManager* manager);
    void setOutput(QString output);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DetailedResults *ui;
    AlgorithmManager* manager;
};

#endif // DETAILEDRESULTS_H

