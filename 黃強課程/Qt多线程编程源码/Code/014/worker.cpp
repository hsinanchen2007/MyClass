#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

//槽函数
 void  Worker::Do()
 {
     //循环100万次，然后每次都设置按钮的文本为当前次数
    for(int i=0;i<=1000000;++i)
    {
        emit mySig( QString::number(i) );
        //  防止子线程一直占用CPU，从而main线程 得不到执行
        QThread::usleep(1);
    }
 }
