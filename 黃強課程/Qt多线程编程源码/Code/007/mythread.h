#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QDebug>
#include<QThread>

class MyThread : public QThread
{
public:
    MyThread();
    void run() override;

    bool  flag = true;//����߳��Ƿ��ܼ���ִ��
};

#endif // MYTHREAD_H
