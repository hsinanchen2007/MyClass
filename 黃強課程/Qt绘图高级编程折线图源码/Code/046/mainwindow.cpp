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


     //定义 横轴的文本刻度
    QVector<double> ticks;
    QVector<QString> labels;
    ticks<<1<<2<<3;
    labels<<"2022年"<<"2023年"<<"2024年";

    //文本轴刻度对象指针
    QSharedPointer<QCPAxisTickerText> tickerText(
            new QCPAxisTickerText());
    tickerText->setTicks(ticks,  labels);

   //为x轴设置 文本刻度对象
    customPlot->xAxis->setTicker( tickerText);
    customPlot->xAxis->setLabel("年份");

    //为y轴设置范围
     customPlot->yAxis->setRange(1000,2000);
     customPlot->yAxis->setLabel("开发者数量");

     //设置图例
     customPlot->legend->setVisible(true);

     //添加柱状图
     QCPBars *bar1 = new QCPBars(customPlot->xAxis,
                                 customPlot->yAxis);

     bar1->setName("C语言");
     //填充色
     bar1->setBrush(Qt::red);
     //设置宽度
     bar1->setWidthType(QCPBars::wtAbsolute);
     bar1->setWidth(25);

     //为柱状图添加数据
     bar1->addData(1, 1200);
     bar1->addData(2, 1800);
     bar1->addData(3, 1600);


     //添加柱状图
     QCPBars *bar2 = new QCPBars(customPlot->xAxis,
                                 customPlot->yAxis);

     bar2->setName("C++");
     //填充色
     bar2->setBrush(Qt::green);

     //设置宽度
     bar2->setWidthType(QCPBars::wtAbsolute);
     bar2->setWidth(25);

     //为柱状图添加数据
     QVector<double> keys={1,2,3};
     QVector<double> vals={1800,1500,1700};
     bar2->addData(keys, vals);


     //分组
     QCPBarsGroup  *group = new QCPBarsGroup(customPlot);
     group->append(bar1);
     group->append(bar2);
     group->setSpacingType(QCPBarsGroup::stAbsolute);
     group->setSpacing(5);

}

MainWindow::~MainWindow()
{
    delete ui;
}

