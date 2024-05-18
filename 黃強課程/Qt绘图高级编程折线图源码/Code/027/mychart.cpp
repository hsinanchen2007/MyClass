#include "mychart.h"
#include "ui_mychart.h"
#include<QPainter>

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

}
