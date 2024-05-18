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
         mutex.lock();//加锁

         if(Space == 3)
         {
             qDebug()<<name<<QStringLiteral("没有商品！");

             goConsumer.wait(&mutex);//阻塞等待有商品了再消费
         }
         else
         {
              qDebug()<<name<<QStringLiteral("消费一个商品！");
              ++Space;//取走一件商品，释放一个位置
         }

         mutex.unlock();//解锁


         QThread::msleep(500);//睡眠500ms

  }

}
