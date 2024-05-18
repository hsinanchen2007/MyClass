#include "producerthread.h"

extern int  Space;
extern QMutex   mutex;
extern QWaitCondition  goProducer;


ProducerThread::ProducerThread(QString name)
{
  this->name = name;
}



void ProducerThread::run( )
{

  while(true)
  {
         mutex.lock();//����

         if(Space <= 0)
         {
             qDebug()<<name<<QStringLiteral("�ֿ����ˣ�");
             goProducer.wait(&mutex ); //���̵߳ȴ�
         }
         else
         {
              qDebug()<<name<<QStringLiteral("������һ����Ʒ��");
              --Space;//����һ����Ʒ��ռ��һ��λ��
         }

         mutex.unlock();//����

         QThread::msleep(500);//˯��500ms
  }

}
