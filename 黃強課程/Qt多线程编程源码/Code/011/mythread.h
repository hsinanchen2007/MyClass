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

    Test * test; //����Ҫ��run����new ���� ���̵߳Ķ���
};

#endif // MYTHREAD_H
