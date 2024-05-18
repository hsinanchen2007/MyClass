#include "mythread.h"


MyThread::MyThread()
{

}


 void MyThread::run()
 {
     //这里new 才算属于子线程的
       test = new Test();

     qDebug()<<QStringLiteral("子线程")<<QThread::currentThreadId();

     //开启时间循环
      exec();
 }
