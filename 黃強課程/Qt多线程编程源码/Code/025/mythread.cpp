#include "mythread.h"

//extern int N;

extern QAtomicInteger<  int  >  N;

MyThread::MyThread()
{

}

//����1������ʹ��QMutex��֤����


 void MyThread::run()
 {
     for(int i=0;i<100000;++i)
     {
         ++N; //����1
     }
 }
