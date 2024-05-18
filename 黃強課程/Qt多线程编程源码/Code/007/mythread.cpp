#include "mythread.h"

MyThread::MyThread()
{

}


 void MyThread::run()
 {
     qDebug()<<QStringLiteral("线程开始！");

     /*
     for(int i=0;i<100;++i)
     {
         QThread::msleep(50);
         qDebug()<<i;
     }
     */

     int i=0;
     while(flag)
     {
         QThread::msleep(50);
         qDebug()<<++i;
     }

     qDebug()<<QStringLiteral("线程执行完毕！");
     qDebug()<<QStringLiteral("清理资源！");

 }
