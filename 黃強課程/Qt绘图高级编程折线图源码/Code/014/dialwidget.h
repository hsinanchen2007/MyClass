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

 private:
     //绘制的细节，私有
      void drawBg(QPainter*painter);

private:
    Ui::DialWidget *ui;

    //仪表盘的半径
    int radius ;
};

#endif // DIALWIDGET_H
