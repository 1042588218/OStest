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
    modelArrive->setColumnCount(6);   //列数
    modelArrive->setHeaderData(0,Qt::Horizontal,"作业号");
    modelArrive->setHeaderData(1,Qt::Horizontal,"到达时间");
    modelArrive->setHeaderData(2,Qt::Horizontal,"需要时间");
    modelArrive->setHeaderData(3,Qt::Horizontal,"等待时间");
    modelArrive->setHeaderData(4,Qt::Horizontal,"优先级");
    modelArrive->setHeaderData(5,Qt::Horizontal,"主存大小");

    ui->tableViewArrival->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int row=0;
    for (int i=0;i<tmp.size();i++) {
        if(row==3){
            i--;
            modelArrive->setItem(row,0,new QStandardItem("--------"));
            modelArrive->setItem(row,1,new QStandardItem("--------"));
            modelArrive->setItem(row,2,new QStandardItem("--------"));
            modelArrive->setItem(row,3,new QStandardItem("--------"));
            modelArrive->setItem(row,4,new QStandardItem("--------"));
            modelArrive->setItem(row,5,new QStandardItem("--------"));
            row++;
            continue;
        }
        if(row<3&&tmp[i].arrivalTime>currentTime){
            i--;
            modelArrive->setItem(row,0,new QStandardItem("waiting"));
            row++;
            continue;
        }
        modelArrive->setItem(row,0,new QStandardItem(tmp[i].PID));
        modelArrive->setItem(row,1,new QStandardItem(QString::number(tmp[i].arrivalTime)));
        modelArrive->setItem(row,2,new QStandardItem(QString::number(tmp[i].requiredRunningTime)));
        modelArrive->setItem(row,3,new QStandardItem(QString::number(tmp[i].waitTime)));
        modelArrive->setItem(row,4,new QStandardItem(QString::number(tmp[i].priority)));
        modelArrive->setItem(row,5,new QStandardItem(QString::number(tmp[i].occupiedMemorySize)));
        row++;
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
    modelSuspended->setColumnCount(7);   //列数
    modelSuspended->setHeaderData(0,Qt::Horizontal,"作业号");
    modelSuspended->setHeaderData(1,Qt::Horizontal,"到达时间");
    modelSuspended->setHeaderData(2,Qt::Horizontal,"运行时间");
    modelSuspended->setHeaderData(3,Qt::Horizontal,"挂起时间");
    modelSuspended->setHeaderData(4,Qt::Horizontal,"优先级");
    modelSuspended->setHeaderData(5,Qt::Horizontal,"主存大小");
    modelSuspended->setHeaderData(6,Qt::Horizontal,"起始位置");

    ui->tableViewSuspended->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i=0;i<tmp.size();i++) {
        modelSuspended->setItem(i,0,new QStandardItem(tmp[i].PID));
        modelSuspended->setItem(i,1,new QStandardItem(QString::number(tmp[i].arrivalTime)));
        modelSuspended->setItem(i,2,new QStandardItem(QString::number(tmp[i].runningTime)));
        modelSuspended->setItem(i,3,new QStandardItem(QString::number(tmp[i].suspendedTime)));
        modelSuspended->setItem(i,4,new QStandardItem(QString::number(tmp[i].priority)));
        modelSuspended->setItem(i,5,new QStandardItem(QString::number(tmp[i].occupiedMemorySize)));
        modelSuspended->setItem(i,6,new QStandardItem(QString::number(tmp[i].mainmemoryStartingPosition)));
    }
    ui->tableViewSuspended->setModel(modelSuspended);
}

