#include "mythread.h"

MyThread::MyThread()
{

}


 void MyThread::run()
 {
     qDebug()<<QStringLiteral("�߳̿�ʼ��");

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

     qDebug()<<QStringLiteral("�߳�ִ����ϣ�");
     qDebug()<<QStringLiteral("������Դ��");

 }
