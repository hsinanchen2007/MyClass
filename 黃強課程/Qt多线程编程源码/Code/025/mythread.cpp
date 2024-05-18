#include "mythread.h"

//extern int N;

extern QAtomicInteger<  int  >  N;

MyThread::MyThread()
{

}

//方案1，可以使用QMutex保证互斥


 void MyThread::run()
 {
     for(int i=0;i<100000;++i)
     {
         ++N; //自增1
     }
 }