void MainWindow::setRunningOne(PCB *tmp)
{
    QStandardItemModel* model=new QStandardItemModel();
    model->setColumnCount(6);   //列数
    model->setHeaderData(0,Qt::Horizontal,"作业号");
    model->setHeaderData(1,Qt::Horizontal,"所需时间");
    model->setHeaderData(2,Qt::Horizontal,"运行时间");
    model->setHeaderData(3,Qt::Horizontal,"优先级");
    model->setHeaderData(4,Qt::Horizontal,"主存大小");
    model->setHeaderData(5,Qt::Horizontal,"起始位置");
    ui->progressBar->setValue(tmp->runningTime*100/tmp->requiredRunningTime);
    ui->tableViewRunningOne->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setItem(0,0,new QStandardItem(tmp->PID));
    model->setItem(0,1,new QStandardItem(QString::number(tmp->requiredRunningTime)));
    model->setItem(0,2,new QStandardItem(QString::number(tmp->runningTime)));
    model->setItem(0,3,new QStandardItem(QString::number(tmp->priority)));
    model->setItem(0,4,new QStandardItem(QString::number(tmp->occupiedMemorySize)));
    model->setItem(0,5,new QStandardItem(QString::number(tmp->mainmemoryStartingPosition)));
    ui->tableViewRunningOne->setModel(model);
}

void MainWindow::setRunningTwo(PCB *tmp)
{
    QStandardItemModel* model=new QStandardItemModel();
    model->setColumnCount(6);   //列数
    model->setHeaderData(0,Qt::Horizontal,"作业号");
    model->setHeaderData(1,Qt::Horizontal,"所需时间");
    model->setHeaderData(2,Qt::Horizontal,"运行时间");
    model->setHeaderData(3,Qt::Horizontal,"优先级");
    model->setHeaderData(4,Qt::Horizontal,"主存大小");
    model->setHeaderData(5,Qt::Horizontal,"起始位置");
    ui->progressBar_2->setValue(tmp->runningTime*100/tmp->requiredRunningTime);
    ui->tableViewRunningTwo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setItem(0,0,new QStandardItem(tmp->PID));
    model->setItem(0,1,new QStandardItem(QString::number(tmp->requiredRunningTime)));
    model->setItem(0,2,new QStandardItem(QString::number(tmp->runningTime)));
    model->setItem(0,3,new QStandardItem(QString::number(tmp->priority)));
    model->setItem(0,4,new QStandardItem(QString::number(tmp->occupiedMemorySize)));
    model->setItem(0,5,new QStandardItem(QString::number(tmp->mainmemoryStartingPosition)));
    ui->tableViewRunningTwo->setModel(model);
}

