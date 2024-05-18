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


    //创建日期时间刻度类对象
    QSharedPointer<QCPAxisTickerDateTime>
            dateTimeTicker (new  QCPAxisTickerDateTime);

    //为x轴设置刻度对象QCPAxis
    customPlot->xAxis->setTicker(dateTimeTicker);

   // 设置日期的显示格式
    dateTimeTicker->
            setDateTimeFormat("yyyy-MM-dd hh:mm:ss");

  //设置轴的范围
    QDateTime min( QDate(2023,1,1) ,QTime(0,0,0));
    QDateTime max( QDate(2023,12,30) ,QTime(23,59,59));

    //传入1970年8点至今的一个秒数
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
    QCPGraph  *graph = customPlot->addGraph();

    //设置标题
    graph->setName("时间轴折线图");

    //添加一个折线 数据
        QDateTime  t1= QDateTime(QDate(2023,2,2) ,QTime(3,4,5));
        QDateTime  t2= QDateTime(QDate(2023,6,1) ,QTime(6,7,8));
        QDateTime  t3= QDateTime(QDate(2023,8,2) ,QTime(9,1,2));

        //传入秒数
        graph->addData(t1.toSecsSinceEpoch(),1200);
        graph->addData(t2.toSecsSinceEpoch(),1800);
        graph->addData(t3.toSecsSinceEpoch(),1500);

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

