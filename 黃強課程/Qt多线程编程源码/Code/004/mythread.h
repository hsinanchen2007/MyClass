#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>

//��ʽһ
//��һ��������һ���࣬�̳���QThread
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

    //�ڶ��������߳�Ҫִ�е�����д��run����
     virtual void run();
};

#endif // MYTHREAD_H
