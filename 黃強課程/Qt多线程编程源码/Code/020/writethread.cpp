#include "writethread.h"

//表示此变量在其它文件中定义，可以使用
extern  QReadWriteLock  rwLock;

WriteThread::WriteThread( QString name)
{
this->name= name;
}


void WriteThread::run()
{

    while(true)
    {
        //加上写的锁，不可以同时写,一个线程lockForWrite之后，unlock之前，
        //其它线程来lockForWrite就会阻塞
        rwLock.lockForWrite();


      qDebug()<<name<<QStringLiteral("开始写");

      //模拟耗费时间
      QThread::sleep(3);

      qDebug()<<name<<QStringLiteral("结束写");


      rwLock.unlock();

      QThread::usleep(1);


    }


}
