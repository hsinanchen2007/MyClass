#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ע��Settings���Ա���  �źŲ�����Ϊ����ʹ��
    qRegisterMetaType<MySerialPort::Settings>("MySerialPort::Settings");

    InitUI();

    InitCOM();
}


void MainWindow::InitUI()
{

    //�˿����ƣ�Ԥ��10������
    for(int i=1;i<=10;++i)
    {
        ui->portName->addItem(QString("COM%1").arg(i));
    }

    //������
    ui->baudRate->addItem("1200" , QSerialPort::Baud1200  );
    ui->baudRate->addItem("2400" , QSerialPort::Baud2400  );
    ui->baudRate->addItem("4800" , QSerialPort::Baud4800  );
    ui->baudRate->addItem("9600" , QSerialPort::Baud9600  );
    ui->baudRate->addItem("19200" , QSerialPort::Baud19200  );

    //����λ
    ui->dataBits->addItem("8",QSerialPort::Data8);
    ui->dataBits->addItem("7",QSerialPort::Data7);
    ui->dataBits->addItem("6",QSerialPort::Data6);
    ui->dataBits->addItem("5",QSerialPort::Data5);

    //��żУ��
    ui->parity->addItem("None" ,  QSerialPort::NoParity);
    ui->parity->addItem("Even" ,  QSerialPort::EvenParity);
    ui->parity->addItem("Odd" ,  QSerialPort::OddParity);

    //ֹͣλ
    ui->stopBits->addItem("1", QSerialPort::OneStop);
    ui->stopBits->addItem("1.5", QSerialPort::OneAndHalfStop);
    ui->stopBits->addItem("2", QSerialPort::TwoStop);

    //������
    ui->flowControl->addItem("None",QSerialPort::NoFlowControl);
    ui->flowControl->addItem("RTS/CTS",QSerialPort::HardwareControl);
    ui->flowControl->addItem("XON/XOFF",QSerialPort::SoftwareControl);

    //��ʱ����Ĭ��ʱ����
    ui->timelineEdit->setText("1000");

   //���Ӷ�ʱ�����ź����
    connect(&m_timer,&QTimer::timeout ,this ,&MainWindow::timeUp);
}
void   MainWindow::InitCOM()
{

    //������
    m_serial.moveToThread(&m_thread);
    m_thread.start();//�����߳�

    //������Ӧ���ź����,  �����������͵��ź�
    connect( this,  &MainWindow::sigStart, &m_serial, &MySerialPort::Start);
    connect( this,  &MainWindow::sigStop, &m_serial, &MySerialPort::Stop);
    connect( this,  &MainWindow::sigSend, &m_serial, &MySerialPort::Send);

    //���Ӵ��ڶ����һЩ֪ͨ�źţ����汻�����յ��ź�
    connect(&m_serial, &MySerialPort::sigStarted, this ,&MainWindow::started);
    connect(&m_serial, &MySerialPort::sigStoped, this ,&MainWindow::stoped);
    connect(&m_serial, &MySerialPort::sigReceived, this ,&MainWindow::recieved);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//�����ģ�ʹ���ź��������߳���MySerialPort�����һЩ�ۺ���
void MainWindow::on_openButton_clicked()
{
    QString text= ui->openButton->text();
    if(text ==  QStringLiteral("�򿪴���"))
    {
        MySerialPort::Settings  s;
        s.name= ui->portName->currentText();
        s.baudRate= (QSerialPort::BaudRate)ui->baudRate->currentData().toInt();
         s.dataBits = (QSerialPort::DataBits)  ui->dataBits->currentData().toInt();
         s.stopBits= (QSerialPort::StopBits)  ui->stopBits->currentData().toInt();
         s.parity= (QSerialPort::Parity)  ui->parity->currentData().toInt();
         s.flowControl = (QSerialPort::FlowControl)  ui->flowControl->currentData().toInt();


        //���ź����߳��д򿪴���
        emit sigStart(s);
    }
    else
    {
        //���ź����߳��йرմ���
        emit sigStop();
    }

}

void MainWindow::on_sendButton_clicked()
{
    QString strSend= ui->sendTextEdit->toPlainText();
    QByteArray arr= strSend.toUtf8();

    //���ź����߳���д��������
    emit sigSend(arr );
}

void  MainWindow::started()
{
    ui->openButton->setText(QStringLiteral("�رմ���"));
    ui->groupBox->setEnabled(false);

}

void  MainWindow::stoped(int status)
{
    ui->openButton->setText(QStringLiteral("�򿪴���"));
    ui->groupBox->setEnabled(true);
}


void  MainWindow::recieved(QByteArray arr)
{
   //�ֽ�����תΪ�ַ���
   QString  strText= QString (arr);

   //����ʱ��
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString  t  =current_date_time.toString("yyyy-MM-dd hh:mm:ss.zzz : ");

   //׷�ӵ�ĩβ
    ui->recvTextEdit->appendPlainText( t + strText + "\n" );
}



void MainWindow::closeEvent(QCloseEvent *event)
{
   //�رմ���
    emit sigStop();

    //�˳��̵߳���Ϣѭ��
    m_thread.quit();

    //�ȴ��߳̽���
    m_thread.wait();

}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1) //��ѡ��
    {
        m_timer.start( ui->timelineEdit->text().toUInt());
    }
    else
    {
        m_timer.stop();
    }
}


//��ʱ�������Ĳۺ���
 void MainWindow::timeUp()
 {
         //qDebug()<<"time up!";

     //��������
     on_sendButton_clicked();
 }

