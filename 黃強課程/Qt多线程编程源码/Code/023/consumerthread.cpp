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
      //等待一个随机时间
         qsrand(time(NULL));
         int  time = 1+qrand() % 5;
        QThread::sleep(time);

         mutex.lock();//加锁

         if(Space == 3)
         {
             qDebug()<<name<<QStringLiteral("没有商品！");

           // goProducer.wakeAll();//唤醒所有的生产者去生产，取消他们的阻塞

             goProducer.wakeOne(); //从阻塞的线程中随意唤醒一个


         }
         else
         {
              qDebug()<<name<<QStringLiteral("消费一个商品！");
              ++Space;//取走一件商品，释放一个位置
         }

         mutex.unlock();//解锁

  }

}
