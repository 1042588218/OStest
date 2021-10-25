#include "dialogresult.h"
#include "ui_dialogresult.h"

DialogResult::DialogResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogResult)
{
    ui->setupUi(this);
}

DialogResult::~DialogResult()
{
    delete ui;
}

void DialogResult::getResult(QList<PCB> finish)
{
    int turnaroundTime=0;
    int waitingTime=0;
    float weightedTurnaroundTime;
    for(int i=0;i<finish.size();i++){
        turnaroundTime+=(finish[i].endTime-finish[i].arrivalTime);
        waitingTime+=finish[i].waitTime;
        weightedTurnaroundTime=(float)(finish[i].endTime-finish[i].arrivalTime)/(float)(finish[i].runningTime);
    }
    ui->lineEdit->setText(QString::number((double)turnaroundTime/(double)finish.size()));
    ui->lineEdit_2->setText(QString::number((double)weightedTurnaroundTime/(double)finish.size()));
    ui->lineEdit_3->setText(QString::number((double)waitingTime/(double)finish.size()));
}

void DialogResult::on_pushButton_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    this->close();
}
