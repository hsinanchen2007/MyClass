#include "carthread.h"

CarThread::CarThread(   QString name)
{
   this->name =name;
}

//�����������ã���һ����Դ���л��Ᵽ��
//QMutex  mutex;


//�ź��������ã�����N���߳�ͬʱ������Դ
QSemaphore sem(3);//ģ��3����λ��ͬʱ����3���߳����ֱ�ռ��3����λ

//QMutex  �ȼ���  QSemaphore sem(1)

void CarThread::run()
{

    while(true)
    {

        sem.acquire();//�̼߳���һ����Դ��

       qDebug()<<name<<QStringLiteral("���복λ!");
       QThread::sleep(3);//ͣ��ʱ��
       qDebug()<<name<<QStringLiteral("�뿪��λ!");

       sem.release();//�ͷ�һ����λ
    }
}
