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


        {
            //对象构造的时候自动调用rwLock的lockForWrite
            QWriteLocker  lock(&rwLock);

            qDebug()<<name<<QStringLiteral("开始写");

           //模拟耗费时间
           QThread::sleep(3);

           qDebug()<<name<<QStringLiteral("结束写");

           }//lock对象的作用域结束，销毁时自动调用rwLock的unLock


      QThread::usleep(1);


    }


}
