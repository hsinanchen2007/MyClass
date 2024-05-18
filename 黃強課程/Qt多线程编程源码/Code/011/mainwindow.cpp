#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //�������߳�

    t= new MyThread();
    t->start();
    QThread::sleep(1);//ȷ��run����� new Test�Ѿ�ִ��

    //��main���߳���Ϊ���ź��ߵ��̣߳�sender Ϊmainwindow����
    //�� t���߳���Ϊ�����źŵ��߳�(recieverΪ test����)

    //DirectConnection ������ֱ�ӵ��òۺ������ۺ�����sender���ڵ��߳���ִ�С�
   // connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::DirectConnection  );

    //QueuedConnection ͨ���¼�ѭ�����òۺ������ۺ�����receiver�����̵߳��á�
   //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::QueuedConnection  );

    //BlockingQueuedConnection  ͨ���¼�ѭ�����òۺ������ۺ�����receiver�����̵߳��ã��ڲۺ����������֮ǰ������ sender���ڵ��߳�
   //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::BlockingQueuedConnection  );

    //AutoConnection   �Զ����ӣ���Ĭ��ֵ��
   // ���sender��receiver����ͬһ���̣߳����ͬ��Qt::DirectConnection�������ͬ��Qt :: QueuedConnection
   //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot,Qt::AutoConnection  );
    //connect( this, &MainWindow::mySig,  t->test, &Test::MySlot);

    //UniqueConnection,�������ĸ����ʹ�ã���ֹ��ΰ�
    connect( this, &MainWindow::mySig,  t->test, &Test::MySlot, Qt::AutoConnection);
    connect( this, &MainWindow::mySig,  t->test, &Test::MySlot, (Qt::ConnectionType) (Qt::UniqueConnection | Qt::AutoConnection));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   //�����ź�
    emit  mySig();

    qDebug()<<"on_pushButton_clicked";

}
