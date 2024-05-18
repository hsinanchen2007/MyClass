#include "dialwidget.h"
#include "ui_dialwidget.h"
#include<QPainter>

DialWidget::DialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialWidget)
{
    ui->setupUi(this);
}

 void DialWidget::paintEvent(QPaintEvent *event)
 {
     //定义画家类
     QPainter painter(this);

     //以矩形短的一条边为 圆盘的直径
     int w= width();
     int h = height();
     radius = qMin(w,h)/2;

     //反锯齿设置
     painter.setRenderHint(QPainter::Antialiasing);

     //将坐标系平移到窗口中心，方便后面绘制
     painter.translate( w/2, h/2);

     //绘制仪表盘的背景
     drawBg(&painter);

     //绘制仪表盘的刻度
     drawScale(&painter);


 }


 void DialWidget::drawBg(QPainter*painter)
 {
     int  r= radius;

     //设置画笔
     painter->setPen(QPen(Qt::white,5));

     //画5块饼图，每个60度 , 弧度需要乘16
     painter->setBrush(Qt::red );
     painter->drawPie(-r,-r , 2*r ,2*r , -60 *16 ,60*16);

     QColor yellow = QColor("#FF9C0E");
     painter->setBrush(yellow);
     painter->drawPie(-r, -r, r * 2, 2*r,0*16,60*16);

     QColor green = QColor("#1FFF8B");
     painter->setBrush(green);
     painter->drawPie(-r, -r, r * 2, 2*r,60*16,60*16);

     painter->setBrush(yellow);
     painter->drawPie(-r, -r, r * 2, 2*r,120*16,60*16);

     painter->setBrush(Qt::red );
     painter->drawPie(-r, -r, r * 2, 2*r,180*16,60*16);


     //画内表盘圆形
       r = radius *0.9;
       painter->setBrush( QColor("#7B68EE") );
       painter->drawEllipse(-r, -r,  r * 2,  2*r  );


 }



 void DialWidget::drawScale(QPainter*painter)
 {
        //画内表盘圆形
       int   r = radius *0.9;

       //保存绘制设置，方便后面恢复原来的设置
       painter->save();

       //设置刻度的画笔
       painter->setPen(QPen(Qt::white,1));


       //旋转坐标系
       //负数逆时针旋转240度
       painter->rotate(-240);


       for(int i=0; i<= 300/10 ;++i)
       {
           if(i%5==0)
           {
              //绘制一条长刻度线
                painter->drawLine(r,0, r-30, 0);
           }
           else
           {
               //绘制一条短刻度线
               painter->drawLine(r,0, r-20, 0);
           }

           //旋转坐标系
           //正数顺时针旋转10度
           painter->rotate(10);
       }


       //恢复原来的绘制设置
       painter->restore();

 }


DialWidget::~DialWidget()
{
    delete ui;
}
