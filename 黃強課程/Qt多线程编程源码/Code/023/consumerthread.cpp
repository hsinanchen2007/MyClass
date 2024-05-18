#include "consumerthread.h"


extern int  Space;
extern QMutex   mutex;
extern QWaitCondition  goProducer;

ConsumerThread::ConsumerThread(QString name)
{
  this->name = name;
}


void ConsumerThread::run( )
{

  while(true)
  {
      //�ȴ�һ�����ʱ��
         qsrand(time(NULL));
         int  time = 1+qrand() % 5;
        QThread::sleep(time);

         mutex.lock();//����

         if(Space == 3)
         {
             qDebug()<<name<<QStringLiteral("û����Ʒ��");

           // goProducer.wakeAll();//�������е�������ȥ������ȡ�����ǵ�����

             goProducer.wakeOne(); //���������߳������⻽��һ��


         }
         else
         {
              qDebug()<<name<<QStringLiteral("����һ����Ʒ��");
              ++Space;//ȡ��һ����Ʒ���ͷ�һ��λ��
         }

         mutex.unlock();//����

  }

}
