#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUI();
}

void MainWindow::InitUI()
{

    //端口名称，预置10个串口
    for(int i=1;i<=10;++i)
    {
        ui->portName->addItem(QString("COM%1").arg(i));
    }

    //波特率
    ui->baudRate->addItem("1200" , QSerialPort::Baud1200  );
    ui->baudRate->addItem("2400" , QSerialPort::Baud2400  );
    ui->baudRate->addItem("4800" , QSerialPort::Baud4800  );
    ui->baudRate->addItem("9600" , QSerialPort::Baud9600  );
    ui->baudRate->addItem("19200" , QSerialPort::Baud19200  );

    //数据位
    ui->dataBits->addItem("8",QSerialPort::Data8);
    ui->dataBits->addItem("7",QSerialPort::Data7);
    ui->dataBits->addItem("6",QSerialPort::Data6);
    ui->dataBits->addItem("5",QSerialPort::Data5);

    //奇偶校验
    ui->parity->addItem("None" ,  QSerialPort::NoParity);
    ui->parity->addItem("Even" ,  QSerialPort::EvenParity);
    ui->parity->addItem("Odd" ,  QSerialPort::OddParity);

    //停止位
    ui->stopBits->addItem("1", QSerialPort::OneStop);
    ui->stopBits->addItem("1.5", QSerialPort::OneAndHalfStop);
    ui->stopBits->addItem("2", QSerialPort::TwoStop);

    //流控制
    ui->flowControl->addItem("None",QSerialPort::NoFlowControl);
    ui->flowControl->addItem("RTS/CTS",QSerialPort::HardwareControl);
    ui->flowControl->addItem("XON/XOFF",QSerialPort::SoftwareControl);

    //定时器的默认时间间隔
    ui->timelineEdit->setText("1000");

    //连接有数据到来的信号与槽
    connect(&m_serial , &QSerialPort::readyRead , this ,  &MainWindow::serialReadData);

    //连接数据发送后的信号槽
    connect(&m_serial, &QSerialPort::bytesWritten ,this , &MainWindow::bytesWriteData);

   //连接定时器的信号与槽
    connect(&m_timer,&QTimer::timeout ,this ,&MainWindow::timeUp);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    QString text= ui->openButton->text();
    if(text ==  QStringLiteral("打开串口"))
    {
        //设置串口的各种参数
        m_serial.setPortName( ui->portName->currentText() );
        m_serial.setBaudRate( ui->baudRate->currentData().toInt());
        m_serial.setParity((QSerialPort::Parity) ui->parity->currentData().toInt());
        m_serial.setDataBits((QSerialPort::DataBits) ui->dataBits->currentData().toInt());
        m_serial.setStopBits((QSerialPort::StopBits) ui->stopBits->currentData().toInt());
        m_serial.setFlowControl((QSerialPort::FlowControl) ui->flowControl->currentData().toInt());

        //打开串口
        bool ret= m_serial.open(QIODevice::ReadWrite);
        if(ret )
        {
            //打开后禁止更改参数
            ui->groupBox->setEnabled(false);

            //切换按钮文本
            ui->openButton->setText(QStringLiteral("关闭串口"));
        }
        else
        { //打开失败,状态栏显示错误信息5 s
            ui->statusbar->showMessage( m_serial.errorString() +QString::number( m_serial.error()) ,5000);
        }

    }
    else
    {

        //关闭串口
         m_serial.close();

         //启用更改参数
         ui->groupBox->setEnabled(true);

         //切换按钮文本
         ui->openButton->setText(QStringLiteral("打开串口"));

    }
}

void MainWindow::bytesWriteData(qint64 bytes)
{
    ui->statusbar->showMessage( QStringLiteral("发送了%1字节！").arg(bytes),5000);
}

 void MainWindow::serialReadData()
 {
        //读取串口的数据
       QByteArray  arr=  m_serial.readAll();

       //字节数组转为字符串
       QString  strText= QString (arr);

       //加上时间
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString  t  =current_date_time.toString("yyyy-MM-dd hh:mm:ss.zzz : ");

       //追加到末尾
        ui->recvTextEdit->appendPlainText( t + strText + "\n" );


        //输出线程ID
        qDebug()<<QThread::currentThreadId();

 /*
       //耗时工作
       int sum=0;
        for (int i=0;i<10000000;++i)
        {
            sum+=i;
        }
         qDebug()<<sum;
*/


 }

void MainWindow::on_sendButton_clicked()
{
      QString strSend= ui->sendTextEdit->toPlainText();
      QByteArray arr= strSend.toUtf8();
      //发送数据
      m_serial.write(arr);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1) //勾选了
    {
        m_timer.start( ui->timelineEdit->text().toUInt());
    }
    else
    {
        m_timer.stop();
    }
}

//定时器触发的槽函数
 void MainWindow::timeUp()
 {
         //qDebug()<<"time up!";

     //发送数据
     on_sendButton_clicked();
 }
