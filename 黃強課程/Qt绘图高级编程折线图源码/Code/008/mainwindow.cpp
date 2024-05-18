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

    //定义参考矩形
    QRect  r1(100,100,200,200);
    painter.drawRect(r1);

    //设置画家写字的字体
    //字体名， 字体大小，粗体，是否斜体
    QFont font( "楷体",15, QFont::Bold ,true);
    painter.setFont(font);

    //设置画笔
    QPen pen(QBrush(Qt::red) ,1);
    painter.setPen(pen);

    //写文本,坐标为文字的左下角
    painter.drawText(100,100, "黄强老师!");

    //在矩形内写文本
    painter.drawText(r1, "你好啊!");

    //在矩形中心位置写文本
    painter.drawText(r1, Qt::AlignCenter,"居中");

  //在矩形右下角写文本
    painter.drawText(r1,
     Qt::AlignRight| Qt::AlignBottom,"右下角");


    //在矩形内写大量文字
    QString str= "你好啊，这是测试文字换行!";

    //获取给定宽度，文本， 所需要的实际矩形
    QRect bdRect = painter.boundingRect(
         QRect(0,0,300,0 ), Qt::TextWordWrap,str    );
    //绘制返回的矩形
    painter.drawRect(bdRect);

    //验证一下能不能全部包住
    painter.drawText( bdRect ,Qt::TextWordWrap,str );


    //获取一行文本在给定字体下的长度，宽度
    QFontMetricsF fm ( painter.font()  );
     qreal w=  fm.width(str);//宽度根据文本来确定
     qreal h=  fm.height();//高度是根据字体就可以确定
     qDebug()<<w<<"    "<<h <<"    "<<fm.maxWidth();

}

MainWindow::~MainWindow()
{
    delete ui;
}

