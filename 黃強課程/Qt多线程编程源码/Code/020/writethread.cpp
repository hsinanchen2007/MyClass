#include "writethread.h"

//��ʾ�˱����������ļ��ж��壬����ʹ��
extern  QReadWriteLock  rwLock;

WriteThread::WriteThread( QString name)
{
this->name= name;
}


void WriteThread::run()
{

    while(true)
    {
        //����д������������ͬʱд,һ���߳�lockForWrite֮��unlock֮ǰ��
        //�����߳���lockForWrite�ͻ�����
        rwLock.lockForWrite();


      qDebug()<<name<<QStringLiteral("��ʼд");

      //ģ��ķ�ʱ��
      QThread::sleep(3);

      qDebug()<<name<<QStringLiteral("����д");


      rwLock.unlock();

      QThread::usleep(1);


    }


}
