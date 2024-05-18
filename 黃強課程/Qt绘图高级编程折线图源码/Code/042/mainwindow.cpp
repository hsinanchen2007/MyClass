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


    //获取图表的x轴QCPAxis类，并设置范围与标题
    customPlot->xAxis->setRange(0,100);
     customPlot->xAxis->setLabel("x轴");

     //获取图表的y轴QCPAxis类，并设置范围与标题
     customPlot->yAxis->setRange(1000,2000);
     customPlot->yAxis->setLabel("y轴");

     //显示图例QCPLegend类
     customPlot->legend->setVisible(true);


     //添加一个折线图(自动添加到 customPlot 里面)
     QCPGraph  *graph = new QCPGraph
             (customPlot->xAxis ,customPlot->yAxis);

     //获取索引为0的折线图对象
     QCPGraph * g0 = customPlot->graph(0);
     bool b = ( graph == g0);
     qDebug()<<"比较："<<b;

      graph->setPen(QPen(Qt::blue));
      graph->setName("折线图1"); //图例显示的名称
      graph->addData(1,1200);
      graph->addData(100,1400);
      graph->addData(30,1700);
      graph->addData(40,1500);
      graph->addData(70,1800);

    //测试QCPAxis类的方法

      //设置坐标轴 线的画笔
      customPlot->xAxis->setBasePen(QPen(Qt::yellow,2));
      //设置刻度 线的画笔
      customPlot->xAxis->setTickPen(QPen(Qt::green,4));
      //设置子刻度 线的画笔
      customPlot->xAxis->setSubTickPen(QPen(Qt::red,2));
      //设置轴 标题的颜色
      customPlot->xAxis->setLabelColor( Qt::blue);
      //设置 刻度值文本的颜色
      customPlot->xAxis->setTickLabelColor( Qt::darkRed);

      //设置 坐标轴起点的形状
      customPlot->xAxis->setLowerEnding(
                  QCPLineEnding::esDisc); //圆点
      //设置 坐标轴终点的形状
      customPlot->xAxis->setUpperEnding(
                  QCPLineEnding::esSpikeArrow); //箭头

      //设置主刻度的个数(受显示策略的影响)
      customPlot->xAxis->ticker()->setTickCount(3);

      //设置刻度的显示策略
      customPlot->xAxis->ticker()
 ->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);

      //设置刻度文本的角度
      customPlot->xAxis->setTickLabelRotation(45);

      //设置网格线
      QPen pen1(Qt::red,1, Qt::DotLine); //点线
      customPlot->xAxis->grid()->setPen(pen1);

      //设置子网格线
      QPen pen2(Qt::gray,1, Qt::SolidLine);//实线
      customPlot->xAxis->grid()->setSubGridPen(pen2);

      //显示 主、子网格线
      customPlot->xAxis->grid()->setVisible(true);
      customPlot->xAxis->grid()->setSubGridVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

