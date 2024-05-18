#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QBitmap>


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

    /*
   //以下演示QImage 与 drawImage
    //绘图
    QImage img(":/imgs/beach.png");
    //指定左上角点绘制图片（原尺寸）
    painter.drawImage(0,0, img);


   //绘制一个矩形，方便大家观察
    QRect  rect(100,100,200,200);
    painter.drawRect(rect);

    //绘制图片的某个区域
    //在窗口坐标（400,100）的位置绘制img某个区域的图片
    painter.drawImage(400,100,img, 100,100,200,200 );


    //缩放绘制某张图像
    QImage img2(":/imgs/boat.bmp");
    painter.drawImage(QRect(0,300,200,200),img2);


    //裁剪并且缩放绘制图像
    QImage img3(":/imgs/dog.jpg");
    painter.drawImage(QRect(300,300,200,200),
                      img3,QRect(200,100,100,100));

*/


    /*
    //以下演示QPixmap  与  drawPixmap
    //绘图
    QPixmap img(":/imgs/beach.png");
    //指定左上角点绘制图片（原尺寸）
    painter.drawPixmap(0,0, img);


   //绘制一个矩形，方便大家观察
    QRect  rect(100,100,200,200);
    painter.drawRect(rect);

    //绘制图片的某个区域
    //在窗口坐标（400,100）的位置绘制img某个区域的图片
    painter.drawPixmap(400,100,img, 100,100,200,200 );


    //缩放绘制某张图像
    QPixmap img2(":/imgs/boat.bmp");
    painter.drawPixmap(QRect(0,300,200,200),img2);


    //裁剪并且缩放绘制图像
    QPixmap img3(":/imgs/dog.jpg");
    painter.drawPixmap(QRect(300,300,200,200),
                      img3,QRect(200,100,100,100));


*/

    //以下演示QBitmap  与  drawPixmap
    //绘图
    QBitmap img(":/imgs/beach.png");
    //指定左上角点绘制图片（原尺寸）
    painter.drawPixmap(0,0, img);


   //绘制一个矩形，方便大家观察
    QRect  rect(100,100,200,200);
    painter.drawRect(rect);

    //绘制图片的某个区域
    //在窗口坐标（400,100）的位置绘制img某个区域的图片
    painter.drawPixmap(400,100,img, 100,100,200,200 );


    //缩放绘制某张图像
    QBitmap img2(":/imgs/boat.bmp");
    painter.drawPixmap(QRect(0,300,200,200),img2);


    //裁剪并且缩放绘制图像
    QBitmap img3(":/imgs/dog.jpg");
    painter.drawPixmap(QRect(300,300,200,200),
                      img3,QRect(200,100,100,100));



}

MainWindow::~MainWindow()
{
    delete ui;
}

