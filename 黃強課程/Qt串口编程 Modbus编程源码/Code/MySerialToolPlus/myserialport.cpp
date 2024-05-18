#include "myserialport.h"

MySerialPort::MySerialPort()
{
    connect(this, &QSerialPort::readyRead, [this]
    {

        //����߳�ID
        qDebug()<<"recv:   "<<QThread::currentThreadId();


        //�յ���������
        QByteArray arr=  readAll();
        emit sigReceived(arr);


      /*
       //��ʱ����
       int sum=0;
        for (int i=0;i<10000000;++i)
        {
            sum+=i;
        }
         qDebug()<<sum;
      */


    });
}


//����һ������
void  MySerialPort::Start(Settings sets)
{
    //���ô��ڲ���
  QSerialPort::setPortName(sets.name);
  QSerialPort::setParity(sets.parity);
  QSerialPort::setBaudRate(sets.baudRate);
  QSerialPort::setDataBits(sets.dataBits);
  QSerialPort::setStopBits(sets.stopBits);
  QSerialPort::setFlowControl(sets.flowControl);

  //����߳�ID
  qDebug()<<"start:   "<<QThread::currentThreadId();


  //�򿪴���
  if(QSerialPort::open(QIODevice::ReadWrite))
  {
        emit sigStarted();
  }
  else{
      //��ʧ���˹رմ�1
      emit sigStoped(1);
  }

}

//ֹͣһ������
void  MySerialPort::Stop()
{
    //�رմ���
    if(QSerialPort::isOpen())
    {
         QSerialPort::close();
    }

    //����߳�ID
    qDebug()<<"Stop:   "<<QThread::currentThreadId();


     //����ֹͣ��0
    emit sigStoped(0);


}


//�򴮿�д����
void MySerialPort::Send(QByteArray  data)
{

    //����߳�ID
    qDebug()<<"Send:   "<<QThread::currentThreadId();


    if(QSerialPort::isOpen())
    {    //д����
         QSerialPort::write(data);
    }
}
