#include "dialwidget.h"
#include "ui_dialwidget.h"
#include<QPainter>
#include<QtMath> //π的头文件

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

     //绘制仪表盘的刻度文字
     drawScaleNum(&painter);

     //绘制仪表盘的指针
     drawPointer(&painter);

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


 void DialWidget::drawScaleNum(QPainter*painter)
 {
        //刻度文字内圈的半径
       int   r = radius *0.9 - 50 ;

       //保存绘制设置，方便后面恢复原来的设置
       painter->save();

       //设置刻度的画笔
       painter->setPen(QPen(Qt::white,1));
       //设置刻度文字的字体
       painter->setFont(QFont("Arial",14));


       for(int i=0;i<=300; i+=50)
      {
            //确定文字的x，y坐标
           int  angle = 240 -i;

           //角度转弧度
           float angleArc =  angle * M_PI /180;

           int x = r  *  cos( angleArc) ;
           int y = -r  *  sin( angleArc) ;

           QString strV= QString("%1").arg(i);

           //获取文本的长宽
           QFontMetricsF fm(painter->font());
           int  w = (int )fm.width(strV);
           int  h = (int )fm.height( );

            //绘制刻度文本
           painter->drawText( x - w/2  ,  y + h/2 ,strV);
       }


       //恢复原来的绘制设置
       painter->restore();

 }


 void DialWidget::drawPointer(QPainter*painter)
 {
        //指针绕一圈的半径
       int   r = radius *0.9 - 60 ;

       //保存绘制设置，方便后面恢复原来的设置
       painter->save();

       //顺时针旋转坐标系30，默认停在0位置
        painter->rotate(30);

        //根据value的值， 旋转度数
       painter->rotate(value);


       //画一个多边形
       QPolygon pts;
       //3个点， （-6，0） （0,6） （0,r）
       pts.setPoints(3, -6 ,0 , 6, 0,0,r);

       //设置画笔与画刷
       painter->setPen(QPen(Qt::white,0.5));
       painter->setBrush( QColor("#FF4500") );

       painter->drawPolygon(pts);


       //设置渐变画刷
          QRadialGradient radial(0, 0, 20);
          radial.setColorAt(0.0, QColor(100, 100, 100));
          radial.setColorAt(1.0, QColor(250, 50, 50));
          painter->setPen(QPen(Qt::white,1));
          painter->setBrush(radial);


       //画圆
       int rCenter = 14;
       painter->drawEllipse( -rCenter , -rCenter
                             , 2*rCenter,2*rCenter);




       //恢复原来的绘制设置
       painter->restore();
 }


 //设置仪表当前值
 void  DialWidget::setValue(int v)
 {
     value= v;

     //刷新一下控件显示，触发paintEvent
     repaint();
 }

 int    DialWidget::getValue( )
 {
     return value;
 }

DialWidget::~DialWidget()
{
    delete ui;
}
