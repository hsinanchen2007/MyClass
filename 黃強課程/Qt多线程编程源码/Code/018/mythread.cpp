#include "mythread.h"
#include<QMutex>
#include<QMutexLocker>

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
        // QMutexLocker 构造的时候需要传入一个QMutex
        // 并且构造的时候自动帮我们加锁，调用QMutex的lock
        //说白了，它只是个壳子，真正干活的还是QMutex

        {
               QMutexLocker  m(&mutex);


                if(tickets>0)
                {
                    //避免有一个线程一直占用CPU
                    QThread::msleep(1);

                    qDebug()<<name <<QStringLiteral("卖出了票")<<tickets;

                    //线程可能在这里完毕CPU时间片，此时暂停

                    //减少一张票
                    -- tickets;
                }

                //QMutexLocker对象销毁的时候，自动调用QMutex的unlock

        }//对象m出了作用域，销毁


    }

}
