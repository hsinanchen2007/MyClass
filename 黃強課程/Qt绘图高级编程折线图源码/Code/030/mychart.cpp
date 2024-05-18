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

    //画刻度
    drawKedu(&painter);

    //画折线
    drawLines(&painter);
}

void MyChart::SetAxisText(QString x, QString y)
{
    this->xTitle = x;
    this->yTitle = y;

    //重绘
    repaint();
}

void MyChart::SetRange(double xMin, double xMax, double yMin, double yMax)
{
    this->xMin = xMin;
    this->xMax = xMax;

    this->yMin = yMin;
    this->yMax = yMax;

    //重绘
    repaint();
}

void MyChart::AppendPoint(QPointF p)
{
    points.append(p);

    //重绘
    repaint();
}

void MyChart::drawAxis(QPainter *painter)
{

    //y轴
   drawArrorLine( QLine(rect.bottomLeft() ,
                        QPoint( rect.topLeft().x() ,  rect.topLeft().y()-30 )) , painter );
   painter->drawText( rect.topLeft().x() +10,
                      rect.topLeft().y() - 20, yTitle );

   //x轴
   drawArrorLine( QLine(rect.bottomLeft() ,
                        QPoint( rect.bottomRight().x()  +30 ,   rect.bottomRight().y() ) ) , painter);
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

void MyChart::drawKedu(QPainter *painter)
{

    double X = (xMax - xMin) /5;
     //绘制x轴的刻度
    for (int i=0; i<=5 ; i++)
    {
        int x = rect.left() +  i*  rect.width()/5 ;
        int y = rect.bottom();
        painter->drawLine( x,  y ,  x,  y + 5 );

        double kd = xMin+  i *X;
        QString strKD = QString::number( kd , 'f' , 2);

        //文本居中可以使用QFontMetrics
        painter->drawText( x, y+20 , strKD );
    }



    double Y = (yMax - yMin) /5;
     //绘制x轴的刻度
    for (int i=0; i<=5 ; i++)
    {
        int x = rect.left() ;
        int y = rect.bottom() -  i*  rect.height()/5 ;
        painter->drawLine( x-5 ,  y ,  x,  y  );

        double kd = yMin+  i *Y;
        QString strKD = QString::number( kd , 'f' , 0);

        //文本居中可以使用QFontMetrics
        painter->drawText( x - 50, y  , strKD );
    }
}

void MyChart::drawLines(QPainter *painter)
{


    //最好可以优化一下，这样drawPolyline画出来就比较好
    //points 按x轴坐标排序，避免客户加入的时候顺序不对

    //真实坐标点的集合
    QVector<QPointF >  tmps;

    //将点等比例转换一下，然后转换为屏幕点的坐标
    foreach(const QPointF & p , points)
    {
                int x   = rect.width() *1.0f /(xMax-xMin)  *(  p.x() - xMin)    ;
                int y =  rect.height()*1.0f  /(yMax-yMin)  *(  p.y() - yMin)   ;
                //将图表的点转为真实绘制的坐标
                int x1 =   rect.left() +  x   ;
                int y1 =   ( height() -  y )  -  ( height() - rect.bottom() )  ;

                tmps.push_back(QPoint(x1,y1));

    }

    //绘制折线
    painter->drawPolyline(tmps.data() , tmps.size());

    //设置画刷
    painter->setBrush(Qt::red);

    //每个点标注一个圆圈
      foreach(const QPointF & p , tmps) {
        painter->drawEllipse( p.x()-3 , p.y()-3 , 6, 6  );
    }

}
