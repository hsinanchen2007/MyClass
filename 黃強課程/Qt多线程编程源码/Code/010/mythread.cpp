#include "mythread.h"
#include<QTimer>

MyThread::MyThread()
{

}

void MyThread::run()
{
  qDebug()<<QStringLiteral("�߳̿�ʼ��");


  //�߳�����ʹ�ö�ʱ��
  QTimer *timer= new QTimer();
  connect(timer, &QTimer::timeout ,this ,&MyThread::timeSlot);
  timer->start(1000);//1�봥��һ���ź�

  //�����¼�ѭ��
   exec();

  qDebug()<<QStringLiteral("�߳̽�����");

}

void  MyThread::timeSlot()
{
     qDebug()<<QStringLiteral("��ʱ��������");
}
