#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QDebug>

class MyThread : public QThread
{
public:
    //为了方便区别是哪条线程
    MyThread(QString name,int time);

    void run() override;

private:
    QString name;
    int time;
};

#endif // MYTHREAD_H
