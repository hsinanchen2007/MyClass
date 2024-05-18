#include "producerthread.h"

extern int  Space;
extern QMutex   mutex;
extern QWaitCondition  goConsumer;


ProducerThread::ProducerThread(QString name)
{
  this->name = name;
}



void ProducerThread::run( )
{

  while(true)
  {
      //�ȴ�һ�����ʱ��
         qsrand(time(NULL));
         int  time = 1+qrand() % 5;
        QThread::sleep(time);


         mutex.lock();//����

         if(Space <= 0)
         {
             qDebug()<<name<<QStringLiteral("�ֿ����ˣ�");

             goConsumer.wakeAll();//��Ʒ������3����֪ͨ����������������
         }
         else
         {
              qDebug()<<name<<QStringLiteral("������һ����Ʒ��");
              --Space;//����һ����Ʒ��ռ��һ��λ��
         }

         mutex.unlock();//����

  }

}
