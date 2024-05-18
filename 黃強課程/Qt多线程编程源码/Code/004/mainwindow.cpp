#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //�����źźͲ�
    connect(&t, &MyThread::started,this , &MainWindow::ThreadStarted  );
    connect(&t, &MyThread::finished,this , &MainWindow::ThreadFinished );


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startBtn_clicked()
{
   //������,��ʼִ���߳�
    t.start();

}

void MainWindow::on_termiateBtn_clicked()
{
   //��ֹ�̣߳����Ƽ�ʹ�ã���Ϊ��ǿ����ֹ���룬����һЩ��Դ�޷��ͷ�
    t.terminate();
}

void MainWindow::on_statusBtn_clicked()
{
   //�߳�״̬
   qDebug()<<"isRunning "<<t.isRunning()<<"   isFinished"<<t.isFinished();
}


void  MainWindow::ThreadStarted()
{
     qDebug()<<"ThreadStarted.....";
}
void  MainWindow::ThreadFinished()
{
    qDebug()<<"ThreadFinished....";
}