void MainWindow::setRunningThree(PCB *tmp)
{
    QStandardItemModel* model=new QStandardItemModel();
    model->setColumnCount(6);   //列数
    model->setHeaderData(0,Qt::Horizontal,"作业号");
    model->setHeaderData(1,Qt::Horizontal,"所需时间");
    model->setHeaderData(2,Qt::Horizontal,"运行时间");
    model->setHeaderData(3,Qt::Horizontal,"优先级");
    model->setHeaderData(4,Qt::Horizontal,"主存大小");
    model->setHeaderData(5,Qt::Horizontal,"起始位置");
    ui->progressBar_3->setValue(tmp->runningTime*100/tmp->requiredRunningTime);
    ui->tableViewRunningThree->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setItem(0,0,new QStandardItem(tmp->PID));
    model->setItem(0,1,new QStandardItem(QString::number(tmp->requiredRunningTime)));
    model->setItem(0,2,new QStandardItem(QString::number(tmp->runningTime)));
    model->setItem(0,3,new QStandardItem(QString::number(tmp->priority)));
    model->setItem(0,4,new QStandardItem(QString::number(tmp->occupiedMemorySize)));
    model->setItem(0,5,new QStandardItem(QString::number(tmp->mainmemoryStartingPosition)));
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

//bool MainWindow::compareFCFSData(const PCB &barAmount1, const PCB &barAmount2)
//{

//}

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
                if(usedMemory.contains(arrive[i].PID)){
                    usedMemory.value(arrive[i].PID)->hide();
                    //                for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                    //                    RAM[i]=0;
                    //                }
                    delete usedMemory.value(arrive[i].PID);
                    usedMemory.remove(arrive[i].PID);
                    num--;
                }
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

int MainWindow::judgeMemory(int occupiedMemorySize){
    if(num==0){
        return 0;
    }else{
        int j=0;
        for (int i=0;i<64;i++) {
            if(RAM[i]==0){
                j++;
            }else{
                j=0;
            }
            if(j==occupiedMemorySize){
                return i-j+1;
            }
        }
        return -1;
    }
}

PCB* MainWindow::runIfWaiting(PCB* runningOne){
    if(runningOne->PID=="waiting"){
        if(arrive.size()!=0&&arrive[0].arrivalTime<=currentTime){
            if(judgeMemory(arrive[0].occupiedMemorySize)!=-1||arrive[0].mainmemoryStartingPosition!=-1){
                runningOne=new PCB;
                *runningOne=arrive[0];
                arrive.removeAt(0);
                if(runningOne->mainmemoryStartingPosition==-1){
                    runningOne->mainmemoryStartingPosition=judgeMemory(arrive[0].occupiedMemorySize);
                    for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                        RAM[i]=1;
                    }
                    QPushButton *btn=new QPushButton(ui->RAM);
                    QStringList list;
                    list.append("background-color:gray;");
                    list.append("font-family:'宋体';font-size:32px;color:rgb(255,255,255,255)");
                    btn->setStyleSheet(list.join(';'));
                    btn->setText(runningOne->PID);
                    btn->move(0,runningOne->mainmemoryStartingPosition*10);
                    btn->resize(100,runningOne->occupiedMemorySize*10);
                    usedMemory.insert(runningOne->PID,btn);
                    num++;
                    btn->show();
                }
            }
        }
    }
    return runningOne;
}

