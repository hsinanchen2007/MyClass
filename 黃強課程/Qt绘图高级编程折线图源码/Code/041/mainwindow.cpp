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


      //再添加一个折线图
     QCPGraph  *graph2  =customPlot->addGraph();

     //第二个索引为1
         bool  b2  = ( graph2= customPlot->graph(1));
        qDebug()<<"比较2："<<b2;
         graph2->setPen(QPen(Qt::red));
         graph2->setName("折线图2");
         graph2->addData(1,1000);
         graph2->addData(100,1200);
         graph2->addData(30,1500);
         graph2->addData(40,1300);
         graph2->addData(70,1600);

}

MainWindow::~MainWindow()
{
    delete ui;
}

