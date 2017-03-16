#ifndef ALGORITHMSUMMARY_H
#define ALGORITHMSUMMARY_H

#include <QWidget>
#include "algorithmmanager.h"
#include <QTableWidget>

class QTableWidget;
class AlgorithmManager;

namespace Ui {
class AlgorithmSummary;
}

class AlgorithmSummary : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmSummary(QWidget *parent = 0);
    ~AlgorithmSummary();
    void setOutput(QString output);
    void setManager(AlgorithmManager* manager);
    void setAllOutput(QList<QMap<QString, int>*>* output);
    QTableWidget* getTable();
private slots:
    void on_pushButton_clicked();
    
    void on_detailedResults_clicked();

private:
    Ui::AlgorithmSummary *ui;
    AlgorithmManager* manager;
};

#endif // ALGORITHMSUMMARY_H


