#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QDebug>

class MyThread : public QThread
{
public:
    //�����̣߳�ָ���߳����ƺ����ȼ�
    MyThread(QString name , Priority pri);
    void run() override;

    public:
    QString name;
    Priority pri;

    //�ķѵ���ʱ��,CPU���ȵ�Խ�࣬�����ͬ�������񻨷ѵ�ʱ�����
    int  costTime=0;
};

#endif // MYTHREAD_H
