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

private:
   //内部绘制细节
  void  drawBg(QPainter *painter);


private:
    Ui::WarnWidget *ui;

   //圆的半径
    int r1=0;
    int r2=0;
    int r3=0;
     //画笔的粗细
    int w1=0;
    int w2=0;
};

#endif // WARNWIDGET_H
