#include "mythread.h"
#include<QTime>

MyThread::MyThread(QString name,Priority pri)
{
   this->name= name;
    this->pri= pri;
}

void  MyThread::run( )
{
    //�����̵߳����ȼ�
    setPriority(pri);

    QTime time;
    time.start();//��ʼ��ʱ

    //�߳�ִ��ָ��������
    qint64  sum= 0;
    for(int i=0;i<100000;++i)
    {
        for(int j=0;j<10000;++j)
        {
            sum+=1;
        }
    }

    costTime+= time.elapsed();//��ʱ

}
