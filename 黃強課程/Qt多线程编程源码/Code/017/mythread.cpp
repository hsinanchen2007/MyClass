#include "mythread.h"
#include<QMutex>

//现在有100张票资源
int tickets= 100;

//采用QMutex来保证一次只能一个线程访问该代码
QMutex  mutex;


MyThread::MyThread(QString name)
{
   this->name = name;
}


void MyThread::run()
{
    while(tickets>0)
    {
        //加锁，A线程加锁后，如果B线程调用lock加锁，就会阻塞
        //除非A线程unlock解锁后， B线程才会停止阻塞
        mutex.lock();

        if(tickets>0)
        {
            //避免有一个线程一直占用CPU
            QThread::msleep(1);

            qDebug()<<name <<QStringLiteral("卖出了票")<<tickets;

            //线程可能在这里完毕CPU时间片，此时暂停

            //减少一张票
            -- tickets;
        }

        //解锁
        mutex.unlock();

    }

}
