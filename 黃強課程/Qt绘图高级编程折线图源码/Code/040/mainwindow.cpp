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

    //设置x轴y轴的范围
    customPlot->xAxis->setRange(0,100000);
    customPlot->yAxis->setRange(1000,2000);

    //添加折线图
    QCPGraph *graph = customPlot->addGraph();

    //测试用时
    QElapsedTimer timer;
    timer.start();//开始计时

    //加入10w个点
    for (int i=0;i<100000;++i) {
        graph->addData(i , 1500);
    }


    qDebug()<<"点的个数"<<graph->dataCount()
           <<"   耗时"<<timer.elapsed()<<"ms";

}

MainWindow::~MainWindow()
{
    delete ui;
}

