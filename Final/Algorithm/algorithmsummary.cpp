#include "algorithmsummary.h"
#include "ui_algorithmsummary.h"

AlgorithmSummary::AlgorithmSummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlgorithmSummary)
{
    ui->setupUi(this);
}

AlgorithmSummary::~AlgorithmSummary()
{
    delete ui;
}

void AlgorithmSummary::setOutput(QString output){
    //ui->output->append(output);
}

void AlgorithmSummary::setManager(AlgorithmManager* manager){
    this->manager = manager;
}

void AlgorithmSummary::on_pushButton_clicked()
{
    manager->goToProject();
}


void AlgorithmSummary::on_detailedResults_clicked()
{
    manager->goToDetails();
}

void AlgorithmSummary::setAllOutput(QList<QMap<QString, int>*>* output){
    int sum = 0;
    for(int i = 0; i < output->size() ; ++i){
        sum += output->at(i)->value("size");
    }
    sum += output->size();

    ui->outputTable->setRowCount(sum);
    ui->outputTable->setColumnCount(2);
    ui->outputTable->setColumnWidth(0, 600);
    ui->outputTable->horizontalHeader()->setStretchLastSection(true);
    ui->outputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->outputTable->setHorizontalHeaderLabels(QString("Student Name;Student ID").split(";"));
    ui->outputTable->verticalHeader()->setVisible(false);
    int count = 0;
    for(int i = 0; i < output->size() ; ++i){
        QColor * green = new QColor(185, 222, 249);
        ui->outputTable->verticalHeader()->resizeSection(count, 35);
        ui->outputTable->setSpan(count,0,1,2);
        //for (int Col = 0; Col < ui->outputTable->columnCount(); Col++)
        //{
            QTableWidgetItem *newTeam = new QTableWidgetItem("Team "+QString::number(i+1));
            newTeam->setTextAlignment(Qt::AlignCenter);

            ui->outputTable->setItem(count, 0, newTeam);
            ui->outputTable->item(count, 0)->setBackground(QBrush(QColor(185, 222, 249),Qt::SolidPattern));
            //ui->outputTable->item(count,0)->setSelected(true);
        //}
        ++count;

        QList<QString> keysList = output->at(i)->keys();
        for(int z = 0; z < keysList.size() ; ++z){
            if(keysList.at(z).contains("s") && !keysList.at(z).contains("size")){
                   StudentProfile* stu = manager->getStorage()->getStudentProfile(output->at(i)->value(keysList.at(z)));
                   QTableWidgetItem *studentName = new QTableWidgetItem(stu->getName());
                   QTableWidgetItem *studentId = new QTableWidgetItem(QString::number(stu->getID()));
                   //studentName->setTextAlignment(Qt::AlignCenter);
                   studentId->setTextAlignment(Qt::AlignCenter);
                   ui->outputTable->setItem(count, 0, studentName);
                   ui->outputTable->setItem(count, 1, studentId);

                   //output += stu->getName() +"\t\t"+ QString::number(stu->getID())+"\n";
                   ++count;
            }
        }

    }


}

QTableWidget* AlgorithmSummary::getTable(){
    return ui->outputTable;
}
