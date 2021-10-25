#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <stdio.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog::on_pushButton_clicked()
{
    if(ui->lineEditPid->text()==""||
       ui->lineEditArrivalTime->text()==""||
       ui->lineEditPriority->text()==""||
       ui->lineEditRequiredRunningTime->text()==""){
        QMessageBox::critical(0 , "错误警告" , "输入不合法！", QMessageBox::Ok | QMessageBox::Default , 0 );
        return;
    }
    PCB* tmp=new PCB;
    tmp->PID=ui->lineEditPid->text();
    tmp->arrivalTime=ui->lineEditArrivalTime->text().toInt();
    tmp->priority=ui->lineEditPriority->text().toInt();
    tmp->requiredRunningTime=ui->lineEditRequiredRunningTime->text().toInt();
    emit getNewPcb(tmp);
    this->close();
}
