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

      graph->setPen(QPen(Qt::blue,8));
      graph->setName("折线图1"); //图例显示的名称
      graph->addData(1,1200);
      graph->addData(30,1200);
      graph->addData(40,1500);
      graph->addData(70,1800);
      graph->addData(100,1400);
      graph->addData(30,1700);


      //点具有三个值，分别是排序的t， x ，y

      QCPCurve  *curve = new QCPCurve
              (customPlot->xAxis ,customPlot->yAxis);

       curve->setPen(QPen(Qt::red,4));
       curve->setName("曲线图1"); //图例显示的名称
       curve->addData(1,1,1200);
       curve->addData(2,30,1200);
       curve->addData(3, 40,1500);
       curve->addData(4, 70,1800);
       curve->addData(5,100,1400);
       curve->addData(6, 30,1700);




}

MainWindow::~MainWindow()
{
    delete ui;
}

