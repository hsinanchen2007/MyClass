#include "readthread.h"

//��ʾ�˱����������ļ��ж��壬����ʹ��
extern  QReadWriteLock  rwLock;


ReadThread::ReadThread( QString name)
{
this->name= name;
}


void ReadThread::run()
{

    while(true)
    {

     //���϶�����������ͬʱ����
      rwLock.lockForRead();


      qDebug()<<name<<QStringLiteral("��ʼ��");

      //ģ��ķ�ʱ��
      QThread::sleep(3);

      qDebug()<<name<<QStringLiteral("������");


      rwLock.unlock();
    }


}
