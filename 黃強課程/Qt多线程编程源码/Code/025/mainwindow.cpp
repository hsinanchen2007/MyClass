#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"mythread.h"

//ȫ�ֱ���
//int N=0;

//ԭ������(ֻ����������)���̰߳�ȫ��
QAtomicInteger<int>  N;

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

    N =0; //����ʼֵ

    //�����߳�
    MyThread t1;
    MyThread t2;

    t1.start();
    t2.start();


    t1.wait();
    t2.wait();

    qDebug()<<QStringLiteral("N����20���֮������ ")<<N;

}
