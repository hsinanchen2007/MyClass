#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QDebug>

class MyThread : public QThread
{
public:
    //Ϊ�˷��������������߳�
    MyThread(QString name,int time);

    void run() override;

private:
    QString name;
    int time;
};

#endif // MYTHREAD_H
