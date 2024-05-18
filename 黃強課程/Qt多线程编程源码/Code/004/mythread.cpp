#include "mythread.h"
#include<QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
 {
    qDebug()<<QStringLiteral("子线程ID ")<<QThread::currentThreadId();


     qDebug()<<QStringLiteral("线程开始执行了!");

     for(int i=0;i<100;++i)
     {
         qDebug()<<i;
         //睡眠10ms，放在占用大量CPU
         QThread::msleep(10);
     }

      qDebug()<<QStringLiteral("线程结束了！");
      qDebug()<<QStringLiteral("做一些资源清理工作！");
 }
