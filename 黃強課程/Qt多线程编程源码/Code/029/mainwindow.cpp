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

MyTask * t5;

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

        if(i==5) t5=t;
    }

     qDebug()<<QStringLiteral("函数结束!");
}




void MainWindow::on_tryStartButton_clicked()
{
    MyTask * t = new MyTask(QStringLiteral("任务%1").arg(10) );
     t->setAutoDelete(true);//设置为执行完毕之后销毁

    //尝试执行一个任务、如果没有空闲线程，任务不会执行，并且返回false
    //否则执行返回true
   bool  ret=  pool.tryStart(t);
   qDebug()<<QStringLiteral("尝试执行")<<ret;
}

void MainWindow::on_tryTakeButton_clicked()
{
    //只能移除队列中任务，失败返回false
    bool  ret= pool.tryTake(t5);
    qDebug()<<QStringLiteral("尝试移除")<<ret;
}

void MainWindow::on_clearButton_clicked()
{
    //清除队列中所有任务
    pool.clear();
     qDebug()<<QStringLiteral("清除队列中所有任务");
}
