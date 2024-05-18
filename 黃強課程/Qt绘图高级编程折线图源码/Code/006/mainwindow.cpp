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
    QPen  pen(Qt::red);
    pen.setWidth(3);

    //为画家设置画笔
    painter.setPen(pen);

    //画折线
    QPoint pts[] ={
                    QPoint(100,100),
                    QPoint(200,100),
                    QPoint(300,150),
                    QPoint(500,50)  };
    painter.drawPolyline(pts, 4);

    //设置画刷
    QBrush bsh(Qt::cyan);
    painter.setBrush(bsh);


    //画多边形(点的顺序会影响图形)
    QPoint pts2[] ={
                    QPoint(300,200),
                     QPoint(350,450) ,
                     QPoint(200,300),
                     QPoint(400,300) ,
                    QPoint(300,400),
    };
    painter.drawPolygon(pts2, 5);

}




MainWindow::~MainWindow()
{
    delete ui;
}

