#include "mythread.h"
#include<QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
 {
    qDebug()<<QStringLiteral("���߳�ID ")<<QThread::currentThreadId();


     qDebug()<<QStringLiteral("�߳̿�ʼִ����!");

     for(int i=0;i<100;++i)
     {
         qDebug()<<i;
         //˯��10ms������ռ�ô���CPU
         QThread::msleep(10);
     }

      qDebug()<<QStringLiteral("�߳̽����ˣ�");
      qDebug()<<QStringLiteral("��һЩ��Դ��������");
 }
