#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitMasterUI();
    InitSlaveUI();

}


//��ʼ����վ��UI
void MainWindow::InitMasterUI()
{
    //�������Ϊ10�У�2��
    ui->tableMaster->setRowCount(10);
    ui->tableMaster->setColumnCount(2);

    QStringList hStrs;
    hStrs<<"Alisa"<<"00000";
    ui->tableMaster->setHorizontalHeaderLabels(hStrs);

    QStringList vStrs;
    vStrs<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    ui->tableMaster->setVerticalHeaderLabels(vStrs);

    //��ʼ��ÿ�����Ԫ�������
    for (int i=0;i<10;++i)
    {
        ui->tableMaster->setItem(i,0 ,new QTableWidgetItem(""));
        ui->tableMaster->setItem(i,1 ,new QTableWidgetItem(""));
    }

    //ͨѶ��ʽ������
    ui->mType->addItem("SerialPort");
    ui->mType->addItem("TCP");

    //���ô�վĬ�ϵ�ַ
    ui->mAddr->setText("1");


}

//��ʼ����վ��UI
void MainWindow::InitSlaveUI()
{
    //�������Ϊ10�У�2��
    ui->tableSlave->setRowCount(10);
    ui->tableSlave->setColumnCount(2);

    QStringList hStrs;
    hStrs<<"Alisa"<<"00000";
    ui->tableSlave->setHorizontalHeaderLabels(hStrs);

    QStringList vStrs;
    vStrs<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    ui->tableSlave->setVerticalHeaderLabels(vStrs);

    //��ʼ��ÿ�����Ԫ�������
    for (int i=0;i<10;++i)
    {
        ui->tableSlave->setItem(i,0 ,new QTableWidgetItem(""));
        ui->tableSlave->setItem(i,1 ,new QTableWidgetItem(""));
    }

    //ͨѶ��ʽ������
    ui->sType->addItem("SerialPort");
    ui->sType->addItem("TCP");

    //���ô�վĬ�ϵ�ַ
    ui->sAddr->setText("1");


    //��վ������������ѡ��
     ui->sTable->addItem( "Coils" ,QModbusDataUnit::Coils );
     ui->sTable->addItem( "InputRegisters" ,QModbusDataUnit::InputRegisters );
     ui->sTable->addItem( "DiscreteInputs" ,QModbusDataUnit::DiscreteInputs );
     ui->sTable->addItem( "HoldingRegisters" ,QModbusDataUnit::HoldingRegisters );


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mType_currentIndexChanged(const QString &arg1)
{
    if(ui->mType->currentText() == "TCP")
    {
        ui->mIP_COM->setText("127.0.0.1");
        ui->m_Port->setText("4000");
    }
    else
    {
        ui->mIP_COM->setText("COM1");
        ui->m_Port->setText("");
    }
}

void MainWindow::on_sType_currentTextChanged(const QString &arg1)
{
    if(ui->sType->currentText() == "TCP")
    {
        ui->sIP_COM->setText("127.0.0.1");
        ui->s_Port->setText("4000");
    }
    else
    {
        ui->sIP_COM->setText("COM2");
        ui->s_Port->setText("");
    }
}

void MainWindow::on_mConBtn_clicked()
{
    QString strText= ui->mConBtn->text();

    if(strText == QStringLiteral("����"))
    {
        //Modbus RTU
        if(ui->mType->currentText() == "SerialPort")
        {
            //new ��վ����
             master = new QModbusRtuSerialMaster();

             //���ô��ڲ���
             master->setConnectionParameter (
              QModbusDevice::SerialPortNameParameter , ui->mIP_COM->text());
            master->setConnectionParameter(
                        QModbusDevice::SerialParityParameter , QSerialPort::EvenParity);
            master->setConnectionParameter(
                        QModbusDevice::SerialBaudRateParameter , QSerialPort::Baud9600);
            master->setConnectionParameter(
                        QModbusDevice::SerialDataBitsParameter , QSerialPort::Data8);
            master->setConnectionParameter(
                        QModbusDevice::SerialStopBitsParameter , QSerialPort::OneStop);



        }
        else  //Modbus TCP
        {
            //new ��վ����
             master = new QModbusTcpClient();

             //�ߵ�����,����IP��˿�
             master->setConnectionParameter(
                         QModbusDevice::NetworkAddressParameter, ui->mIP_COM->text() );
             master->setConnectionParameter(
                         QModbusDevice::NetworkPortParameter, ui->m_Port->text().toUInt() );
        }


        //�������ӳ�ʱʱ��1s
        master->setTimeout(1000);
        //ʧ�ܺ����ԵĴ���
        master->setNumberOfRetries(3);

      //�����źŲ�
        connect(master, &QModbusDevice::stateChanged ,this ,[this]()
        {
            //������״̬��
            if(master->state() == QModbusDevice::ConnectedState)
            {
                 ui->mConBtn->setText(QStringLiteral("�Ͽ�"));
                 ui->statusbar->showMessage("Connect Success!",3000);
            }
            else
            {
                ui->mConBtn->setText(QStringLiteral("����"));
            }
        });


        // �豸��������ʱ�źš���
       connect(master, &QModbusClient::errorOccurred, [this](QModbusDevice::Error)
       {
            statusBar()->showMessage(master->errorString(), 3000);
            ui->mConBtn->setText(QStringLiteral("����"));
        });

       //�����豸
       master->connectDevice();

    }
    else
    {
        if(master)
        {
           //�Ͽ�����
            master->disconnectDevice();
            delete master;
            master = nullptr;

        }
    }

}

/*

 //ʹ��sendRawRequest���� QModbusRequest�������վ��
 //�յ���վ�Ļظ�ΪQModbusReply�� QModbusResponse��


void MainWindow::on_m03Btn_clicked()
{
    if(master==nullptr) return;

    //���վ����QModbusRequest����
    //03������+2�ֽڵ���ʼλ�� 0000+2�ֽڵĶ�ȡ���� 000A
    QModbusRequest mr(QModbusPdu::ReadHoldingRegisters );
    mr.setData(QByteArray::fromHex("0000000A"));

    //���վ����rawԭʼ����
   if( QModbusReply *reply= master->sendRawRequest(mr, ui->mAddr->text().toUInt()))
   {
       //�����û��ɻظ�
       if(!reply->isFinished())
       {
            //�󶨻ظ���ɵ��ź�
             connect( reply, &QModbusReply::finished , this ,[this,reply]
             {
                 //���û�д���
                 if(reply->error() == QModbusDevice::NoError)
                 {
                     //�õ�ԭʼ�ظ�
                     QModbusResponse  response= reply->rawResult();
                     //�õ�������
                     QModbusPdu::FunctionCode  code = response.functionCode();
                     //Ȼ��õ����ݲ���
                     QByteArray arr= response.data();

                     //��һ���ֽڱ�ʾ��������ݳ���
                     int len = arr[0];

                     //ÿ������ռ�����ֽ�
                     for(int i=0;i< len/2;++i)
                     {
                         unsigned char  high = arr[2*i+1];
                         unsigned char  low = arr[2*i+2];
                         //�õ��Ĵ�����ֵ
                         quint16  v = (high<<8 )| low;
                         //���õ����
                         ui->tableMaster->item(i , 1)->setText( QString::number(v));
                     }

                     ui->statusbar->showMessage("ReadHoldingRegisters Success!",5000);

                 }
                 else
                 {
                      ui->statusbar->showMessage(reply->errorString(),5000);
                 }

                 //ͨ���¼�ѭ��ȥ�ӳ�ɾ��
                 reply->deleteLater();
             });
       }
   }
   else
   {   //reply��NULL
        ui->statusbar->showMessage(master->errorString(),5000);
   }

}
*/


//ʹ��  sendReadRequest  ���� QModbusDataUnit  �������վ����
//�յ���վ�Ļظ�ΪQModbusReply��  QModbusDataUnit ��
void MainWindow::on_m03Btn_clicked()
{
    if(master==nullptr) return;

    //���ּĴ���+ ��ʼλ��+��ȡ����
    QModbusDataUnit mdu(QModbusDataUnit::HoldingRegisters , 0 ,10);

    //������
    if( QModbusReply *reply=master->sendReadRequest(mdu,ui->mAddr->text().toUInt() ))
    {
        //����δ���
        if(!reply->isFinished())
        {
            //�󶨻ظ���ɵ��ź�
             connect( reply, &QModbusReply::finished , this ,[this,reply]
             {
                 //���û�д���
                 if(reply->error() == QModbusDevice::NoError)
                 {
                     //�õ���ͨ�ظ�
                     QModbusDataUnit  unit = reply->result();

                     for(int i=0;i<unit.valueCount();++i)
                     {
                        //�õ���λ�õ�ֵ
                        quint16 v=  unit.value(i);

                        //���õ����
                        ui->tableMaster->item(unit.startAddress()+i , 1)->setText( QString::number(v));

                     }
                     ui->statusbar->showMessage("ReadHoldingRegisters Success!",5000);

                 }
                 else
                 {
                      ui->statusbar->showMessage(reply->errorString(),5000);
                 }

                 //ͨ���¼�ѭ��ȥ�ӳ�ɾ��
                 reply->deleteLater();
             });
        }
    }
    else
    {
        //reply��NULL
        ui->statusbar->showMessage(master->errorString(),5000);
    }

}

/*
//ʹ��sendRawRequest���� QModbusRequest�������վ��
//�յ���վ�Ļظ�ΪQModbusReply�� QModbusResponse��
void MainWindow::on_m06Btn_clicked()
{
    if(master==nullptr) return;

    //���վ����QModbusRequest����
    //06������+2�ֽڵ�д��λ�� 0003 + д���2�ֽڵ�ֵ 666��0x029A��
    QModbusRequest mr(QModbusPdu::WriteSingleRegister );
    mr.setData(QByteArray::fromHex("0003029A"));

    //���վ����rawԭʼ����
   if( QModbusReply *reply= master->sendRawRequest(mr, ui->mAddr->text().toUInt()))
   {
       //�����û��ɻظ�
       if(!reply->isFinished())
       {
            //�󶨻ظ���ɵ��ź�
             connect( reply, &QModbusReply::finished , this ,[this,reply]
             {
                 //���û�д���
                 if(reply->error() == QModbusDevice::NoError)
                 {
                     //�õ�ԭʼ�ظ�
                     QModbusResponse  response= reply->rawResult();
                     //�õ�������
                     QModbusPdu::FunctionCode  code = response.functionCode();
                     //Ȼ��õ����ݲ���
                     QByteArray arr= response.data();

                     //06�����룬������Ӧ�Ա���һ����
                     unsigned char  high1 = arr[0];
                     unsigned char  low1 = arr[1];

                     unsigned char  high2= arr[2];
                     unsigned char  low2= arr[3];


                       quint16  pos =  (high1<<8 )| low1;
                       quint16  v =  (high2<<8 )| low2;

                      //���õ����
                      ui->tableMaster->item(pos , 1)->setText( QString::number(v));

                       ui->statusbar->showMessage("WriteSingleRegister Success!",5000);

                 }
                 else
                 {
                      ui->statusbar->showMessage(reply->errorString(),5000);
                 }

                 //ͨ���¼�ѭ��ȥ�ӳ�ɾ��
                 reply->deleteLater();
             });
       }
   }
   else
   {   //reply��NULL
        ui->statusbar->showMessage(master->errorString(),5000);
   }
}
*/



//ʹ��  sendWriteRequest  ���� QModbusDataUnit  �������վ����
//�յ���վ�Ļظ�ΪQModbusReply��  QModbusDataUnit ��
void MainWindow::on_m06Btn_clicked()
{
    if(master==nullptr) return;

    //���뵥��ֵ
    QVector<quint16> vec;
    vec.push_back(666);

    //���ּĴ���+ ��ʼλ��+����ֵ
    QModbusDataUnit mdu(QModbusDataUnit::HoldingRegisters , 3 ,vec);

    //д����
    if( QModbusReply *reply=master->sendWriteRequest(mdu,ui->mAddr->text().toUInt() ))
    {
        //����δ���
        if(!reply->isFinished())
        {
            //�󶨻ظ���ɵ��ź�
             connect( reply, &QModbusReply::finished , this ,[this,reply]
             {
                 //���û�д���
                 if(reply->error() == QModbusDevice::NoError)
                 {
                     //�õ���ͨ�ظ�
                     QModbusDataUnit  unit = reply->result();


                      //�õ���λ�õ�ֵ
                     quint16 v=  unit.value(0);

                    //���õ����
                      ui->tableMaster->item(unit.startAddress()  , 1)->setText( QString::number(v));

                     ui->statusbar->showMessage("WriteSingleRegister Success!",5000);

                 }
                 else
                 {
                      ui->statusbar->showMessage(reply->errorString(),5000);
                 }

                 //ͨ���¼�ѭ��ȥ�ӳ�ɾ��
                 reply->deleteLater();
             });
        }
    }
    else
    {
        //reply��NULL
        ui->statusbar->showMessage(master->errorString(),5000);
    }

}

/*
//ʹ��sendRawRequest���� QModbusRequest�������վ��
//�յ���վ�Ļظ�ΪQModbusReply�� QModbusResponse��
void MainWindow::on_m16Btn_clicked()
{
    if(master==nullptr) return;

    QByteArray arr;

    //2�ֽڵ�д��λ�� 0000
    arr.push_back((char)0);
    arr.push_back((char)0);

    //2���ֽڵ�д��������10��ֵ
    arr.push_back((char)0);
    arr.push_back((char)10);

    //1�ֽڵ� ���ݴ�С
    arr.push_back((char)20);

    for (int i=0;i<10;++i)
    {
       QString text= ui->tableMaster->item(i,1)->text();
       if(text.isEmpty()) text="0";

       quint16  v= text.toUInt();

       unsigned char high = v>>8;
       unsigned char low = v ;

       arr.push_back(high);
       arr.push_back(low);

    }

    //���վ����QModbusRequest����
    //16������+ ����
    QModbusRequest mr(QModbusPdu::WriteMultipleRegisters,arr );


    //���վ����rawԭʼ����
   if( QModbusReply *reply= master->sendRawRequest(mr, ui->mAddr->text().toUInt()))
   {
       //�����û��ɻظ�
       if(!reply->isFinished())
       {
            //�󶨻ظ���ɵ��ź�
             connect( reply, &QModbusReply::finished , this ,[this,reply]
             {
                 //���û�д���
                 if(reply->error() == QModbusDevice::NoError)
                 {
                     //�õ�ԭʼ�ظ�
                     QModbusResponse  response= reply->rawResult();
                     //�õ�������
                     QModbusPdu::FunctionCode  code = response.functionCode();
                     //Ȼ��õ����ݲ���
                     QByteArray arr= response.data();

                     //16������Ӧ������
                     // �����ֽڵ���ʼλ��
                     unsigned char  high1 = arr[0];
                     unsigned char  low1 = arr[1];

                      //�����ֽڵ�д������
                     unsigned char  high2= arr[2];
                     unsigned char  low2= arr[3];

                       quint16  pos =  (high1<<8 )| low1;
                       quint16  cnt =  (high2<<8 )| low2;


                       ui->statusbar->showMessage(
                                   QString("WriteMultipleRegisters  %1 , %2  Success!").arg(pos).arg(cnt),5000);

                 }
                 else
                 {
                      ui->statusbar->showMessage(reply->errorString(),5000);
                 }

                 //ͨ���¼�ѭ��ȥ�ӳ�ɾ��
                 reply->deleteLater();
             });
       }
   }
   else
   {   //reply��NULL
        ui->statusbar->showMessage(master->errorString(),5000);
   }
}

*/



//ʹ��  sendWriteRequest  ���� QModbusDataUnit  �������վ����
//�յ���վ�Ļظ�ΪQModbusReply��  QModbusDataUnit ��
void MainWindow::on_m16Btn_clicked()
{
    if(master==nullptr) return;

    //������ֵ
    QVector<quint16> vec;

    for(int i=0;i<10;++i)
    {
        QString text= ui->tableMaster->item(i,1)->text();
        if(text.isEmpty()) text="0";

        quint16  v= text.toUInt();
        vec.push_back(v);
    }


    //���ּĴ���+ ��ʼλ��+���ֵ
    QModbusDataUnit mdu(QModbusDataUnit::HoldingRegisters , 0 ,vec);

    //д����
    if( QModbusReply *reply=master->sendWriteRequest(mdu,ui->mAddr->text().toUInt() ))
    {
        //����δ���
        if(!reply->isFinished())
        {
            //�󶨻ظ���ɵ��ź�
             connect( reply, &QModbusReply::finished , this ,[this,reply]
             {
                 //���û�д���
                 if(reply->error() == QModbusDevice::NoError)
                 {
                     //�õ���ͨ�ظ�
                     QModbusDataUnit  unit = reply->result();

                     ui->statusbar->showMessage(
                     QString("WriteMultipleRegisters  %1 , %2  Success!").
                                 arg(unit.startAddress()).arg(unit.valueCount()),5000);
                 }
                 else
                 {
                      ui->statusbar->showMessage(reply->errorString(),5000);
                 }

                 //ͨ���¼�ѭ��ȥ�ӳ�ɾ��
                 reply->deleteLater();
             });
        }
    }
    else
    {
        //reply��NULL
        ui->statusbar->showMessage(master->errorString(),5000);
    }

}


void MainWindow::on_sConBtn_clicked()
{
    QString strText= ui->sConBtn->text();

    if(strText == QStringLiteral("����"))
    {
        //Modbus RTU
        if(ui->sType->currentText() == "SerialPort")
        {
            //new ��վ����
             slave = new QModbusRtuSerialSlave();

             //���ô��ڲ���
             slave->setConnectionParameter (
              QModbusDevice::SerialPortNameParameter , ui->sIP_COM->text());
            slave->setConnectionParameter(
                        QModbusDevice::SerialParityParameter , QSerialPort::EvenParity);
            slave->setConnectionParameter(
                        QModbusDevice::SerialBaudRateParameter , QSerialPort::Baud9600);
            slave->setConnectionParameter(
                        QModbusDevice::SerialDataBitsParameter , QSerialPort::Data8);
            slave->setConnectionParameter(
                        QModbusDevice::SerialStopBitsParameter , QSerialPort::OneStop);



        }
        else  //Modbus TCP
        {
            //new ��վ����
             slave = new QModbusTcpServer();

             //�ߵ�����,����IP��˿�
             slave->setConnectionParameter(
                         QModbusDevice::NetworkAddressParameter, ui->sIP_COM->text() );
             slave->setConnectionParameter(
                         QModbusDevice::NetworkPortParameter, ui->s_Port->text().toUInt() );
        }

      //���ô�վ��ַ
        slave->setServerAddress( ui->sAddr->text().toUInt());

      //�����źŲ�
        connect(slave, &QModbusDevice::stateChanged ,this ,[this]()
        {
            //������״̬��
            if(slave->state() == QModbusDevice::ConnectedState)
            {
                 ui->sConBtn->setText(QStringLiteral("�Ͽ�"));
                 ui->statusbar->showMessage("Connect Success!",3000);


                 //���ô�վ�����ű�
                 QModbusDataUnitMap map;

                 //�ڴ�վΪ��Ȧ�� ����10��ֵ������
                 map.insert( QModbusDataUnit::Coils , QModbusDataUnit(QModbusDataUnit::Coils ,0 ,10));
                 map.insert( QModbusDataUnit::DiscreteInputs , QModbusDataUnit(QModbusDataUnit::DiscreteInputs ,0 ,10));
                 map.insert( QModbusDataUnit::InputRegisters , QModbusDataUnit(QModbusDataUnit::InputRegisters ,0 ,10));
                 map.insert( QModbusDataUnit::HoldingRegisters , QModbusDataUnit(QModbusDataUnit::HoldingRegisters ,0 ,10));

                 //���ô�վ��map
                 slave->setMap(map);

//                 //�ṩHoldingRegistersһЩ����ֵ
//                 slave->setData(QModbusDataUnit::HoldingRegisters, 0,101 );
//                 slave->setData(QModbusDataUnit::HoldingRegisters, 1,102 );
//                  slave->setData(QModbusDataUnit::HoldingRegisters, 2,103 );
            }
            else
            {
                ui->sConBtn->setText(QStringLiteral("����"));
            }
        });


        // �豸��������ʱ�źš���
       connect(slave, &QModbusServer::errorOccurred, [this](QModbusDevice::Error)
       {
            statusBar()->showMessage(slave->errorString(), 3000);
            ui->sConBtn->setText(QStringLiteral("����"));
        });

       //����վ���վд�����ݵ�ʱ��QModbusServer���������ݱ��ı䣬ͬʱ�ᷢ���ź�
       connect(slave, &QModbusServer::dataWritten, this ,
          [this ]( QModbusDataUnit::RegisterType table, int address, int size)
       {
                //ͬ������UI
                for (int i=0; i<size; ++i)
                 {
                     quint16 v=0;

                     //��ȡ��վĳ�ű�����ĳ��λ�õ�����
                     slave->data( table,address+i,&v );

                     //ȡ������ֵ���µ���վUI
                     ui->tableSlave->item( address+i,1)->setText(QString::number(v));

                 }

        }
       );


       //�����豸
       slave->connectDevice();

    }
    else
    {
        if(slave)
        {
           //�Ͽ�����
            slave->disconnectDevice();
            delete slave;
            slave = nullptr;

        }
    }
}

//���༭�����ݸı��ʱ��������ź�
void MainWindow::on_tableSlave_cellChanged(int row, int column)
{
    if(slave==nullptr) return ;

    //��ȡ���༭�ĵ�Ԫ�������
    QString text=   ui->tableSlave->item(row,column)->text();

    if(text.isEmpty()) text="0";

    //���ı��ֵд���վ��Ӧ����
    QModbusDataUnit::RegisterType registerType=
            (  QModbusDataUnit::RegisterType)ui->sTable->currentData().toUInt();
      slave->setData( registerType , row , text.toUInt() );

}

void MainWindow::on_sTable_currentIndexChanged(int index)
{
    if(slave==nullptr) return ;


    //���ı��ֵд���վ��Ӧ����
    QModbusDataUnit::RegisterType registerType=
            (  QModbusDataUnit::RegisterType)ui->sTable->currentData().toUInt();

    //��UI�е�ֵȫ�����õ��л��ı���ȥ
    for (int i=0;i<10;++i)
    {
        //��ȡ���༭�ĵ�Ԫ�������
        QString text=   ui->tableSlave->item(i,1)->text();

        if(text.isEmpty()) text="0";

        slave->setData( registerType , i , text.toUInt() );
    }

}
