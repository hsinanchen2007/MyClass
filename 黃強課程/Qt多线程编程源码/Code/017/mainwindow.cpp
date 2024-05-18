#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"mythread.h"

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


void MainWindow::on_pushButton_clicked()
{
     //����������ƱԱ
     MyThread t1("AAA");
     MyThread t2("BBB");

     //ͬʱ��ʼ��Ʊ
     t1.start();
     t2.start();

     //�ȴ������߳�ִ�����
     t1.wait();
     t2.wait();

}
