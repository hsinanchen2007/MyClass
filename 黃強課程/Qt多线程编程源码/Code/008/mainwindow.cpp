#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //空闲优先级，只有CPU空闲才调度
    t1= new MyThread("IdlePriority ",QThread::IdlePriority );
    //低优先级
    t2= new MyThread("LowPriority ",QThread::LowPriority);
    //实时优先级，非常高
    t3= new MyThread("TimeCriticalPriority ",QThread::TimeCriticalPriority );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //测试次数越多，结果越精确
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

      //理论上，优先级高的会得到更多的CPU执行，从而执行指定任务花费时间最少
      qDebug()<<t1->name <<QStringLiteral("花费")<<t1->costTime;
      qDebug()<<t2->name <<QStringLiteral("花费")<<t2->costTime;
      qDebug()<<t3->name <<QStringLiteral("花费")<<t3->costTime;


}
