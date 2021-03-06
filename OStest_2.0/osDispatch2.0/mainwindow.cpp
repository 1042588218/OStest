#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "pcb.h"
#include <QButtonGroup>
#include <QStandardItemModel>
#include <QTime>
#include <qabstractitemview.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    arrive.clear();
    finish.clear();
    suspended.clear();
    usedMemory.clear();
    ui->setupUi(this);
    ui->tableViewArrival->setAlternatingRowColors(true);
    ui->tableViewFinish->setAlternatingRowColors(true);
    ui->tableViewSuspended->setAlternatingRowColors(true);
    ui->tableViewArrival->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewFinish->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewSuspended->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView* headerView = ui->tableViewArrival->verticalHeader();
    headerView->setHidden(true);
    QHeaderView* headerView1 = ui->tableViewFinish->verticalHeader();
    headerView1->setHidden(true);
    QHeaderView* headerView2 = ui->tableViewSuspended->verticalHeader();
    headerView2->setHidden(true);
    
    QHeaderView* headerView3 = ui->tableViewRunningOne->verticalHeader();
    headerView3->setHidden(true);
    QHeaderView* headerView4 = ui->tableViewRunningTwo->verticalHeader();
    headerView4->setHidden(true);
    QHeaderView* headerView5 = ui->tableViewRunningThree->verticalHeader();
    headerView5->setHidden(true);
    
    QButtonGroup *CPUButton=new QButtonGroup(this);
    CPUButton->addButton(ui->radioButton_2);
    CPUButton->addButton(ui->radioButton);
    ui->radioButton_2->setChecked(true);
    
    ui->label_9->setVisible(false);
    ui->labelCurrentTime->setVisible(false);
    
    NOTHING=new PCB;
    NOTHING->PID="waiting";
    NOTHING->requiredRunningTime=-1;
    NOTHING->runningTime=0;
    NOTHING->priority=-1;
    NOTHING->occupiedMemorySize=0;
    NOTHING->mainmemoryStartingPosition=0;
    runningOne=NOTHING;
    runningTwo=NOTHING;
    runningThree=NOTHING;
    setRunningOne(runningOne);
    setRunningTwo(runningTwo);
    setRunningThree(runningThree);
    for (int i=0;i<64;i++) {
        RAM[i]=0;
    }
    
    adjustArrivalQueue(arrive);
    adjustFinishQueue(finish);
    adjustSuspendedQueue(suspended);
    dialog=new Dialog(this);
    dialogSuspended=new DialogSuspended(this);
    dialogResult=new DialogResult(this);
    connect(dialog,SIGNAL(getNewPcb(PCB*)),this,SLOT(getPCB(PCB*)));
    connect(dialogSuspended,SIGNAL(getPid(QString)),this,SLOT(suspendPCB(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addPushButton_clicked()
{
    dialog->setModal(true);
    dialog->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    for(int i=0;i<4;i++){
        PCB tmp;
        tmp.PID=QString::number(arrive.size()+1);
        tmp.arrivalTime=qrand()%9+1;
        tmp.requiredRunningTime=qrand()%9+1;
        tmp.priority=qrand()%9+1;
        tmp.occupiedMemorySize=qrand()%10+10;
        tmp.mainmemoryStartingPosition=-1;
        arrive.append(tmp);
    }
    //    if(ui->radioButtonPriority->isChecked()){
    QList<PCB> arrivePart;
    QList<PCB> notArrivePart;
    for(int i=0;i<arrive.size();i++){
        if(arrive[i].arrivalTime<currentTime){
            notArrivePart.append(arrive[i]);
        }else{
            arrivePart.append(arrive[i]);
        }
    }
    qSort(arrivePart.begin(),arrivePart.end(),comparePriorityData);
    qSort(notArrivePart.begin(),notArrivePart.end(),comparePriorityData);
    arrivePart.append(notArrivePart);
    arrive=arrivePart;
    //    }
    //    else if(ui->radioButtonFCFS->isChecked()){
    //        qSort(arrive.begin(),arrive.end(),compareFCFSData);
    //    }
    adjustArrivalQueue(arrive);
}

void MainWindow::on_runOneSecond_clicked()
{
    //    bool state=true;
    ui->pushButton_6->setEnabled(false);
    //    ui->radioButtonPriority->setEnabled(false);
    //    ui->radioButtonFCFS->setEnabled(false);
    //    ui->radioButtonSJF->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    
    ui->addPushButton->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    //    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->runOneSecond->setEnabled(false);
    //    if(ui->radioButtonPriority->isChecked()){
    //    while (true) {
    if(ui->radioButton->isChecked()){
        runningOne=runIfWaiting(runningOne);
        runningTwo=runIfWaiting(runningTwo);
        runningThree=runIfWaiting(runningThree);
        //        QTime dieTime = QTime::currentTime().addMSecs(2000);
        //        while( QTime::currentTime() < dieTime )
        //          QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        runningOne=runIfNotWaiting(runningOne);
        runningTwo=runIfNotWaiting(runningTwo);
        runningThree=runIfNotWaiting(runningThree);
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
        setRunningOne(runningOne);
        setRunningTwo(runningTwo);
        setRunningThree(runningThree);
        adjustArrivalQueue(arrive);
        adjustFinishQueue(finish);
        adjustSuspendedQueue(suspended);
        if(suspended.size()>0){
            for(int i=0;i<suspended.size();i++)suspended[i].suspendedTime++;
        }
        currentTime++;
        ui->label_9->setVisible(true);
        ui->labelCurrentTime->setVisible(true);
        ui->labelCurrentTime->setText(QString::number(currentTime));
    }else{
        ui->tableViewRunningOne->setEnabled(true);
        ui->tableViewRunningThree->setEnabled(true);
        runningTwo=runIfWaiting(runningTwo);
        //        }
        //        QTime dieTime = QTime::currentTime().addMSecs(2000);
        //        while( QTime::currentTime() < dieTime )
        //          QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        
        //????????????????????????????????????????????????????????????
        //        if(runningTwo->PID!="waiting"){
        //            if(arrive.size()!=0&&runningTwo->priority>arrive[0].priority&&arrive[0].arrivalTime<=currentTime){
        //                PCB tmp=arrive[0];
        //                arrive[0]=*runningTwo;
        //                *runningTwo=tmp;
        //                //                state=false;
        //            }
        //            runningTwo->runningTime++;
        //            if(runningTwo->priority<10)runningTwo->priority++;
        //            if(runningTwo->runningTime==runningTwo->requiredRunningTime){
        //                runningTwo->endTime=currentTime+1;
        //                finish.append(*runningTwo);
        //                if(arrive.size()!=0&&arrive[0].arrivalTime<=currentTime){
        //                    *runningTwo=arrive[0];
        //                    arrive.removeAt(0);
        //                }else{
        //                    runningTwo=NOTHING;
        //                }
        //                //                state=false;
        //            }
        
        //        }
        runningTwo=runIfNotWaiting(runningTwo);
        
        //??????
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
        setRunningTwo(runningTwo);
        adjustArrivalQueue(arrive);
        adjustFinishQueue(finish);
        adjustSuspendedQueue(suspended);
        
        //????????????
        if(suspended.size()>0){
            for(int i=0;i<suspended.size();i++)suspended[i].suspendedTime++;
        }
        currentTime++;
        ui->label_9->setVisible(true);
        ui->labelCurrentTime->setVisible(true);
        ui->labelCurrentTime->setText(QString::number(currentTime));
    }
    //        if(!state)break;
    //    }
    //    }
    //    else if(ui->radioBut)
    if(arrive.size()==0&&suspended.size()==0&&finish.size()!=0&&runningOne->PID=="waiting"&&runningTwo->PID=="waiting"&&runningThree->PID=="waiting"){
        ui->pushButton_10->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
        //        ui->radioButtonPriority->setEnabled(false);
        //        ui->radioButtonFCFS->setEnabled(false);
        //        ui->radioButtonSJF->setEnabled(false);
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        ui->addPushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        //        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->runOneSecond->setEnabled(false);
        return;
    }else ui->pushButton_10->setEnabled(false);
    
    ui->addPushButton->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    //    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->runOneSecond->setEnabled(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_6->setEnabled(false);
    //    ui->radioButtonPriority->setEnabled(false);
    //    ui->radioButtonFCFS->setEnabled(false);
    //    ui->radioButtonSJF->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    
    ui->addPushButton->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    //    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->runOneSecond->setEnabled(false);
    //    while (true) {
    //    if(ui->radioButtonPriority->isChecked()){
    if(ui->radioButton->isChecked()){
        while (arrive.size()!=0||runningOne->PID!="waiting"||runningTwo->PID!="waiting"||runningThree->PID!="waiting") {
            runningOne=runIfWaiting(runningOne);
            runningTwo=runIfWaiting(runningTwo);
            runningThree=runIfWaiting(runningThree);
            
            //        QTime dieTime = QTime::currentTime().addMSecs(2000);
            //        while( QTime::currentTime() < dieTime )
            //          QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            
            runningOne=runIfNotWaiting(runningOne);
            runningTwo=runIfNotWaiting(runningTwo);
            runningThree=runIfNotWaiting(runningThree);
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
            setRunningOne(runningOne);
            setRunningTwo(runningTwo);
            setRunningThree(runningThree);
            adjustArrivalQueue(arrive);
            adjustFinishQueue(finish);
            adjustSuspendedQueue(suspended);
            QTime dieTime = QTime::currentTime().addMSecs(1000);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            if(suspended.size()>0){
                for(int i=0;i<suspended.size();i++)suspended[i].suspendedTime++;
            }
            currentTime++;
            ui->label_9->setVisible(true);
            ui->labelCurrentTime->setVisible(true);
            ui->labelCurrentTime->setText(QString::number(currentTime));
        }
    }else{
        while (arrive.size()!=0||runningTwo->PID!="waiting") {
            ui->tableViewRunningOne->setEnabled(true);
            ui->tableViewRunningThree->setEnabled(true);
            runningTwo=runIfWaiting(runningTwo);
            //        QTime dieTime = QTime::currentTime().addMSecs(2000);
            //        while( QTime::currentTime() < dieTime )
            //          QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            
            //????????????????????????????????????????????????????????????
            runningTwo=runIfNotWaiting(runningTwo);
            
            //??????
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
            setRunningTwo(runningTwo);
            adjustArrivalQueue(arrive);
            adjustFinishQueue(finish);
            adjustSuspendedQueue(suspended);
            
            QTime dieTime = QTime::currentTime().addMSecs(1000);
            while( QTime::currentTime() < dieTime )
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            //????????????
            if(suspended.size()>0){
                for(int i=0;i<suspended.size();i++)suspended[i].suspendedTime++;
            }
            currentTime++;
            ui->label_9->setVisible(true);
            ui->labelCurrentTime->setVisible(true);
            ui->labelCurrentTime->setText(QString::number(currentTime));
        }
    }
    //    }
    if(arrive.size()==0&&suspended.size()==0&&finish.size()!=0&&runningOne->PID=="waiting"&&runningTwo->PID=="waiting"&&runningThree->PID=="waiting"){
        ui->pushButton_10->setEnabled(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
        //        ui->radioButtonPriority->setEnabled(false);
        //        ui->radioButtonFCFS->setEnabled(false);
        //        ui->radioButtonSJF->setEnabled(false);
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        ui->addPushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        //        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->runOneSecond->setEnabled(false);
        return;
    }else ui->pushButton_10->setEnabled(false);
    //        if(!state)break;
    //    }
    ui->addPushButton->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    //    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->runOneSecond->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    arrive.clear();
    finish.clear();
    suspended.clear();
    runningOne=NOTHING;
    runningTwo=NOTHING;
    runningThree=NOTHING;
    num=0;
    usedMemory.clear();
    currentTime=0;
    ui->label_9->setVisible(false);
    ui->labelCurrentTime->setVisible(false);
    ui->labelCurrentTime->setText(QString::number(currentTime));
    ui->pushButton_6->setEnabled(true);
    //    ui->radioButtonPriority->setEnabled(true);
    //    ui->radioButtonFCFS->setEnabled(true);
    //    ui->radioButtonSJF->setEnabled(true);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    
    ui->addPushButton->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    //    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->runOneSecond->setEnabled(true);
    setRunningOne(runningOne);
    setRunningTwo(runningTwo);
    setRunningThree(runningThree);
    adjustArrivalQueue(arrive);
    adjustFinishQueue(finish);
    adjustSuspendedQueue(suspended);
}

void MainWindow::on_pushButton_5_clicked()
{
    state=0;
    dialogSuspended->setModal(true);
    dialogSuspended->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    state=1;
    dialogSuspended->setModal(true);
    dialogSuspended->show();
}

void MainWindow::on_pushButton_10_clicked()
{
    dialogResult->setModal(true);
    dialogResult->show();
    dialogResult->getResult(finish);
}
