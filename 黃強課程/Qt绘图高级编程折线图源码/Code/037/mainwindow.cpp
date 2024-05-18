#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义图表对象
    QChart * chart = new QChart;
    chart->setTitle("面积图");

    //定义图表视图
    QChartView  *chartView = new QChartView(this);
    chartView->setGeometry(100,100,900,600);
    //抗锯齿
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setChart(chart);

    //创建面积系列
    QAreaSeries *series = new QAreaSeries();
    //设置折线点可见
    series->setPointsVisible(true);
    //设置点坐标可见
    series->setPointLabelsVisible(true);

    //设置点的颜色
    series->setPointLabelsColor(Qt::red);

    //设置背景色
    series->setBrush(Qt::green);
    //图例上显示的名称
    series->setName("干旱面积");

    //下方折线系列
    QLineSeries * lowerSeries= new QLineSeries;
    lowerSeries->append(25,  80);
    lowerSeries->append(90,  80);

    //上方折线系列
    QLineSeries * upperSeries= new QLineSeries;
    upperSeries->append(10,130);
    upperSeries->append(50,180);
    upperSeries->append(80,120);

    //设置围成面积的两条折线
    series->setLowerSeries(lowerSeries);
    series->setUpperSeries(upperSeries);


    //把面积系列加入图表
    chart->addSeries(series);

  //创建默认坐标轴，一定要在addSeries 之后
  //它是根据你的系列来确定坐标轴的
  //也可以不创建的默认，自己手动创建QValueAxis
    chart->createDefaultAxes();

    //获取默认的两条轴，并且重新设置范围
    QAbstractAxis *axisX= chart->axes( Qt::Horizontal).first();
    QAbstractAxis *axisY= chart->axes( Qt::Vertical).first();

    axisX->setRange(0,100);
    axisY->setRange(0,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

