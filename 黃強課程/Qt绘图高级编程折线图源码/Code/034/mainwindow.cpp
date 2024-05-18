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
    chart->setTitle("动态时间轴折线图");


    //定义图表显示的视图
    QChartView  * chartView=  new  QChartView(this);

    //设置视图的大小位置
    chartView->setGeometry(100,100,900,600);


    //反锯齿渲染
    chartView->setRenderHint(QPainter::Antialiasing);

    //设置要显示的QChart对象
    chartView->setChart(chart);

    //x轴不用数值轴QValueAxis，而是时间轴
     axisX = new QDateTimeAxis;
     axisX->setTitleText("时间");


     //设置时间轴的范围,10s的范围
     QDateTime  min  (QDateTime::currentDateTime());
     QDateTime  max ( min.addSecs(10));
     axisX->setRange(min,max);

     //设置时间显示的格式
     axisX->setFormat("hh:mm:ss");

     //设置轴的刻度数量
     //axisX->setTickCount(6);

     //设置轴刻度值的角度
     //axisX->setLabelsAngle(45);

     //添加x轴
     chart->addAxis(axisX ,Qt::AlignBottom);


     //创建数值y轴
     QValueAxis  *axisY = new QValueAxis;
     axisY->setRange(1000,2000);
     axisY->setTitleText("y轴");
     //添加y轴
     chart->addAxis(axisY ,Qt::AlignLeft);


        //折线系列
        series = new QLineSeries();

        //设置系列的颜色
        series->setColor(Qt::red);

          //加入系列到图表
          chart->addSeries(series);

          //关联系列与x轴，y轴
          series->attachAxis(axisX);
          series->attachAxis(axisY);

          //10ms触发一次
          startTimer(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    //x值是日期的毫秒数
    qint64 x = QDateTime::currentMSecsSinceEpoch();
    //y值是随机数
    qreal y = QRandomGenerator::global()->bounded(1000,2000);

    series->append(x,y);

    //获取x轴的最大值
    QDateTime  max = axisX->max();
    QDateTime  min = axisX->min();

    if( x > max.toMSecsSinceEpoch() )
    {
        QDateTime  newMax= QDateTime::fromMSecsSinceEpoch(x);
        //保证始终只展示10秒的一段
        QDateTime  newMin= newMax.addSecs(-10);
        //设置新的范围
        axisX->setRange( newMin , newMax );

        //防止点数越来越多，内存最后耗尽
        //对于不展示的点，需要删除掉
        series->remove(0);//删除第一个点
    }

    qDebug()<<"折线图的点数"<<series->points().size();

}

