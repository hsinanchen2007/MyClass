#ifndef MYCHART_H
#define MYCHART_H

#include <QWidget>

namespace Ui {
class MyChart;
}

class MyChart : public QWidget
{
    Q_OBJECT

public:
    explicit MyChart(QWidget *parent = nullptr);
    ~MyChart();

    virtual void paintEvent(QPaintEvent *event);

    //设置x轴，y轴的文本
    void SetAxisText( QString x ,QString y);
    void SetRange(double   xMin , double xMax ,double  yMin , double yMax );
    void AppendPoint(QPointF  p);

 private:
    void drawAxis(QPainter *painter);
    void drawArrorLine(QLine line, QPainter *painter);
    void drawKedu(QPainter *painter);
    void drawLines(QPainter *painter);


private:
    Ui::MyChart *ui;

    //坐标轴的矩形区域
    QRect  rect;

    //轴显示的文本
    QString xTitle;
    QString yTitle;

    //x y轴范围
     double xMin ,xMax;
     double yMin ,yMax;

     //图表点的集合
     QVector<QPointF> points;
};

#endif // MYCHART_H
