#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建图表对象
    QChart *chart = new QChart;
    //设置标题
    chart->setTitle("时间轴的折线图");

    //定义图表显示的视图
    QChartView  * chartView=  new  QChartView(this);

    //设置视图的大小位置
    chartView->setGeometry(100,100,900,600);

    //设置要显示的QChart对象
    chartView->setChart(chart);

    //x轴不用数值轴QValueAxis，而是时间轴
     QDateTimeAxis * axisX = new QDateTimeAxis;
     axisX->setTitleText("时间");


     //设置时间轴的范围
     QDateTime  min (QDate(2023,1,1) ,QTime(0,0,0));
     QDateTime  max (QDate(2023,12,30) ,QTime(23,59,59));
     axisX->setRange(min,max);

     //设置时间显示的格式
     axisX->setFormat("MM月dd日 hh:mm:ss");

     //设置轴的刻度数量
     axisX->setTickCount(6);

     //设置轴刻度值的角度
     axisX->setLabelsAngle(45);

     //添加x轴
     chart->addAxis(axisX ,Qt::AlignBottom);


     //创建数值y轴
     QValueAxis  *axisY = new QValueAxis;
     axisY->setRange(1000,2000);
     axisY->setTitleText("y轴");
     //添加y轴
     chart->addAxis(axisY ,Qt::AlignLeft);


        //折线系列
        QLineSeries *series = new QLineSeries();

         QDateTime  t1= QDateTime(QDate(2023,2,2) ,QTime(3,4,5));
         QDateTime  t2= QDateTime(QDate(2023,6,1) ,QTime(6,7,8));
         QDateTime  t3= QDateTime(QDate(2023,8,2) ,QTime(9,10,11));

         //加入3个点，时间转为毫秒
         // toMSecsSinceEpoch 获取该时间从1970 年的一个毫秒数
          series->append(t1.toMSecsSinceEpoch() ,1200);
          series->append(t2.toMSecsSinceEpoch(), 1800);
          series->append(t3.toMSecsSinceEpoch(), 1500);

          //加入系列到图表
          chart->addSeries(series);

          //关联系列与x轴，y轴
          series->attachAxis(axisX);
          series->attachAxis(axisY);


}

MainWindow::~MainWindow()
{
    delete ui;
}

