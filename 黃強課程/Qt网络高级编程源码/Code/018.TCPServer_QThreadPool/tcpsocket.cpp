#include "tcpsocket.h"

TcpSocket::TcpSocket()
{

}


void TcpSocket::slotSend(QByteArray  arr)
{
      qDebug()<<"send 数据 "<<QThread::currentThread();

       write( arr );
}
