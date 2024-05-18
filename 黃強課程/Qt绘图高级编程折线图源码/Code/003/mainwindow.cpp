#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义定时器（使用定时器，减少鼠标操作对paintEvent的影响）
    QTimer *timer = new QTimer();

    //绑定信号槽
     connect(timer, &QTimer::timeout ,[=]
     {
         qDebug()<<"定时器触发了！";

         timer->stop();//至触发一次就停了

         //连续调用3次，观察paintEvent函数被调用的次数
        //repaint();      repaint();      repaint();

         //连续调用3次，观察paintEvent函数被调用的次数
         update();      update();      update();

     });

     //3秒后触发timeout信号
     timer->start(3000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{

    static int  i=0;

    qDebug()<<"paintEvent被系统自动调用"<<++i;

}



