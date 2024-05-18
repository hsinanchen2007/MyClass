#include "mythread.h"
#include<QMutex>

//������100��Ʊ��Դ
int tickets= 100;

//����QMutex����֤һ��ֻ��һ���̷߳��ʸô���
QMutex  mutex;


MyThread::MyThread(QString name)
{
   this->name = name;
}


void MyThread::run()
{
    while(tickets>0)
    {
        //������A�̼߳��������B�̵߳���lock�������ͻ�����
        //����A�߳�unlock������ B�̲߳Ż�ֹͣ����
        mutex.lock();

        if(tickets>0)
        {
            //������һ���߳�һֱռ��CPU
            QThread::msleep(1);

            qDebug()<<name <<QStringLiteral("������Ʊ")<<tickets;

            //�߳̿������������CPUʱ��Ƭ����ʱ��ͣ

            //����һ��Ʊ
            -- tickets;
        }

        //����
        mutex.unlock();

    }

}
