#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QStyleOption>
#include<QPainter>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

    //方式二
     virtual void paintEvent(QPaintEvent *event)
     {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
     }

signals:

};

#endif // MYWIDGET_H
