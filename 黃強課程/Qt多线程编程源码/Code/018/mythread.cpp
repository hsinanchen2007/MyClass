#include "mythread.h"
#include<QMutex>
#include<QMutexLocker>

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
        // QMutexLocker �����ʱ����Ҫ����һ��QMutex
        // ���ҹ����ʱ���Զ������Ǽ���������QMutex��lock
        //˵���ˣ���ֻ�Ǹ����ӣ������ɻ�Ļ���QMutex

        {
               QMutexLocker  m(&mutex);


                if(tickets>0)
                {
                    //������һ���߳�һֱռ��CPU
                    QThread::msleep(1);

                    qDebug()<<name <<QStringLiteral("������Ʊ")<<tickets;

                    //�߳̿������������CPUʱ��Ƭ����ʱ��ͣ

                    //����һ��Ʊ
                    -- tickets;
                }

                //QMutexLocker�������ٵ�ʱ���Զ�����QMutex��unlock

        }//����m��������������


    }

}
