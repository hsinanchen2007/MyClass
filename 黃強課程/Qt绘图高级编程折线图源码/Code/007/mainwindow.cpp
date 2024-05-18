#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    //定义画家 ,需要一个画板(QPaintDevice)对象来构造
    QPainter painter(this);

    //确定圆弧所在的圆,就要确定外接矩形
    QRect r1(100,100,200,200);
    painter.drawRect(r1);

    //设置画笔
    QPen pen(QBrush(Qt::red) ,3);
    painter.setPen(pen);

    //画圆弧 , N*16表示16度
    //从0度开始, 正数表示正向(逆时针)偏移90度
    painter.drawArc(r1, 0*16, 90*16);

     pen.setColor(Qt::blue);
    painter.setPen( pen );


    //从-30度开始, 负数表示反向(顺时针)偏移60度
    painter.drawArc(r1, -30*16, -60*16);

   //恢复画笔
    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter.setPen( pen );


    //确定圆弧所在的圆,就要确定外接矩形
    QRect r2(400,100,200,200);
    painter.drawRect(r2);

   pen.setColor(Qt::red);
   painter.setPen( pen );

  painter.setBrush(QBrush(Qt::red));


    //画 扇形
    painter.drawPie( r2 , 0*16, 90*16);

    pen.setColor(Qt::blue);
   painter.setPen( pen );

   painter.setBrush(QBrush(Qt::blue));



   //从-30度开始, 负数表示反向(顺时针)偏移60度
   painter.drawPie(r2, -30*16, -60*16);
}

MainWindow::~MainWindow()
{
    delete ui;
}

