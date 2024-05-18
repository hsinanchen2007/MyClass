#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"readthread.h"
#include"writethread.h"


//��д������
QReadWriteLock  rwLock;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_readButton_clicked()
{
    //��Ϊ�ӵ��Ƕ�������������������ͬʱ���ģ����Կ���ͬʱ��ȡ
    ReadThread  t1("AAA");
    ReadThread  t2("BBB");

    t1.start();
    t2.start();

    t1.wait();
}

void MainWindow::on_writeButton_clicked()
{
    //��Ϊ�ӵ���д��������д���ǲ�����ͬʱд�ģ�����һ��ֻ��һ���߳�д
    WriteThread  t1("AAA");
    WriteThread  t2("BBB");

    t1.start();
    t2.start();

    t1.wait();
}

void MainWindow::on_rwButton_clicked()
{
      //�ȶ�
       ReadThread  t1("AAA");
       t1.start();

       QThread::usleep(1);//ȷ�����߳�������

       //���Զ���ʱ���Ƿ�����д
        WriteThread  t2("BBB");
         t2.start();

         t1.wait();
}

void MainWindow::on_wrButton_clicked()
{
    //��д
     WriteThread  t1("AAA");
      t1.start();


      QThread::usleep(1);//ȷ��д�߳�������

    //����д��ʱ�������
     ReadThread  t2("BBB");
     t2.start();


       t1.wait();
}
