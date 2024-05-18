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

    //定义画笔
    QPen pen( QBrush( Qt::red) , 15);

    //把画笔给画家
    painter.setPen(pen);

    //开始画点
    painter.drawPoint(QPoint( 0,0));

    painter.drawPoint(QPoint( 100,100));

    //画多个点
    QPoint pts[]={  QPoint( 200,200),QPoint( 300,300) };

    painter.drawPoints(pts,2);


    //修改画笔颜色
    pen.setColor(Qt::blue);
    //修改画笔的粗细
    pen.setWidth(1);

    //重新设置画笔
    painter.setPen(pen);

    //画直线
    painter.drawLine(QPoint( 200,200),QPoint( 300,300)  );

    QLine line(400,400,  500,500);
    QLine line2(10,10,  300,20);
    QLine lines[] ={  line, line2};
    //画多条线
    painter.drawLines(lines,2  );
}


MainWindow::~MainWindow()
{
    delete ui;
}

