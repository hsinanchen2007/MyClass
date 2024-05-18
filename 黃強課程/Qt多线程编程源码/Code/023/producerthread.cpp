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
         mutex.lock();//加锁

         if(Space <= 0)
         {
             qDebug()<<name<<QStringLiteral("仓库满了！");
             goProducer.wait(&mutex ); //让线程等待
         }
         else
         {
              qDebug()<<name<<QStringLiteral("生产了一个商品！");
              --Space;//放入一件商品，占用一个位置
         }

         mutex.unlock();//解锁

         QThread::msleep(500);//睡眠500ms
  }

}
