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

    //绘制进度颜色
    drawProgress(&painter);


    //画最内圈半圆
    drawHalf(&painter);

    //画刻度值
    drawKedu(&painter);


    //画表盘指针
    drawPointer(&painter);

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
   p1.setCapStyle(Qt::FlatCap);



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

         //设置画笔
          p1.setWidth(w1);
         painter->setPen( p1);

        //第一圈
        painter->drawArc( rect1,startAng*16 , -alen*16);

       p1.setWidth(w2);
       painter->setPen( p1);
        //第二圈
        painter->drawArc( rect2,startAng*16 , -alen*16);
    }

}

void WarnWidget::drawProgress(QPainter *painter)
{
    //画圆弧
    QRect  rect1(-r1,-r1, 2*r1,2*r1);
    QRect  rect2(-r2,-r2, 2*r2,2*r2);


   QPen p1;
   p1.setCapStyle(Qt::FlatCap);


    //我们知道 0~180度 对应  min~max
    //  v-min /(max- min) = ang/(180-0)

    //偏移角度
    double an =  (m_value-min ) / (max-min)*180;
    //角度值
    double angle = 180-an;


    // 180度 正值从0度开始逆时针方向180度 ，
    //偏移度数-180 表示 顺时针偏移180度
    //度数需要*16

    int BLANK =2;//空隙
    for(int i=0;i<12;++i) //分为12段 ，180度/12 = 15度
    {
         //确定等级色
        if(i<2)   curColor = Qt::green;//绿色
        else if( i< 7) curColor = QColor(255,112,0); //橙色
        else curColor = Qt::red; //红色

        p1.setColor( curColor);

        //这一段的起始角度和结束角度
        int  startAng = 180 -i*15;
        int  endAng = startAng -15;

        int  alen =  15- BLANK; //减去空隙
        if(i == 11) alen = 15; //最后一个偏移直接为15

        //从左往右看
        if(angle < endAng)
        {
            //设置画笔
            p1.setWidth(w1);
            painter->setPen( p1);

            //说明前一块可以全部绘制
               painter->drawArc( rect1,startAng*16 , -alen*16);


               //设置画笔
               p1.setWidth(w2);
               painter->setPen( p1);
               //第二圈
               painter->drawArc( rect2,startAng*16 , -alen*16);

        }

        //说明指针在 这一块的内部
        if( angle <= startAng && angle >= endAng)
        {
            //设置画笔
            p1.setWidth(w1);
            painter->setPen( p1);

            //至绘制开始到 指针指向位置为结束
             painter->drawArc( rect1,startAng*16 , -  (startAng-angle  )*16);

             //设置画笔
             p1.setWidth(w2);
             painter->setPen( p1);

             //第二圈
             painter->drawArc( rect2,startAng*16 , -  (startAng-angle  )*16);


             //后面不需要再填充色了，因为指针只指到这里
             break;
        }


    }
}

void WarnWidget::drawHalf(QPainter *painter)
{

    //画第三圈
    QRect rect3(-r3,-r3, 2*r3, 2*r3);

    painter->setPen(QPen(Qt::white,1));

    painter->setBrush(QBrush(  curColor ));

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

void WarnWidget::drawPointer(QPainter *painter)
{
    //先保存场景设置
       painter->save();

       //我们知道 0~180度 对应  min~max
       //  v-min /(max- min) = ang/(180-0)

       double angle =  (m_value-min ) / (max-min)*180;

       //顺时针旋转
       painter->rotate(angle);


       //设置 笔、画刷
        QPen pen(Qt::white,1);
        painter->setPen(pen);

        painter->setBrush( Qt::gray);

        //画多边形
        QPolygon poly;
        poly.setPoints(4 ,  -r3, 0,    0,-6,   6,0,   0,6);
        painter->drawPolygon(poly);


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

void WarnWidget::setValue(double v)
{
    //合法校验
    if( v > max) v= max;
    if( v < min) v= min;

    m_value = v;

    //强制刷新
    repaint();
}

double WarnWidget::getValue()
{
    return m_value;
}

WarnWidget::~WarnWidget()
{
    delete ui;
}
