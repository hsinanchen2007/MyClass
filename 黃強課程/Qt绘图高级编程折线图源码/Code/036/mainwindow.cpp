#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义图表对象
    QChart * chart = new QChart;
    chart->setTitle("柱状图");

    //定义图表视图
    QChartView  *chartView = new QChartView(this);
    chartView->setGeometry(100,100,900,600);
    //抗锯齿
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setChart(chart);


    //柱状图系列
    QBarSeries  *series = new QBarSeries;

    //设置条状图标签可见
    series->setLabelsVisible(true);

    //QBarSet 一种数据集合
    QBarSet * bs1= new QBarSet("C语言");
    bs1->append(20);
    bs1->append(30);
    bs1->append(40);

    //设置条形图的样式
    bs1->setBrush(Qt::red);
    bs1->setLabelColor(Qt::cyan);
    bs1->setBorderColor(Qt::blue);
    bs1->setPen(QPen(Qt::blue,4));
    bs1->setLabel("标签文本");

    //QBarSet 一种数据集合
    QBarSet * bs2= new QBarSet("C++");
    bs2->append(100);
    bs2->append(120);
    bs2->append(150);


    //QBarSet 一种数据集合
    QBarSet * bs3= new QBarSet("JAVA");
    bs3->append(60);
    bs3->append(70);
    bs3->append(80);


    //把数据集合添加到系列
    series->append(bs1);
    series->append(bs2);
    series->append(bs3);

    //把系列加到chart对象中
    chart->addSeries(series);

    //添加坐标轴

    //x轴
    QBarCategoryAxis  *axisX = new QBarCategoryAxis();

    QStringList  list;
    list<<"2021年"<<"2022年"<<"2023年";
    axisX->append(list);

    //加入x轴
    chart->addAxis(axisX , Qt::AlignBottom);



    //y轴
    QValueAxis  *axisY = new QValueAxis();
    axisY->setRange(0,200);

    //加入y轴
    chart->addAxis(axisY , Qt::AlignLeft);


    //细节，系列需要关联轴
    series->attachAxis(axisY);

}

MainWindow::~MainWindow()
{
    delete ui;
}

