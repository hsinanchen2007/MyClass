#ifndef MYTHREAD_H
#define MYTHREAD_H
#include"test.h"
#include<QThread>
#include<QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

    void run() override;

    Test * test; //必须要在run里面new 才算 子线程的对象
};

#endif // MYTHREAD_H
