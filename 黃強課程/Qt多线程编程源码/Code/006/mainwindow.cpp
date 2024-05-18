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
    /*
    //��һ���߳�ִ��5��
    MyThread  t1("AAA", 5);
    t1.start();

    //wait������������������ʱ
    bool  ret=t1.wait(10000);//�˴��������̣߳��ȴ�t1�߳�ִ�����֮��Ž������
                           //����3�볬ʱҲֹͣ����

    if(ret)
    {
        qDebug()<<QStringLiteral("�߳̽�����wait����!");
    }
    else
    {
         qDebug()<<QStringLiteral("wait��ʱ����!");
    }


    */

    MyThread  t1("AAA", 3);
    t1.start();

    MyThread  t2("BBB", 2);
    t2.start();

    MyThread  t3("CCC", 3);
    t3.start();


    t1.wait(); //�ȴ�t1ִ�����
    t2.wait();//�ȴ�t2ִ�����
    t3.wait();//�ȴ�t3ִ�����

    qDebug()<<"on_pushButton_clicked()";

}
