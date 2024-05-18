#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QDebug>

class MyThread : public QThread
{
public:
    //构造线程，指定线程名称和优先级
    MyThread(QString name , Priority pri);
    void run() override;

    public:
    QString name;
    Priority pri;

    //耗费的总时间,CPU调度的越多，你完成同样的任务花费的时间就少
    int  costTime=0;
};

#endif // MYTHREAD_H
