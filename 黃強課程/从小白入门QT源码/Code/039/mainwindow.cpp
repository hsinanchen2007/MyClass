#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置文本的对齐方式
    ui->progressBar->setAlignment(Qt::AlignHCenter);

    //设置当前值
    ui->progressBar->setValue(20);

    //设置范围
    ui->progressBar->setRange(0,100);

    //定义一个定时器改变进度条的进度
      QTimer *t = new QTimer(this);

      //将定时器超时信号与槽(功能函数)联系起来
      connect( t,SIGNAL(timeout()), this, SLOT(timeFun()) );

      //开始运行定时器，间隔为100ms
       t->start(100);



}

void  MainWindow::timeFun()
{
    int  val= ui->progressBar->value();
     ui->progressBar->setValue( val+1  );
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    qDebug()<<"进度"<<value<<endl;
}
