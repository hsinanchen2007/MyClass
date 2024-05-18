#include "warnwidget.h"
#include "ui_warnwidget.h"

WarnWidget::WarnWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarnWidget)
{
    ui->setupUi(this);
}


void WarnWidget::paintEvent(QPaintEvent *event)
{
    //画家类
    QPainter  painter(this);

   //获取窗口的长宽
    int w = width();
    int h = height();

    //把原点(0,0)移动到窗口中心
    painter.translate(w/2,h/2);

   //反锯齿
    painter.setRenderHint(QPainter::Antialiasing);

    //画表盘的背景
    drawBg(&painter);

    //画最内圈半圆
    drawHalf(&painter);

    //画刻度值
    drawKedu(&painter);

}

void WarnWidget::drawBg(QPainter *painter)
{


    //画圆弧
    QRect  rect1(-r1,-r1, 2*r1,2*r1);
    QRect  rect2(-r2,-r2, 2*r2,2*r2);

    //自定义灰色
    QColor colorGray(26,59,107,125);

   QPen p1;
   p1.setColor( colorGray);
   p1.setWidth(w1);
   p1.setCapStyle(Qt::FlatCap);

   //设置画笔
    painter->setPen( p1);

    // 180度 正值从0度开始逆时针方向180度 ，
    //偏移度数-180 表示 顺时针偏移180度
    //度数需要*16

    int BLANK =2;//空隙
    for(int i=0;i<12;++i) //分为12段 ，180度/12 = 15度
    {
         //painter->drawArc( rect1,  180*16 ,  -180*16);

        int startAng = 180 -i*15;
        int  alen =  15- BLANK; //减去空隙
        if(i == 11) alen = 15; //最后一个偏移直接为15

        //第一圈
        painter->drawArc( rect1,startAng*16 , -alen*16);
        //第二圈
        painter->drawArc( rect2,startAng*16 , -alen*16);
    }

}

void WarnWidget::drawHalf(QPainter *painter)
{

    //画第三圈
    QRect rect3(-r3,-r3, 2*r3, 2*r3);

    painter->setPen(QPen(Qt::white,1));

    painter->setBrush(QBrush(Qt::red));

    //画半圆（饼图）
    painter->drawPie( rect3,  180*16 ,  -180*16 );
}

void WarnWidget::drawKedu(QPainter *painter)
{
 //先保存场景设置
    painter->save();

    //刻度值在最外圈绘制
    int  r = r1+w1;//画笔很粗

    //设置画笔
       QColor colorGray(26,59,107);
       QPen pen(colorGray , 1);
       painter->setPen(pen);

       //设置字体
       painter->setFont(QFont("Arial", 12));

       //逆时针旋转坐标系90度
       painter->rotate(-90);

       //分成5份， 6个值
       for (int i=0;i<6;++i)
       {
           //平均值
           double   avg =  (max -min )/5;
           double  v= min + i *avg;

           //保留小数位
           QString strV =  QString::number(v, 'f' ,precise);

           QFontMetricsF fm(painter->font());
           int w = fm.width(strV);
           int h = fm.height();
           painter->drawText(  0-w/2, -r  ,strV);

           //顺时针旋转
           painter->rotate( 180/ 5 );
       }


    //恢复场景设置
    painter->restore();
}



void WarnWidget::setRadius(int r1, int w1, int r2, int w2, int r3)
{
    this->r1 = r1;
    this->r2 = r2;
    this->r3 = r3;

    this->w1 = w1;
    this->w2 = w2;

    //重绘，调用paintEvent
    repaint();
}

void WarnWidget::setRange(double min, double max)
{
    this->min = min;
    this->max = max;

    //强制刷新
    repaint();
}

void WarnWidget::setPrecise(int n)
{
    precise= n;

    //强制刷新
    repaint();
}

WarnWidget::~WarnWidget()
{
    delete ui;
}
