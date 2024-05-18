#include "myserialport.h"

MySerialPort::MySerialPort()
{
    connect(this, &QSerialPort::readyRead, [this]
    {

        //输出线程ID
        qDebug()<<"recv:   "<<QThread::currentThreadId();


        //收到串口数据
        QByteArray arr=  readAll();
        emit sigReceived(arr);


      /*
       //耗时工作
       int sum=0;
        for (int i=0;i<10000000;++i)
        {
            sum+=i;
        }
         qDebug()<<sum;
      */


    });
}


//开启一个串口
void  MySerialPort::Start(Settings sets)
{
    //设置串口参数
  QSerialPort::setPortName(sets.name);
  QSerialPort::setParity(sets.parity);
  QSerialPort::setBaudRate(sets.baudRate);
  QSerialPort::setDataBits(sets.dataBits);
  QSerialPort::setStopBits(sets.stopBits);
  QSerialPort::setFlowControl(sets.flowControl);

  //输出线程ID
  qDebug()<<"start:   "<<QThread::currentThreadId();


  //打开串口
  if(QSerialPort::open(QIODevice::ReadWrite))
  {
        emit sigStarted();
  }
  else{
      //打开失败了关闭传1
      emit sigStoped(1);
  }

}

//停止一个串口
void  MySerialPort::Stop()
{
    //关闭串口
    if(QSerialPort::isOpen())
    {
         QSerialPort::close();
    }

    //输出线程ID
    qDebug()<<"Stop:   "<<QThread::currentThreadId();


     //正常停止传0
    emit sigStoped(0);


}


//向串口写数据
void MySerialPort::Send(QByteArray  data)
{

    //输出线程ID
    qDebug()<<"Send:   "<<QThread::currentThreadId();


    if(QSerialPort::isOpen())
    {    //写数据
         QSerialPort::write(data);
    }
}
