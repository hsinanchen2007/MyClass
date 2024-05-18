#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QRunnable>
#include<QDebug>
#include<QThread>

//可执行的任务
class  MyTask:public QRunnable
{
public:
    MyTask(QString name)
    {
        this->name= name;
    }
    virtual void run()
    {
            qDebug()<<name<<QStringLiteral("开始执行")<<QThread::currentThread();
            QThread::sleep(10);
            qDebug()<<name<<QStringLiteral("结束执行!");
    }
    ~MyTask( )
    {
        qDebug()<<name<<QStringLiteral("被销毁!");
    }
private:
    QString name;

};



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

void MainWindow::on_activeThreadNumButton_clicked()
{
     qDebug()<<QStringLiteral("活动线程数!")<<pool.activeThreadCount();
}


void MainWindow::on_startButton_clicked()
{
   //设置线程池最大的线程数量
    pool.setMaxThreadCount(3);

    for (int i=1;i<=5;++i)
    {
        //产生一些任务（默认会被线程池自动销毁）
        MyTask * t = new MyTask(QStringLiteral("任务%1").arg(i) );
        t->setAutoDelete(false);//设置任务执行完毕后不被销毁
        //放到线程池中去执行
        pool.start(t);
    }

     qDebug()<<QStringLiteral("函数结束!");
}



void MainWindow::on_prioityButton_clicked()
{
    //设置线程池最大的线程数量
     pool.setMaxThreadCount(3);

     for (int i=1;i<=10;++i)
     {
         //产生一些任务（默认会被线程池自动销毁）
         MyTask * t = new MyTask(QStringLiteral("任务%1").arg(i) );
         t->setAutoDelete(false);//设置任务执行完毕后不被销毁
         //放到线程池中去执行
         pool.start(t, i );//带优先级
     }

      qDebug()<<QStringLiteral("函数结束!");
}

void MainWindow::on_waitButton_clicked()
{
    //设置线程池最大的线程数量
     pool.setMaxThreadCount(3);

     for (int i=1;i<=5;++i)
     {
         //产生一些任务（默认会被线程池自动销毁）
         MyTask * t = new MyTask(QStringLiteral("任务%1").arg(i) );
         t->setAutoDelete(false);//设置任务执行完毕后不被销毁
         //放到线程池中去执行
         pool.start(t, i );//带优先级
     }

     //等待线程池中的所有任务执行完毕之后才继续向下，否则就阻塞
     //传入-1 代表永远不超时，一直等待
      pool.waitForDone(  -1 );
      //可以指定超时时间，只等待3s
     // pool.waitForDone(  3000 );

      qDebug()<<QStringLiteral("函数结束!");
}
