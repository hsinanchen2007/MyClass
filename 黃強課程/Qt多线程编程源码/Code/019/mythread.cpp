#include "mythread.h"


//���廥������������Դ����
//QMutex  mutex;

//�ݹ黥���������Զ�ε�lock����֤unlock������lock����һ�¾Ϳ�����
QRecursiveMutex  mutex;



MyThread::MyThread()
{

}

void  MyThread::run()
{
    qDebug()<<QStringLiteral("run()��ʼ ");
    fun2();
    qDebug()<<QStringLiteral("run()���� ");
}

void MyThread::fun1()
{
      mutex.lock();
      qDebug()<<"fun1() ";
      mutex.unlock();
}
void MyThread::fun2()
{
     mutex.lock();
     qDebug()<<"fun2() ";
     //��Ҫfun1�Ĺ���
     fun1();
     mutex.unlock();
}

