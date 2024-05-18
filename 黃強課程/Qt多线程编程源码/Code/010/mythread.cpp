#include "mythread.h"
#include<QTimer>

MyThread::MyThread()
{

}

void MyThread::run()
{
  qDebug()<<QStringLiteral("线程开始了");


  //线程里面使用定时器
  QTimer *timer= new QTimer();
  connect(timer, &QTimer::timeout ,this ,&MyThread::timeSlot);
  timer->start(1000);//1秒触发一次信号

  //开启事件循环
   exec();

  qDebug()<<QStringLiteral("线程结束了");

}

void  MyThread::timeSlot()
{
     qDebug()<<QStringLiteral("定时器触发！");
}
