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

          //����lock�����ʱ���Զ�����rwLock�� lockFroRead
          {
              QReadLocker lock(&rwLock);

              qDebug()<<name<<QStringLiteral("��ʼ��");

                //ģ��ķ�ʱ��
                QThread::sleep(3);

                qDebug()<<name<<QStringLiteral("������");

           } //������lock�������������������������ʱ���Զ�����unLock


    }


}
