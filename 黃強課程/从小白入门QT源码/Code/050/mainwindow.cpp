#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QHBoxLayout>
#include<QDebug>
#include"mybutton.h"


//打印小部件的各个size属性
void  printSize(QWidget * w)
{
    qDebug("size                              %d    %d" ,w->size().width(), w->size().height());
    qDebug("sizeHint                        %d    %d" ,w->sizeHint().width(), w->sizeHint().height());
    qDebug("minimumSizeHint        %d    %d" ,w->minimumSizeHint().width(), w->minimumSizeHint().height());
    qDebug("minimumSize               %d    %d" ,w->minimumSize().width(), w->minimumSize().height());
    qDebug("maximumSize               %d    %d" ,w->maximumSize().width(), w->maximumSize().height());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QPushButton * btn = new QPushButton();
    MyButton * btn = new MyButton();
    btn->setText("111111111111111");

    //按钮不在布局中的时候，以下两个函数有效
    btn->setGeometry(100,100,300,300);
    btn->resize(100,100);


    QHBoxLayout * layout=new  QHBoxLayout(ui->centralWidget);
    //按钮一旦加入布局，就会以sizeHint的大小为准了
    layout->addWidget(btn);

    //打印默认的btn的策略
    QSizePolicy po=  btn->sizePolicy();
    qDebug()<<"默认策略"<<po.horizontalPolicy()<<"    " <<po.verticalPolicy()<<endl;

    //Fixed策略     初始以 sizeHint 的大小显示,   不能拉伸(GrowFlag)和收缩(ShrinkFlag)
    //btn->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed );

    //Minimum策略   初始占满布局，可扩大，可缩小(以sizeHint为最小值）
    //btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum );

   //Maximum策略  初始以 sizeHint的大小显示 ,  可扩大( 以 sizeHint为最大值)，可缩小（以minimumSizeHint 为最小值）
    //btn->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum );

    //Preferred策略 初始占满布局，可扩大，可缩小(以 minimumSizeHint 为最小值）
   // btn->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred );

    //MinimumExpanding策略  初始占满布局，可扩大，可缩小(以 sizeHint 为最小值）
     btn->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding );

     // Expanding策略   初始占满布局，可扩大，可缩小(以 minimumSizeHint 为最小值）
     //btn->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding );

     // Ignored  初始占满布局，可扩大，可缩小，忽略 sizeHint 的作用
     //btn->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored );


     //设置最大尺寸和最小尺寸(高于策略)
     btn->setMinimumSize(QSize(1,1));//设置为0，0表示没有设置
    // btn->setMaximumSize(QSize(100,100));

    //打印大小
    printSize(btn);

}





MainWindow::~MainWindow()
{
    delete ui;
}
