#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"readthread.h"
#include"writethread.h"


//读写锁变量
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
    //因为加的是读的锁，而读锁是允许同时读的，所以可以同时读取
    ReadThread  t1("AAA");
    ReadThread  t2("BBB");

    t1.start();
    t2.start();

    t1.wait();
}

void MainWindow::on_writeButton_clicked()
{
    //因为加的是写的锁，而写锁是不允许同时写的，所以一次只能一个线程写
    WriteThread  t1("AAA");
    WriteThread  t2("BBB");

    t1.start();
    t2.start();

    t1.wait();
}

void MainWindow::on_rwButton_clicked()
{
      //先读
       ReadThread  t1("AAA");
       t1.start();

       QThread::usleep(1);//确保读线程先启动

       //测试读的时候是否允许写
        WriteThread  t2("BBB");
         t2.start();

         t1.wait();
}

void MainWindow::on_wrButton_clicked()
{
    //先写
     WriteThread  t1("AAA");
      t1.start();


      QThread::usleep(1);//确保写线程先启动

    //测试写的时候不允许读
     ReadThread  t2("BBB");
     t2.start();


       t1.wait();
}
