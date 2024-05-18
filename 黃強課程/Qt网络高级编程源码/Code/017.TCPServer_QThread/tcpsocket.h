#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include<QThread>
#include<QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket();

 public slots:
    void slotSend(QByteArray  arr);
};

#endif // TCPSOCKET_H
