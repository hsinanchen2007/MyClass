#include "mythread.h"
#include<QTime>

MyThread::MyThread(QString name,Priority pri)
{
   this->name= name;
    this->pri= pri;
}

void  MyThread::run( )
{
    //设置线程的优先级
    setPriority(pri);

    QTime time;
    time.start();//开始计时

    //线程执行指定的任务
    qint64  sum= 0;
    for(int i=0;i<100000;++i)
    {
        for(int j=0;j<10000;++j)
        {
            sum+=1;
        }
    }

    costTime+= time.elapsed();//耗时

}
