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

          //构造lock对象的时候，自动调用rwLock的 lockFroRead
          {
              QReadLocker lock(&rwLock);

              qDebug()<<name<<QStringLiteral("开始读");

                //模拟耗费时间
                QThread::sleep(3);

                qDebug()<<name<<QStringLiteral("结束读");

           } //在这里lock对象作用域结束，对象析构的时候自动调用unLock


    }


}
