#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

//槽函数作为线程的执行函数，由信号触发
 void Worker::Do()
 {
     qDebug()<<QStringLiteral("Do 函数执行了")<< QThread::currentThreadId();
 }

 //槽函数作为线程的执行函数，由信号触发
  void Worker::DoOther()
  {
      qDebug()<<QStringLiteral("DoOther 函数执行了")<< QThread::currentThreadId();
  }
