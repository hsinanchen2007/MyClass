#include "mythread.h"

MyThread::MyThread(QString name,int time)
{
    this->name= name;
    this->time= time;
}


void MyThread::run( )
{
    qDebug()<<name<<QStringLiteral("��ʼִ���ˣ�");

    QThread::sleep(time);//ģ���߳�ִ�����ĵ�ʱ��

    qDebug()<<name<<QStringLiteral("�����ˣ�");
}
