#include "mychart.h"
#include "ui_mychart.h"
#include<QPainter>
#include<QtMath>

MyChart::MyChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyChart)
{
    ui->setupUi(this);
}

MyChart::~MyChart()
{
    delete ui;
}

void MyChart::paintEvent(QPaintEvent *event)
{

    //定义画家类
    QPainter  painter(this);

    //画一个背景矩形
    painter.fillRect( 0,0, width(),height(),QBrush(Qt::gray));

    //坐标轴的绘制区域
    rect = QRect( 50,50 , width()-50*2 , height()-50*2);
    //painter.fillRect(  rect ,QBrush(Qt::red));


    //画坐标轴
    drawAxis(&painter);
}

void MyChart::SetAxisText(QString x, QString y)
{
    this->xTitle = x;
    this->yTitle = y;
}

void MyChart::drawAxis(QPainter *painter)
{

    //y轴
   drawArrorLine( QLine(rect.bottomLeft() , rect.topLeft()) , painter );
   painter->drawText( rect.topLeft().x() ,
                      rect.topLeft().y() - 20, yTitle );

   //x轴
   drawArrorLine( QLine(rect.bottomLeft() , rect.bottomRight()) , painter);
   painter->drawText( rect.bottomRight().x() ,
                      rect.bottomRight().y() - 20, xTitle );

}

void MyChart::drawArrorLine(QLine line, QPainter *painter)
{
    //画出这条直线
     painter->drawLine(line);

     //加上 箭头
     double len = 10;//箭头长度
     double angle = 0.5;//箭头和直线直接的夹角

     //求出直线与水平线的夹角s
     //手动加负号是因为qt y轴与数学坐标系y轴方向相反
     double s = - atan2(   (line.y2() - line.y1()) , (line.x2() - line.x1())  );


     //根据课件图解

     // 求得箭头点 1 的坐标
        double x11 = line.x2() - len * cos(s- angle);
        //y轴向下为正
        double y11 = line.y2() + len * sin(s - angle);

        // 求得箭头点 2 的坐标
        double x22 = line.x2() - len * cos(s + angle);
         //y轴向下为正
        double y22 = line.y2() + len * sin(s + angle);

        //连起来
        painter->drawLine(  x11,y11,   line.x2()  ,line.y2() );
        painter->drawLine(  x22,y22,   line.x2()  ,line.y2() );

}
