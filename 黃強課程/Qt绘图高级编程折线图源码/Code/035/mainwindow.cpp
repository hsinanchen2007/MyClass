#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义图表对象
    QChart * chart = new QChart;
    chart->setTitle("饼图");

    //定义图表视图
    QChartView  *chartView = new QChartView(this);
    chartView->setGeometry(100,100,900,600);
    //抗锯齿
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setChart(chart);

    //定义饼图系列
    QPieSeries *series = new QPieSeries;

    //添加数据

    //创建一个切片
    QPieSlice  *ps1= new QPieSlice("C语言", 40);
    series->append(ps1);

    QPieSlice  *ps2= new QPieSlice("C++", 30);
    series->append(ps2);

    series->append("JAVA", 20);

    series->append("C#", 10);

    //设置中间圆孔大小
    series->setHoleSize(0.2);


    //获取饼图的切片
   QPieSlice * s0=  series->slices().at(0);
   s0->setPen(QPen(Qt::red ,3));
   s0->setBrush(QBrush(Qt::green));

   QPieSlice * s1=  series->slices().at(1);
   s1->setBrush(QBrush(Qt::red));

   qreal per= s1->percentage() *100;
   s1->setLabel("C++的占比"+ QString::number(per)+"%");
   s1->setLabelVisible(true);

    //添加系列
    chart->addSeries(series);


    //添加饼图系列的信号
    connect( series , &QPieSeries::clicked, [](QPieSlice *slice)
    {
        //让切片和饼图分离
        slice->setExploded(true);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

