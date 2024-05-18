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

   //绘制方案一
    painter.setPen(Qt::blue);
    painter.setFont(QFont("草书",16,QFont::Bold));

    painter.drawText(100,100,"绘制一段横向文字！");

    //保存方案一中的绘图设置
    painter.save();


   //绘制方案二
    painter.rotate(30);
    painter.setPen(Qt::red);
    painter.setFont(QFont("华文行楷",16,QFont::Bold));

    painter.drawText(200,200,"绘制一段斜方向文字！");


    /*
    //又想横向显示文字，把设置全部又重新设置了一遍
    //如果设置项目多了，将会非常繁琐麻烦
    painter.rotate(-30);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("草书",16,QFont::Bold));
*/

    //这个时候想恢复方案一的绘画设置
    painter.restore();//与save成对出现


    painter.drawText(100,400,"再绘制一段横向文字！");

}

MainWindow::~MainWindow()
{
    delete ui;
}

