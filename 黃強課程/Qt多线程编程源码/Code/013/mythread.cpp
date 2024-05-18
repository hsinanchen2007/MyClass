#include "mythread.h"

MyThread::MyThread()
{

}


 void MyThread::run()
 {
     //循环100万次，然后每次都设置按钮的文本为当前次数
    for(int i=0;i<=1000000;++i)
    {
        //通过信号槽来改变UI的显示
        emit  mySig(QString::number(i));
        //防止CPU一直执行子线程，从而导致main线程无法执行
        QThread::usleep(1);
    }
  }
