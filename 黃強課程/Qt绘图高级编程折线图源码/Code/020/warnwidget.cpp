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

    //绘制控件背景
    painter.fillRect(QRect(0,0, width(),height()),
                     QBrush(Qt::red) );
}



WarnWidget::~WarnWidget()
{
    delete ui;
}
