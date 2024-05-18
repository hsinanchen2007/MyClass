#include "tcpserver.h"
#include"mainwindow.h"

//静态变量初始化
QList<RecvThread *> TcpServer::clients;

TcpServer::TcpServer()
{

}


void TcpServer::incomingConnection(qintptr handle)
{
    qDebug()<<"当有客户端连接时被调用"<<handle;

    //为每个客户端来开辟一个线程，类似于传统C++ socket 多线程网络编程
    RecvThread *thread = new RecvThread(handle);

   //连接线程对象的信号槽
    connect( thread, &RecvThread::sigPrint , (MainWindow*) parent(),   &MainWindow::slotPrint);

    //线程run执行结束之后，自动销毁线程对象
    connect(thread, &QThread::finished , thread,   &QThread::deleteLater);

    //加入到客户端列表中去
    clients.push_back(thread);

    //启动线程
    thread->start();

}


  void TcpServer::send(QByteArray arr)
  {
      //分别调用每个线程的发送
      foreach(RecvThread *t  , clients)
      {
          t->send(arr);
      }
  }


  void TcpServer::close( )
  {
      //调用父类的close
      QTcpServer::close();

      //分别调用每个线程对象的close
      foreach(RecvThread *t  , clients)
      {
          t->close();
      }

      //清空客户端列表
      clients.clear();
  }
