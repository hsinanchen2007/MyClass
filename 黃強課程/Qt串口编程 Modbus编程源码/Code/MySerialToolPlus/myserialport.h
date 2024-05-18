#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H
#include<QSerialPort>
#include<QDebug>
#include<QThread>

//�����Ķ������ŵ��߳���ȥ����
class MySerialPort : public QSerialPort
{
    Q_OBJECT
public:
    MySerialPort();

    //���ڲ����ṹ��
    struct Settings {
          QString name;//�˿�����COM1��COM2
           BaudRate baudRate;//������
           DataBits dataBits;//����λ
           Parity parity;//��żУ��
           StopBits stopBits;//ֹͣλ
           FlowControl flowControl;//������
      };

public slots://�����߳���ִ�е�����д�ɲۺ���

          //����һ������
         void  Start(Settings sets);
          //ֹͣһ������
         void  Stop();
          //�򴮿�д����
         void Send(QByteArray  data);

  signals://�����洫�ݵ�һЩ�ź�
         void  sigStarted();//���ڴ���
         void  sigStoped(int  status);//����ֹͣ��
         void  sigReceived(QByteArray  data);//�����յ�������
};

#endif // MYSERIALPORT_H
