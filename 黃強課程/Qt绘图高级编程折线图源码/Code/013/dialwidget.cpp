#include "dialwidget.h"
#include "ui_dialwidget.h"
#include<QPainter>

DialWidget::DialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialWidget)
{
    ui->setupUi(this);
}

 void DialWidget::paintEvent(QPaintEvent *event)
 {
     //定义画家类
     QPainter painter(this);

     //将整个仪表盘背景绘制为红色
     painter.fillRect(0,0, width(),height(),QBrush(Qt::red));

 }


DialWidget::~DialWidget()
{
    delete ui;
}
