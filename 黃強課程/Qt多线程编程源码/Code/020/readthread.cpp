#include "readthread.h"

//表示此变量在其它文件中定义，可以使用
extern  QReadWriteLock  rwLock;


ReadThread::ReadThread( QString name)
{
this->name= name;
}


void ReadThread::run()
{

    while(true)
    {

     //加上读的锁，可以同时读的
      rwLock.lockForRead();


      qDebug()<<name<<QStringLiteral("开始读");

      //模拟耗费时间
      QThread::sleep(3);

      qDebug()<<name<<QStringLiteral("结束读");


      rwLock.unlock();
    }


}
