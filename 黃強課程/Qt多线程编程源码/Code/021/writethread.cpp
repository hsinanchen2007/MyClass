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


        {
            //�������ʱ���Զ�����rwLock��lockForWrite
            QWriteLocker  lock(&rwLock);

            qDebug()<<name<<QStringLiteral("��ʼд");

           //ģ��ķ�ʱ��
           QThread::sleep(3);

           qDebug()<<name<<QStringLiteral("����д");

           }//lock��������������������ʱ�Զ�����rwLock��unLock


      QThread::usleep(1);


    }


}
