#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //���̵߳��źŲ�
    connect(&t, &QThread::started , this , &MainWindow::startSlot);
    connect(&t, &QThread::finished , this ,  &MainWindow::finishSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
      t.start();//�����߳�,����QThread::run

      qDebug()<<QStringLiteral("��ʼQThread����");

     // t.wait();//�ȴ�t�߳�ִ�н���

     qDebug()<<QStringLiteral("on_startButton_clicked");

}

void MainWindow::on_statusButton_clicked()
{
    qDebug()<<QStringLiteral("�߳�״̬ ")<<t.isRunning();
}

void MainWindow::on_exitButton_clicked()
{
   // t.exit();//�˳�QThread��run������exec�е�whileѭ��

    t.quit();//���ʾ��ǵ���exit(0)
}


void MainWindow::startSlot()
{
     qDebug()<<QStringLiteral("�߳̿�ʼ������ ");
}
void MainWindow::finishSlot()
{
     qDebug()<<QStringLiteral("�߳̽����� ");
}
