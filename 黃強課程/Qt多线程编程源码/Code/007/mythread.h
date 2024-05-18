#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QDebug>
#include<QThread>

class MyThread : public QThread
{
public:
    MyThread();
    void run() override;

    bool  flag = true;//标记线程是否能继续执行
};

#endif // MYTHREAD_H
