#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

    //在run方法里面执行耗时操作
    void run() override;

    //定义信号
signals:
    void mySig(QString  num);
};

#endif // MYTHREAD_H
