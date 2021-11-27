#ifndef PCB_H
#define PCB_H

#include <QObject>

class PCB{
public:
    QString PID;    //进程名
    int requiredRunningTime;    //所需运行时间
    int runningTime;    //运行时间
    int arrivalTime;    //到达时间
    int waitTime;   //等待时间
    int endTime;    //结束时间
    int suspendedTime;  //挂起时间
    int priority;   //优先级
    int occupiedMemorySize; //占用内存大小
    int mainmemoryStartingPosition; //主存起始位置
};

#endif // PCB_H
