#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义图表对象
    QChart * chart = new QChart;
    chart->setTitle("测试10w个点的性能");

    //定义图表视图
    QChartView  *chartView = new QChartView(this);
    chartView->setGeometry(100,100,900,600);
    //抗锯齿
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setChart(chart);

   //测试折线系列
    QLineSeries *series = new QLineSeries;


    //加入系列到图表对象
    chart->addSeries(series);

    //创建默认x，y轴 (一定要在 addSeries 后面调用)
    chart->createDefaultAxes();


    //设置两个轴的范围
    chart->axes(Qt::Horizontal).first()->setRange(0,100000);
    chart->axes(Qt::Vertical).first()->setRange(1000,2000);


    //开启时间计时
    QElapsedTimer timer;
    timer.start();//开始

    //添加10w个点
    for(int i=0;i< 100000;++i)
    {
            series->append(i,1500 );
    }


    qDebug()<<"点个数"<< series->points().size()
           <<"   耗时"<<timer.elapsed() <<"ms";

}

MainWindow::~MainWindow()
{
    delete ui;
}

