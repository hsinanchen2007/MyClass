#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include<QBitmap>
#include<QPicture>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    {
    //定义画家 ,需要一个画板(QPaintDevice)对象来构造
    QPainter painter;

    //定义一个QPicture，作为画板
    QPicture pic;

    //开始绘制到pic中
    painter.begin(&pic);


    //将beach.png绘制到QPicture对象中
    QPixmap img1(":/imgs/beach.png");
    painter.drawPixmap(0,0,img1);


    //将lawn.png平铺绘制到QPicture对象中
    QPixmap img2(":/imgs/lawn.png");
    painter.drawTiledPixmap(QRect(0,0,300,300),img2);


    //结束绘制
    painter.end();

   //QPicture的内容保存为文件
    pic.save("my.pic");
    }


    //下面可以测试my.pic文件
    {

        //定义画家 ,需要一个画板(QPaintDevice)对象来构造
        QPainter painter(this);

        //定义一个QPicture，作为画板
        QPicture pic;
        pic.load("my.pic");//加载图像文件

        //QPicture将绘制到窗口上
        painter.drawPicture(0,0,pic);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

