#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

    //��run��������ִ�к�ʱ����
    void run() override;

    //�����ź�
signals:
    void mySig(QString  num);
};

#endif // MYTHREAD_H
