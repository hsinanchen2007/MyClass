#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //注册Settings，以便在  信号槽中作为参数使用
    qRegisterMetaType<MySerialPort::Settings>("MySerialPort::Settings");

    InitUI();

    InitCOM();
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

   //连接定时器的信号与槽
    connect(&m_timer,&QTimer::timeout ,this ,&MainWindow::timeUp);
}
void   MainWindow::InitCOM()
{

    //步骤三
    m_serial.moveToThread(&m_thread);
    m_thread.start();//启动线程

    //连接响应的信号与槽,  界面主动发送的信号
    connect( this,  &MainWindow::sigStart, &m_serial, &MySerialPort::Start);
    connect( this,  &MainWindow::sigStop, &m_serial, &MySerialPort::Stop);
    connect( this,  &MainWindow::sigSend, &m_serial, &MySerialPort::Send);

    //连接串口对象的一些通知信号，界面被动接收的信号
    connect(&m_serial, &MySerialPort::sigStarted, this ,&MainWindow::started);
    connect(&m_serial, &MySerialPort::sigStoped, this ,&MainWindow::stoped);
    connect(&m_serial, &MySerialPort::sigReceived, this ,&MainWindow::recieved);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//步骤四，使用信号来触发线程中MySerialPort对象的一些槽函数
void MainWindow::on_openButton_clicked()
{
    QString text= ui->openButton->text();
    if(text ==  QStringLiteral("打开串口"))
    {
        MySerialPort::Settings  s;
        s.name= ui->portName->currentText();
        s.baudRate= (QSerialPort::BaudRate)ui->baudRate->currentData().toInt();
         s.dataBits = (QSerialPort::DataBits)  ui->dataBits->currentData().toInt();
         s.stopBits= (QSerialPort::StopBits)  ui->stopBits->currentData().toInt();
         s.parity= (QSerialPort::Parity)  ui->parity->currentData().toInt();
         s.flowControl = (QSerialPort::FlowControl)  ui->flowControl->currentData().toInt();


        //发信号在线程中打开串口
        emit sigStart(s);
    }
    else
    {
        //发信号在线程中关闭串口
        emit sigStop();
    }

}

void MainWindow::on_sendButton_clicked()
{
    QString strSend= ui->sendTextEdit->toPlainText();
    QByteArray arr= strSend.toUtf8();

    //发信号在线程中写串口数据
    emit sigSend(arr );
}

void  MainWindow::started()
{
    ui->openButton->setText(QStringLiteral("关闭串口"));
    ui->groupBox->setEnabled(false);

}

void  MainWindow::stoped(int status)
{
    ui->openButton->setText(QStringLiteral("打开串口"));
    ui->groupBox->setEnabled(true);
}


void  MainWindow::recieved(QByteArray arr)
{
   //字节数组转为字符串
   QString  strText= QString (arr);

   //加上时间
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString  t  =current_date_time.toString("yyyy-MM-dd hh:mm:ss.zzz : ");

   //追加到末尾
    ui->recvTextEdit->appendPlainText( t + strText + "\n" );
}



void MainWindow::closeEvent(QCloseEvent *event)
{
   //关闭串口
    emit sigStop();

    //退出线程的消息循环
    m_thread.quit();

    //等待线程结束
    m_thread.wait();

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

