#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建QCustomPlot的对象
    customPlot = new QCustomPlot(this);

    //设置图表窗口的大小
    customPlot->setGeometry(100,100,900,600);


    //创建日期时间刻度类对象
    QSharedPointer<QCPAxisTickerDateTime>
            dateTimeTicker (new  QCPAxisTickerDateTime);

    //为x轴设置刻度对象QCPAxis
    customPlot->xAxis->setTicker(dateTimeTicker);

   // 设置日期的显示格式
    dateTimeTicker->
            setDateTimeFormat("yyyy-MM-dd hh:mm:ss");

  //设置轴的范围
    QDateTime min = QDateTime::currentDateTime();
    QDateTime max = min.addSecs(10);

    //当前时间开始往后10秒
    customPlot->xAxis->
            setRange( min.toSecsSinceEpoch() ,max.toSecsSinceEpoch());


    //设置轴的标题
    customPlot->xAxis->setLabel("时间轴");

    //设置主刻度的数量
    customPlot->xAxis->ticker()->setTickCount(12);
    //设置刻度文本的角度
    customPlot->xAxis->setTickLabelRotation(45);


    //设置y轴
    customPlot->yAxis->setRange(1000,2000);
    //设置y轴的标题
    customPlot->yAxis->setLabel("y轴");


    //添加一个折线图
    graph = customPlot->addGraph();

    //设置标题
    graph->setName("动态时间轴折线图");

      //设置图表颜色
     graph->setPen(QPen(Qt::red));

        //网格线QCPGrid
       customPlot->xAxis->grid()->setPen(QPen(Qt::red,1,Qt::DotLine));//实线

       // 子网格线(对应子刻度)画笔
       customPlot->xAxis->grid()->setSubGridPen(QPen(Qt::gray, 1, Qt::SolidLine));

       // 显示子网格线
       customPlot->xAxis->grid()->setSubGridVisible(true);


        // 显示图例QCPLegend
        customPlot->legend->setVisible(true);

        //开启定时器，10ms一次
        startTimer(10);

}


void MainWindow::timerEvent(QTimerEvent *event)
{
    //毫秒数（为了提高精度）
    double   x = QDateTime::currentMSecsSinceEpoch();
    x = x/1000;//秒数

    //随机值
    double  y = QRandomGenerator::global()
            ->bounded(1000,2000);

    //单位是秒数
    graph->addData(x, y);


    //获取x轴范围最大值
    double max = customPlot->xAxis->range().upper;

    if( x > max )
    {
        //显示的段为10秒
        customPlot->xAxis->setRange( x - 10 ,x);

        //删除已经不可见的点
        graph->data()->removeBefore( x-10);
    }

    //刷新一下
    customPlot->replot(QCustomPlot::rpQueuedReplot);


    //打印点数
    qDebug()<<"点数"<<graph->data().data()->size();
}


MainWindow::~MainWindow()
{
    delete ui;
}

