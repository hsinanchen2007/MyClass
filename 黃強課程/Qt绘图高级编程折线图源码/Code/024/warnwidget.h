#ifndef WARNWIDGET_H
#define WARNWIDGET_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class WarnWidget;
}

class WarnWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WarnWidget(QWidget *parent = nullptr);
    ~WarnWidget();

    void paintEvent(QPaintEvent *event);


    //设置三个圆的半径，w1是第一个圆弧的画笔粗细，
    //w2是第二个圆弧画笔的粗细
    void  setRadius(int r1,int w1, int r2,int w2, int r3);

    //设置仪表值的范围
    void  setRange(double min, double max);

    //设置刻度的精度,小数点后保留n位
    void setPrecise(int n);

    //设置当前指针值
    void setValue(double v);
    double getValue();

private:
   //内部绘制细节
  void  drawBg(QPainter *painter);
  void  drawHalf(QPainter *painter);
  void  drawKedu(QPainter *painter);
  void  drawPointer(QPainter *painter);


private:
    Ui::WarnWidget *ui;

   //圆的半径
    int r1=0;
    int r2=0;
    int r3=0;
     //画笔的粗细
    int w1=0;
    int w2=0;

    //仪表的范围
    double min=0;
    double max=100;

    //精度
    int precise=0;

    //当前指针值
    double m_value=0;
};

#endif // WARNWIDGET_H
