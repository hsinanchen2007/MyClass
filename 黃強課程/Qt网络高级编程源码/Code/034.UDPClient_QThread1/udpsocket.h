#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include<QUdpSocket>
#include<QThread>

class UdpSocket : public QUdpSocket
{
    Q_OBJECT
public:
    UdpSocket();

public slots:
    void  slotSend(QHostAddress addr,quint16 port, QByteArray arr  );

};

#endif // UDPSOCKET_H
