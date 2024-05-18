#include "mythread.h"

//表示全局变量ts在其他源文件中定义了
extern QThreadStorage< QString > ts;

MyThread::MyThread()
{

}


void MyThread::run()
{
    //这里企图读取mainwindow中设置的"main"数据
     QString str =ts.localData();

     qDebug()<<str<<QThread::currentThreadId();

     //在子线程中设置局部数据
     ts.setLocalData("child");

     //读取局部数据
      QString str2 =ts.localData();


     qDebug()<<str2<<QThread::currentThreadId();
}
