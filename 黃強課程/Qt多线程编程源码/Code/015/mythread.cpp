#include "mythread.h"

//��ʾȫ�ֱ���ts������Դ�ļ��ж�����
extern QThreadStorage< QString > ts;

MyThread::MyThread()
{

}


void MyThread::run()
{
    //������ͼ��ȡmainwindow�����õ�"main"����
     QString str =ts.localData();

     qDebug()<<str<<QThread::currentThreadId();

     //�����߳������þֲ�����
     ts.setLocalData("child");

     //��ȡ�ֲ�����
      QString str2 =ts.localData();


     qDebug()<<str2<<QThread::currentThreadId();
}
