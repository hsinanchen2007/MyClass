#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

//槽函数(主要观测它在哪个线程被调用)
 void  Test::MySlot()
{
       qDebug()<<QStringLiteral("槽函数被调用了，在线程")<<QThread::currentThreadId();
       QThread::sleep(5);
       qDebug()<<QStringLiteral("槽函数执行完毕，在线程")<<QThread::currentThreadId();
 }
