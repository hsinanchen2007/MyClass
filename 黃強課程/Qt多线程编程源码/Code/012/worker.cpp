#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

//�ۺ�����Ϊ�̵߳�ִ�к��������źŴ���
 void Worker::Do()
 {
     qDebug()<<QStringLiteral("Do ����ִ����")<< QThread::currentThreadId();
 }

 //�ۺ�����Ϊ�̵߳�ִ�к��������źŴ���
  void Worker::DoOther()
  {
      qDebug()<<QStringLiteral("DoOther ����ִ����")<< QThread::currentThreadId();
  }
