#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "dialog.h"
#include "pcb.h"
#include "dialogsuspended.h"
#include "dialogresult.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Dialog* dialog;
    DialogSuspended* dialogSuspended;
    DialogResult* dialogResult;
    QList<PCB> arrive;  //到达队列
    QList<PCB> finish;  //完成队列
    QList<PCB> suspended;   //挂起队列

    int state=0;
    int currentTime=0;
    PCB* NOTHING;

    PCB* runningOne;
    PCB* runningTwo;
    PCB* runningThree;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //dao包内部工具函数
    void adjustArrivalQueue(QList<PCB> tmp);
    void adjustFinishQueue(QList<PCB> tmp);
    void adjustSuspendedQueue(QList<PCB> tmp);
    void setRunningOne(PCB* tmp);
    void setRunningTwo(PCB* tmp);
    void setRunningThree(PCB* tmp);
    static bool comparePriorityData(const PCB &barAmount1, const PCB &barAmount2);
    static bool compareTimeSliceData(const PCB &barAmount1, const PCB &barAmount2);

private slots:
    void getPCB(PCB* tmp);
    void suspendPCB(QString tmp);
    void on_addPushButton_clicked();
    void on_pushButton_6_clicked();
    void on_runOneSecond_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
signals:
    void getNewPcb(PCB* tmp);
};

#endif // MAINWINDOW_H
