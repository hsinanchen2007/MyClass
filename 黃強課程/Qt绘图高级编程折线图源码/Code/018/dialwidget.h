#ifndef DIALWIDGET_H
#define DIALWIDGET_H

#include <QWidget>

namespace Ui {
class DialWidget;
}

class DialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DialWidget(QWidget *parent = nullptr);
    ~DialWidget();

     void paintEvent(QPaintEvent *event);

     //公共方法
     void  setValue(int v);
     int    getValue( );

 private:
     //绘制的细节，私有
      void  drawBg(QPainter*painter);
      void  drawScale(QPainter*painter);
      void  drawScaleNum(QPainter*painter);
       void drawPointer(QPainter*painter);
private:
    Ui::DialWidget *ui;

    //仪表盘的半径
    int radius ;

    //当前的值
    int value=0;
};

#endif // DIALWIDGET_H
