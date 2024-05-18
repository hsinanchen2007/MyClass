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
      //等待一个随机时间
         qsrand(time(NULL));
         int  time = 1+qrand() % 5;
        QThread::sleep(time);


         mutex.lock();//加锁

         if(Space <= 0)
         {
             qDebug()<<name<<QStringLiteral("仓库满了！");

             goConsumer.wakeAll();//商品生产了3个，通知所有消费者来消费
         }
         else
         {
              qDebug()<<name<<QStringLiteral("生产了一个商品！");
              --Space;//放入一件商品，占用一个位置
         }

         mutex.unlock();//解锁

  }

}
