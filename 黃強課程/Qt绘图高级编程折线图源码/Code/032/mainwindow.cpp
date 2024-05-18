#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建图表对象
    QChart *chart = new QChart();
    //设置图表标题
    chart->setTitle("折线与曲线图表");

    //隐藏图例
    //chart->legend()->hide();


    //显示图表的视图
    QChartView *chartView = new QChartView(this);
    //设置视图的位置大小
    chartView->setGeometry(100,100, 900,600);

    //设置显示的图表对象
    chartView->setChart(chart);

    //为图表设置 数值轴
    QValueAxis  *axisX = new QValueAxis;
    //设置轴的范围
    axisX->setRange(0,100 );
    //设置轴的标题
    axisX->setTitleText("X轴");
    //设置轴标题的颜色 淡红色
    axisX->setTitleBrush(Qt::magenta);
    //设置网格线是否显示
    axisX->setGridLineVisible(true);
    //设置网格线的 颜色 黄色
    axisX->setGridLineColor(Qt::yellow);

    //设置刻度的精度,保留3位小数
    axisX->setLabelFormat("%.3f");

    //设置刻度的倾斜角度
    axisX->setLabelsAngle(45);

    //设置刻度值文本的颜色
    axisX->setLabelsColor(Qt::darkGray);

    //设置刻度的数量
    axisX->setTickCount(10);

    //设置子刻度的数量
    axisX->setMinorTickCount(3);

    //设置轴的颜色和粗细
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    axisX->setLinePen(pen);


    //把x轴添加到QChart里面
  chart->addAxis(axisX, Qt::AlignBottom);

  /*
   //测试添加两个x轴
  {
      QValueAxis  *axisX = new QValueAxis;
      axisX->setRange(0,100 );
      axisX->setTitleText("X222轴");

      chart->addAxis(axisX, Qt::AlignTop);
  }*/


  //y轴

  QValueAxis  *axisY = new QValueAxis;
  axisY->setRange(1000,2000 );
  axisY->setTitleText("Y轴");
  axisY->setGridLineColor(Qt::blue);
  //把y轴添加到QChart里面
  chart->addAxis(axisY, Qt::AlignLeft);


  //画折线系列
  QLineSeries * series= new QLineSeries;
  //设置系列的颜色
  series->setColor(Qt::green);
  //设置图例显示的名称
  series->setName("折线");

  //加入点
   series->append(1,1200);
   series->append(30,1700);
   series->append(40,1500);
   series->append(70,1800);
   series->append(100,1400);

  //把系列 显示在QChart对象中
   chart->addSeries( series);

   //注意细节，需要将系列和轴关联
   //系列才能正确显示
   series->attachAxis( axisX);
   series->attachAxis( axisY);



   //画曲线系列
   QSplineSeries * series2= new QSplineSeries;
   //设置系列的颜色
   series2->setColor(Qt::red);
   //设置图例显示的名称
   series2->setName("曲线");

   //加入点
    series2->append(1,1200);
    series2->append(30,1700);
    series2->append(40,1500);
    series2->append(70,1800);
    series2->append(100,1400);

   //把系列 显示在QChart对象中
    chart->addSeries( series2);

    //注意细节，需要将系列和轴关联
    //系列才能正确显示
    series2->attachAxis( axisX);
    series2->attachAxis( axisY);




}

MainWindow::~MainWindow()
{
    delete ui;
}

