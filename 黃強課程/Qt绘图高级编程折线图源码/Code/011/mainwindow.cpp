#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>

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

    //首先绘制一个参考的矩形
   painter.drawRect(0,0,100,100);

   //平移坐标系, 向x轴正方向(向右)移动200
   //向y轴正方向(向下)移动200
    painter.translate(200,200);

   //重新绘制一个矩形
   painter.setPen(Qt::red);
   painter.drawRect(0,0,100,100);


   //缩放坐标系
   painter.scale(2,2);//表示x轴坐标*2， y轴坐标*2
   painter.setPen(Qt::blue);
   painter.drawRect(0,0,100,100);


   //旋转坐标系（绕着原点旋转）

   painter.rotate(20);//顺时针旋转20度

   painter.setPen(Qt::green);
   painter.drawRect(0,0,100,100);
   painter.drawText(0,0,"旋转了20度");

   painter.rotate(40);//顺时针再旋转40度(在上一次的基础上)

   painter.setPen(Qt::cyan);
   painter.drawRect(0,0,100,100);
   painter.drawText(0,0,"旋转了40度");

}

MainWindow::~MainWindow()
{
    delete ui;
}