PCB* MainWindow::runIfNotWaiting(PCB* runningOne){
    if(runningOne->PID!="waiting"){
        if(arrive.size()!=0&&runningOne->priority>arrive[0].priority&&arrive[0].arrivalTime<=currentTime){
            if(arrive[0].mainmemoryStartingPosition!=-1){
                PCB tmp=arrive[0];
                arrive[0]=*runningOne;
                *runningOne=tmp;
            }
            else if(judgeMemory(arrive[0].occupiedMemorySize)!=-1){
                PCB tmp=arrive[0];
                arrive[0]=*runningOne;
                *runningOne=tmp;
                runningOne->mainmemoryStartingPosition=judgeMemory(runningOne->occupiedMemorySize);
                //                state=false;
                for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                    RAM[i]=1;
                }
                QPushButton *btn=new QPushButton(ui->RAM);
                QStringList list;
                list.append("background-color:gray;");
                list.append("font-family:'宋体';font-size:32px;color:rgb(255,255,255,255)");
                btn->setStyleSheet(list.join(';'));
                btn->setText(runningOne->PID);
                btn->move(0,runningOne->mainmemoryStartingPosition*10);
                btn->resize(100,runningOne->occupiedMemorySize*10);
                btn->show();
                usedMemory.insert(runningOne->PID,btn);
                num++;
            }
            else{
                for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                    RAM[i]=0;
                }
                if(judgeMemory(arrive[0].occupiedMemorySize)!=-1){
                    PCB tmp=arrive[0];
                    arrive[0]=*runningOne;
                    arrive[0].mainmemoryStartingPosition=-1;
                    usedMemory.value(arrive[0].PID)->hide();
                    delete usedMemory.value(arrive[0].PID);
                    usedMemory.remove(arrive[0].PID);
                    num--;
                    *runningOne=tmp;
                    runningOne->mainmemoryStartingPosition=judgeMemory(runningOne->occupiedMemorySize);
                    //                state=false;
                    QPushButton *btn=new QPushButton(ui->RAM);
                    QStringList list;
                    list.append("background-color:gray;");
                    list.append("font-family:'宋体';font-size:32px;color:rgb(255,255,255,255)");
                    btn->setStyleSheet(list.join(';'));
                    btn->setText(runningOne->PID);
                    btn->move(0,runningOne->mainmemoryStartingPosition*10);
                    btn->resize(100,runningOne->occupiedMemorySize*10);
                    btn->show();
                    usedMemory.insert(runningOne->PID,btn);
                    num++;
                }else{
                    for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                        RAM[i]=1;
                    }
                }
            }
        }
        runningOne->runningTime++;
        if(runningOne->priority<10)runningOne->priority++;
        if(runningOne->runningTime==runningOne->requiredRunningTime){
            runningOne->endTime=currentTime+1;
            finish.append(*runningOne);
            for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                RAM[i]=0;
            }
            if(arrive.size()!=0&&arrive[0].arrivalTime<=currentTime/*&&(judgeMemory(arrive[0].occupiedMemorySize)!=-1||arrive[0].mainmemoryStartingPosition!=-1)*/){
                usedMemory.value(runningOne->PID)->hide();
                //                for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                //                    RAM[i]=0;
                //                }
                delete usedMemory.value(runningOne->PID);
                usedMemory.remove(runningOne->PID);
                num--;
                runningOne->mainmemoryStartingPosition=-1;
                if(arrive[0].mainmemoryStartingPosition==-1){
                    if(judgeMemory(arrive[0].occupiedMemorySize)!=-1){
                        *runningOne=arrive[0];
                        runningOne->mainmemoryStartingPosition=judgeMemory(arrive[0].occupiedMemorySize);
                        for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                            RAM[i]=1;
                        }
                        QPushButton *btn=new QPushButton(ui->RAM);
                        QStringList list;
                        list.append("background-color:gray;");
                        list.append("font-family:'宋体';font-size:32px;color:rgb(255,255,255,255)");
                        btn->setStyleSheet(list.join(';'));
                        btn->setText(runningOne->PID);
                        btn->move(0,runningOne->mainmemoryStartingPosition*10);
                        btn->resize(100,runningOne->occupiedMemorySize*10);
                        btn->show();
                        usedMemory.insert(runningOne->PID,btn);
                        num++;
                        arrive.removeAt(0);
                    }/*else{
                                                                arrive.swap(0,1);
                                                                if(judgeMemory(arrive[0].occupiedMemorySize)!=-1){
                                                                    *runningOne=arrive[0];
                                                                    runningOne->mainmemoryStartingPosition=judgeMemory(arrive[0].occupiedMemorySize);
                                                                    for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                                                                        RAM[i]=1;
                                                                    }
                                                                    QPushButton *btn=new QPushButton(ui->RAM);
                                                                    QStringList list;
                                                                    list.append("background-color:gray;");
                                                                    list.append("font-family:'宋体';font-size:32px;color:rgb(255,255,255,255)");
                                                                    btn->setStyleSheet(list.join(';'));
                                                                    btn->setText(runningOne->PID);
                                                                    btn->move(0,runningOne->mainmemoryStartingPosition*10);
                                                                    btn->resize(100,runningOne->occupiedMemorySize*10);
                                                                    btn->show();
                                                                    usedMemory.insert(runningOne->PID,btn);
                                                                    num++;
                                                                    arrive.removeAt(0);
                                                                }*//*else{
                                                                    runningOne=NOTHING;
                                                                }*/
                    //                    }
                }else{
                    *runningOne=arrive[0];
                    arrive.removeAt(0);
                }
            }else{
                if(runningOne->PID!="waiting"){
                    usedMemory.value(runningOne->PID)->hide();
                    for(int i=runningOne->mainmemoryStartingPosition;i<runningOne->mainmemoryStartingPosition+runningOne->occupiedMemorySize-1;i++){
                        RAM[i]=0;
                    }
                    delete usedMemory.value(runningOne->PID);
                    usedMemory.remove(runningOne->PID);
                    num--;
                    runningOne->mainmemoryStartingPosition=-1;
                }
                runningOne=NOTHING;
            }
            //                state=false;
        }
    }
    return runningOne;
}
