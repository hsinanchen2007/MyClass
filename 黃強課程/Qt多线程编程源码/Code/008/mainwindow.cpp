#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //�������ȼ���ֻ��CPU���вŵ���
    t1= new MyThread("IdlePriority ",QThread::IdlePriority );
    //�����ȼ�
    t2= new MyThread("LowPriority ",QThread::LowPriority);
    //ʵʱ���ȼ����ǳ���
    t3= new MyThread("TimeCriticalPriority ",QThread::TimeCriticalPriority );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //���Դ���Խ�࣬���Խ��ȷ
      for(int i=0;i<10;++i)
      {
          t1->start();
          t2->start();
          t3->start();
          t1->wait();
          t2->wait();
          t3->wait();
          qDebug()<<i;
      }

      //�����ϣ����ȼ��ߵĻ�õ������CPUִ�У��Ӷ�ִ��ָ�����񻨷�ʱ������
      qDebug()<<t1->name <<QStringLiteral("����")<<t1->costTime;
      qDebug()<<t2->name <<QStringLiteral("����")<<t2->costTime;
      qDebug()<<t3->name <<QStringLiteral("����")<<t3->costTime;


}
