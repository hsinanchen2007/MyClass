#include "mythread.h"


//定义互斥锁，保护资源互斥
//QMutex  mutex;

//递归互斥锁，可以多次的lock，保证unlock次数与lock次数一致就可以了
QRecursiveMutex  mutex;



MyThread::MyThread()
{

}

void  MyThread::run()
{
    qDebug()<<QStringLiteral("run()开始 ");
    fun2();
    qDebug()<<QStringLiteral("run()结束 ");
}

void MyThread::fun1()
{
      mutex.lock();
      qDebug()<<"fun1() ";
      mutex.unlock();
}
void MyThread::fun2()
{
     mutex.lock();
     qDebug()<<"fun2() ";
     //需要fun1的功能
     fun1();
     mutex.unlock();
}

