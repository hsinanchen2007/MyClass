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

 private:
    void drawAxis(QPainter *painter);
    void drawArrorLine(QLine line, QPainter *painter);
private:
    Ui::MyChart *ui;

    //坐标轴的矩形区域
    QRect  rect;

    //轴显示的文本
    QString xTitle;
    QString yTitle;
};

#endif // MYCHART_H
