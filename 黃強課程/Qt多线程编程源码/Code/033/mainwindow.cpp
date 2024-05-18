#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtConcurrent>
#include<QThread>
#include<QDebug>
#include<QList>

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

void Add(int &a) //传引用
{
    qDebug()<<QStringLiteral("开始运算")<<a<<QThread::currentThread();
    QThread::sleep(1);//模拟耗时
    a+=1;
    qDebug()<<QStringLiteral("结束运算");
}


int  Add2(int  a) //不传引用
{
    qDebug()<<QStringLiteral("开始运算")<<a<<QThread::currentThread();
    QThread::msleep(2);//模拟耗时2毫秒
    a+=1;
    qDebug()<<QStringLiteral("结束运算");
    return a;
}

void  Sum(int & r , int e)
{
    qDebug()<<QStringLiteral("开始Sum")<<r<<"   "<<e<<QThread::currentThread();
    QThread::msleep(1);//模拟耗时1毫秒
    r+=e;
    qDebug()<<QStringLiteral("结束Sum运算");
}


QFuture<int>  f ;

void MainWindow::on_mappedReducedButton_clicked()
{
    //容器有QVector  QList  ,要求这个容器有begin、end
    QList<int> list;
    for (int i=0;i<10000;++i) {
        list.append(0);
    }


    //对容器中的每个元素执行Add运算、不修改原容器，
    //而是返回一个新容器存放修改后的结果、并且还对新容器进行Sum运算
    f =  QtConcurrent::mappedReduced(list ,Add2,Sum );
  // f.waitForFinished();//等待执行结束
  // qDebug()<<f.result()<<f.results() ;
}


void MainWindow::on_stateButton_clicked()
{
   qDebug()<<QStringLiteral("任务状态： 已开始%1 取消%2 暂停%3 运行%4 完成%5")
             .arg( f.isStarted()).arg(f.isCanceled()).arg(f.isPaused())
             .arg(f.isRunning()).arg(f.isFinished());

   if( f.isFinished())
   {
        qDebug()<<f.results() ;
   }
}

void MainWindow::on_cancelButton_clicked()
{
    qDebug()<<QStringLiteral("取消！");
    f.cancel();
}

void MainWindow::on_pauseButton_clicked()
{
    qDebug()<<QStringLiteral("暂停！");
    f.pause();
}

void MainWindow::on_resumeButton_clicked()
{
    qDebug()<<QStringLiteral("恢复！");
    f.resume();
}
