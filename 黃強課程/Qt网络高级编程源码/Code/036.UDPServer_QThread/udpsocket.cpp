#include "udpsocket.h"

UdpSocket::UdpSocket()
{

}

void  UdpSocket::slotSend(QHostAddress addr,quint16 port, QByteArray arr  )
{
    qDebug()<<"send 线程"<<QThread::currentThread();

      writeDatagram(arr,  addr, port);
}
