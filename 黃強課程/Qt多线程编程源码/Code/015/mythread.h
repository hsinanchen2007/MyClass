#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>
#include<QThreadStorage>
#include<QDebug>

class MyThread : public QThread
{
public:
    MyThread();


    void run() override;
};

#endif // MYTHREAD_H
