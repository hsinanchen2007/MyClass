#include "mythread.h"


MyThread::MyThread()
{

}


 void MyThread::run()
 {
     //����new �����������̵߳�
       test = new Test();

     qDebug()<<QStringLiteral("���߳�")<<QThread::currentThreadId();

     //����ʱ��ѭ��
      exec();
 }
