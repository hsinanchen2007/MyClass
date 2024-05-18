#include "mythread.h"

MyThread::MyThread(QString name,int time)
{
    this->name= name;
    this->time= time;
}


void MyThread::run( )
{
    qDebug()<<name<<QStringLiteral("开始执行了！");

    QThread::sleep(time);//模拟线程执行消耗的时间

    qDebug()<<name<<QStringLiteral("结束了！");
}
