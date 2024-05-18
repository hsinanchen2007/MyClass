#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>

//方式一
//第一步，定义一个类，继承自QThread
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

    //第二步，将线程要执行的内容写到run方法
     virtual void run();
};

#endif // MYTHREAD_H
