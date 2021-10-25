#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pcb.h"
#include <QObject>
#include <QMainWindow>
#include <qstandarditemmodel.h>
#include <qdebug.h>
#include <QMessageBox>

//用于更新到达队列
void MainWindow::adjustArrivalQueue(QList<PCB> tmp){
    QStandardItemModel* modelArrive=new QStandardItemModel();
    modelArrive->setColumnCount(5);   //列数
    modelArrive->setHeaderData(0,Qt::Horizontal,"作业号");
    modelArrive->setHeaderData(1,Qt::Horizontal,"到达时间");
    modelArrive->setHeaderData(2,Qt::Horizontal,"需要时间");
    modelArrive->setHeaderData(3,Qt::Horizontal,"等待时间");
    modelArrive->setHeaderData(4,Qt::Horizontal,"优先级");
    ui->tableViewArrival->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i=0;i<tmp.size();i++) {
       modelArrive->setItem(i,0,new QStandardItem(tmp[i].PID));
       modelArrive->setItem(i,1,new QStandardItem(QString::number(tmp[i].arrivalTime)));
       modelArrive->setItem(i,2,new QStandardItem(QString::number(tmp[i].requiredRunningTime)));
       modelArrive->setItem(i,3,new QStandardItem(QString::number(tmp[i].waitTime)));
       modelArrive->setItem(i,4,new QStandardItem(QString::number(tmp[i].priority)));
    }
    ui->tableViewArrival->setModel(modelArrive);
}

//用于更新完成队列
void MainWindow::adjustFinishQueue(QList<PCB> tmp){
    QStandardItemModel* modelFinish=new QStandardItemModel();
    modelFinish->setColumnCount(5);   //列数
    modelFinish->setHeaderData(0,Qt::Horizontal,"作业号");
    modelFinish->setHeaderData(1,Qt::Horizontal,"到达时间");
    modelFinish->setHeaderData(2,Qt::Horizontal,"运行时间");
    modelFinish->setHeaderData(3,Qt::Horizontal,"完成时间");
    modelFinish->setHeaderData(4,Qt::Horizontal,"优先级");
    ui->tableViewFinish->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i=0;i<tmp.size();i++) {
       modelFinish->setItem(i,0,new QStandardItem(tmp[i].PID));
       modelFinish->setItem(i,1,new QStandardItem(QString::number(tmp[i].arrivalTime)));
       modelFinish->setItem(i,2,new QStandardItem(QString::number(tmp[i].runningTime)));
       modelFinish->setItem(i,3,new QStandardItem(QString::number(tmp[i].endTime)));
       modelFinish->setItem(i,4,new QStandardItem(QString::number(tmp[i].priority)));
    }
    ui->tableViewFinish->setModel(modelFinish);
}

//用于更新挂起队列
void MainWindow::adjustSuspendedQueue(QList<PCB> tmp){
    QStandardItemModel* modelSuspended=new QStandardItemModel();
    modelSuspended->setColumnCount(5);   //列数
    modelSuspended->setHeaderData(0,Qt::Horizontal,"作业号");
    modelSuspended->setHeaderData(1,Qt::Horizontal,"到达时间");
    modelSuspended->setHeaderData(2,Qt::Horizontal,"运行时间");
    modelSuspended->setHeaderData(3,Qt::Horizontal,"挂起时间");
    modelSuspended->setHeaderData(4,Qt::Horizontal,"优先级");
    ui->tableViewSuspended->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i=0;i<tmp.size();i++) {
       modelSuspended->setItem(i,0,new QStandardItem(tmp[i].PID));
       modelSuspended->setItem(i,1,new QStandardItem(QString::number(tmp[i].arrivalTime)));
       modelSuspended->setItem(i,2,new QStandardItem(QString::number(tmp[i].runningTime)));
       modelSuspended->setItem(i,3,new QStandardItem(QString::number(tmp[i].suspendedTime)));
       modelSuspended->setItem(i,4,new QStandardItem(QString::number(tmp[i].priority)));
    }
    ui->tableViewSuspended->setModel(modelSuspended);
}

void MainWindow::setRunningOne(PCB *tmp)
{
    QStandardItemModel* model=new QStandardItemModel();
    model->setColumnCount(4);   //列数
    model->setHeaderData(0,Qt::Horizontal,"作业号");
    model->setHeaderData(1,Qt::Horizontal,"所需时间");
    model->setHeaderData(2,Qt::Horizontal,"运行时间");
    model->setHeaderData(3,Qt::Horizontal,"优先级");
    ui->progressBar->setValue(tmp->runningTime*100/tmp->requiredRunningTime);
    ui->tableViewRunningOne->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       model->setItem(0,0,new QStandardItem(tmp->PID));
       model->setItem(0,1,new QStandardItem(QString::number(tmp->requiredRunningTime)));
       model->setItem(0,2,new QStandardItem(QString::number(tmp->runningTime)));
       model->setItem(0,3,new QStandardItem(QString::number(tmp->priority)));
    ui->tableViewRunningOne->setModel(model);
}

