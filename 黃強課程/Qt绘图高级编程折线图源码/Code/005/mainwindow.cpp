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
    QPen pen( Qt::red );
    // 设置粗细
    pen.setWidth(3);

    //把画笔给画家
    painter.setPen(pen);

    //画矩形(长方形，正方形)
    QRect  r1(100,100,300,200 );
    painter.drawRect( r1 );

  //画圆角矩形
    QRect  r2(400,400,300,200 );
    painter.drawRoundedRect(  r2,  30, 30);

    //使用画刷涂色
    QBrush bsh(Qt::green);

    //把画刷给画家
    painter.setBrush(bsh);

    //画椭圆（圆）
    QRect  r3(0,0,300,300 ); //外接矩形
    painter.drawEllipse( r3);
}


MainWindow::~MainWindow()
{
    delete ui;
}

