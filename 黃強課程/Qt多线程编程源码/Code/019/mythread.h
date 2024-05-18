#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QDebug>
#include<QMutex>
#include<QRecursiveMutex>

class MyThread : public QThread
{
public:
    MyThread();

    void run() override;


    void fun1();
    void fun2();

};

#endif // MYTHREAD_H
