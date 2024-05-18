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

    //���������ݵ������ź����
    connect(&m_serial , &QSerialPort::readyRead , this ,  &MainWindow::serialReadData);

    //�������ݷ��ͺ���źŲ�
    connect(&m_serial, &QSerialPort::bytesWritten ,this , &MainWindow::bytesWriteData);

   //���Ӷ�ʱ�����ź����
    connect(&m_timer,&QTimer::timeout ,this ,&MainWindow::timeUp);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    QString text= ui->openButton->text();
    if(text ==  QStringLiteral("�򿪴���"))
    {
        //���ô��ڵĸ��ֲ���
        m_serial.setPortName( ui->portName->currentText() );
        m_serial.setBaudRate( ui->baudRate->currentData().toInt());
        m_serial.setParity((QSerialPort::Parity) ui->parity->currentData().toInt());
        m_serial.setDataBits((QSerialPort::DataBits) ui->dataBits->currentData().toInt());
        m_serial.setStopBits((QSerialPort::StopBits) ui->stopBits->currentData().toInt());
        m_serial.setFlowControl((QSerialPort::FlowControl) ui->flowControl->currentData().toInt());

        //�򿪴���
        bool ret= m_serial.open(QIODevice::ReadWrite);
        if(ret )
        {
            //�򿪺��ֹ���Ĳ���
            ui->groupBox->setEnabled(false);

            //�л���ť�ı�
            ui->openButton->setText(QStringLiteral("�رմ���"));
        }
        else
        { //��ʧ��,״̬����ʾ������Ϣ5 s
            ui->statusbar->showMessage( m_serial.errorString() +QString::number( m_serial.error()) ,5000);
        }

    }
    else
    {

        //�رմ���
         m_serial.close();

         //���ø��Ĳ���
         ui->groupBox->setEnabled(true);

         //�л���ť�ı�
         ui->openButton->setText(QStringLiteral("�򿪴���"));

    }
}

void MainWindow::bytesWriteData(qint64 bytes)
{
    ui->statusbar->showMessage( QStringLiteral("������%1�ֽڣ�").arg(bytes),5000);
}

 void MainWindow::serialReadData()
 {
        //��ȡ���ڵ�����
       QByteArray  arr=  m_serial.readAll();

       //�ֽ�����תΪ�ַ���
       QString  strText= QString (arr);

       //����ʱ��
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString  t  =current_date_time.toString("yyyy-MM-dd hh:mm:ss.zzz : ");

       //׷�ӵ�ĩβ
        ui->recvTextEdit->appendPlainText( t + strText + "\n" );


        //����߳�ID
        qDebug()<<QThread::currentThreadId();

 /*
       //��ʱ����
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
      //��������
      m_serial.write(arr);
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