void MainWindow::setRunningTwo(PCB *tmp)
{
    QStandardItemModel* model=new QStandardItemModel();
    model->setColumnCount(4);   //列数
    model->setHeaderData(0,Qt::Horizontal,"作业号");
    model->setHeaderData(1,Qt::Horizontal,"所需时间");
    model->setHeaderData(2,Qt::Horizontal,"运行时间");
    model->setHeaderData(3,Qt::Horizontal,"优先级");
    ui->progressBar_2->setValue(tmp->runningTime*100/tmp->requiredRunningTime);
    ui->tableViewRunningTwo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       model->setItem(0,0,new QStandardItem(tmp->PID));
       model->setItem(0,1,new QStandardItem(QString::number(tmp->requiredRunningTime)));
       model->setItem(0,2,new QStandardItem(QString::number(tmp->runningTime)));
       model->setItem(0,3,new QStandardItem(QString::number(tmp->priority)));
    ui->tableViewRunningTwo->setModel(model);
}

void MainWindow::setRunningThree(PCB *tmp)
{
    QStandardItemModel* model=new QStandardItemModel();
    model->setColumnCount(4);   //列数
    model->setHeaderData(0,Qt::Horizontal,"作业号");
    model->setHeaderData(1,Qt::Horizontal,"所需时间");
    model->setHeaderData(2,Qt::Horizontal,"运行时间");
    model->setHeaderData(3,Qt::Horizontal,"优先级");
    ui->progressBar_3->setValue(tmp->runningTime*100/tmp->requiredRunningTime);
    ui->tableViewRunningThree->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       model->setItem(0,0,new QStandardItem(tmp->PID));
       model->setItem(0,1,new QStandardItem(QString::number(tmp->requiredRunningTime)));
       model->setItem(0,2,new QStandardItem(QString::number(tmp->runningTime)));
       model->setItem(0,3,new QStandardItem(QString::number(tmp->priority)));
    ui->tableViewRunningThree->setModel(model);
}

bool MainWindow::comparePriorityData(const PCB &barAmount1, const PCB &barAmount2)
{
    if(barAmount1.priority<barAmount2.priority){
        return true;
    }
    else if(barAmount1.priority==barAmount2.priority){
        return barAmount1.requiredRunningTime<barAmount2.requiredRunningTime;
    }
    return false;
}

bool MainWindow::compareTimeSliceData(const PCB &barAmount1, const PCB &barAmount2)
{

}

//bool MainWindow::compareBarData(const PCB &barAmount1, const PCB &barAmount2){
//    if (barAmount1.arrivalTime < barAmount2.arrivalTime){
//            return true;
//    }
//    else if(barAmount1.arrivalTime == barAmount2.arrivalTime){
//        return barAmount1.PID<barAmount2.PID;
//    }
//      return false;
//}

void MainWindow::getPCB(PCB *tmp)
{
    arrive.append(*tmp);
    if(arrive.size()>0){
        for(int i=0;arrive.size()>i&&arrive[i].arrivalTime<=currentTime;i++)arrive[i].waitTime++;
        QList<PCB> arrivePart;
        QList<PCB> notArrivePart;
        for(int i=0;i<arrive.size();i++){
            if(arrive[i].arrivalTime>currentTime){
                notArrivePart.append(arrive[i]);
            }else{
                arrivePart.append(arrive[i]);
            }
        }
        qSort(arrivePart.begin(),arrivePart.end(),comparePriorityData);
        qSort(notArrivePart.begin(),notArrivePart.end(),comparePriorityData);
        arrivePart.append(notArrivePart);
        arrive=arrivePart;
    }
    adjustArrivalQueue(arrive);
}

void MainWindow::suspendPCB(QString tmp)
{
    if(state==0){
        for(int i=0;i<arrive.size();i++){
            if(arrive[i].PID==tmp){
                suspended.append(arrive[i]);
                arrive.removeAt(i);
                adjustArrivalQueue(arrive);
                adjustFinishQueue(finish);
                adjustSuspendedQueue(suspended);
                return;
            }
        }
        QMessageBox::critical(0 , "错误警告" , "输入不合法！", QMessageBox::Ok | QMessageBox::Default , 0 );
    }else{
        for(int i=0;i<suspended.size();i++){
            if(suspended[i].PID==tmp){
                arrive.append(suspended[i]);
                suspended.removeAt(i);
                if(arrive.size()>0){
                    for(int i=0;arrive.size()>i&&arrive[i].arrivalTime<=currentTime;i++)arrive[i].waitTime++;
                    QList<PCB> arrivePart;
                    QList<PCB> notArrivePart;
                    for(int i=0;i<arrive.size();i++){
                        if(arrive[i].arrivalTime>currentTime){
                            notArrivePart.append(arrive[i]);
                        }else{
                            arrivePart.append(arrive[i]);
                        }
                    }
                    qSort(arrivePart.begin(),arrivePart.end(),comparePriorityData);
                    qSort(notArrivePart.begin(),notArrivePart.end(),comparePriorityData);
                    arrivePart.append(notArrivePart);
                    arrive=arrivePart;
                }
                adjustArrivalQueue(arrive);
                adjustFinishQueue(finish);
                adjustSuspendedQueue(suspended);
                return;
            }
        }
        QMessageBox::critical(0 , "错误警告" , "输入不合法！", QMessageBox::Ok | QMessageBox::Default , 0 );
    }
}
