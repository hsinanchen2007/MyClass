#ifndef RECVTHREAD_H
#define RECVTHREAD_H
//头文件
#include<QTcpSocket>
#include<QThread>
#include<QDebug>
#include <QTcpSocket>
#include <QQueue>

//步骤一，新建一个类继承自QThread
class RecvThread : public QThread
{
    Q_OBJECT
public:
    RecvThread( );

    void  setParam(QString ip ,quint16 port );

     //步骤二，重写虚方法run
     virtual void run();


 signals:
      //这个信号，线程内发送，传递给外面的MainWindows 在界面上显示
      void  sigPrint(QString info,  bool conn =true);//与网络无关的信号


private:
    //定义一个QTcpSocket对象（在主线程中创建的）
    //在run方法使用这个对象，会提示一些问题
   //QTcpSocket  m_tcpClient;

    //最好是在线程run中创建QTcpSocket对象
    QTcpSocket  *m_tcpClient;


    QString ip;
    quint16 port;



 public:
    volatile  bool bRun;//是否继续运行

    //使用一个队列保存要发送的数据
    QQueue<QByteArray>  que;
};

#endif // RECVTHREAD_H
