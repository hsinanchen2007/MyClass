#include "carthread.h"

CarThread::CarThread(   QString name)
{
   this->name =name;
}

//互斥锁的作用，对一个资源进行互斥保护
//QMutex  mutex;


//信号量的作用，允许N个线程同时访问资源
QSemaphore sem(3);//模拟3个车位，同时允许3个线程来分别占用3个车位

//QMutex  等价于  QSemaphore sem(1)

void CarThread::run()
{

    while(true)
    {

        sem.acquire();//线程减少一个资源数

       qDebug()<<name<<QStringLiteral("进入车位!");
       QThread::sleep(3);//停车时间
       qDebug()<<name<<QStringLiteral("离开车位!");

       sem.release();//释放一个车位
    }
}
