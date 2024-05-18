#include "consumerthread.h"


extern int  Space;
extern QMutex   mutex;
extern QWaitCondition  goConsumer;

ConsumerThread::ConsumerThread(QString name)
{
  this->name = name;
}


void ConsumerThread::run( )
{

  while(true)
  {
         mutex.lock();//����

         if(Space == 3)
         {
             qDebug()<<name<<QStringLiteral("û����Ʒ��");

             goConsumer.wait(&mutex);//�����ȴ�����Ʒ��������
         }
         else
         {
              qDebug()<<name<<QStringLiteral("����һ����Ʒ��");
              ++Space;//ȡ��һ����Ʒ���ͷ�һ��λ��
         }

         mutex.unlock();//����


         QThread::msleep(500);//˯��500ms

  }

}
