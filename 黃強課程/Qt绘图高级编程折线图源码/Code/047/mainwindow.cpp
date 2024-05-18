#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建QCustomPlot的对象
    QCustomPlot  *customPlot = new QCustomPlot(this);

    //设置图表窗口的大小
    customPlot->setGeometry(100,100,900,600);

    //显示图例
    customPlot->legend->setVisible(true);


     //定义 横轴的文本刻度
    QVector<double> ticks;
    QVector<QString> labels;
    ticks<<1<<2<<3;
    labels<<"05-20"<<"05-21"<<"05-22";

    //文本轴刻度对象指针
    QSharedPointer<QCPAxisTickerText> tickerText(
            new QCPAxisTickerText());
    tickerText->setTicks(ticks,  labels);

   //为x轴设置 文本刻度对象
    customPlot->xAxis->setTicker( tickerText);
    customPlot->xAxis->setLabel("日期");

    //为y轴设置范围
     customPlot->yAxis->setRange(0,3000);
     customPlot->yAxis->setLabel("价格");

   //创建 k线图
     QCPFinancial* financial = new
     QCPFinancial(customPlot->xAxis , customPlot->yAxis);

     //设置图例的文本
     financial->setName("日K");

     // key 键,   open 开盘价,   high 最高价,   low最低价,   close收盘价
     financial->addData(1, 1000,1500, 800,1200);
     financial->addData(2, 600,2500,300, 1800);
     financial->addData(3, 2300,1900, 1000,1800);

   //设置阳线(红色)、阴线（绿色）的颜色
     financial->setBrushPositive(Qt::red);
     financial->setBrushNegative(Qt::green);


}

MainWindow::~MainWindow()
{
    delete ui;
}

