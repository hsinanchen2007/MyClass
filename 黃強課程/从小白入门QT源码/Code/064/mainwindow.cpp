#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSplitter>
#include<QTextEdit>
#include<QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //定义一个水平布局
    QHBoxLayout  *layout = new QHBoxLayout(ui->centralWidget);


    //定义水平的拆分器
    QSplitter * hSplitter = new QSplitter(Qt::Horizontal );

    //将拆分器加入到布局中
    layout->addWidget(hSplitter);

    //将编辑框放到水平拆分器中去
     QTextEdit  *left= new QTextEdit("左侧窗口");
   //  QTextEdit  *right= new QTextEdit("右侧窗口");

      QSplitter  *right= new QSplitter(Qt::Vertical);

     //将小部件添加到水平拆分器上
     hSplitter->addWidget(left);
     hSplitter->addWidget(right);


     //禁止将子窗口调整为0
     hSplitter->setChildrenCollapsible(false);

     //设置手柄的宽度
     hSplitter->setHandleWidth(50);



     //添加编辑框到 垂直拆分器上
      QTextEdit  *edit1= new QTextEdit("右上窗口", right);
      QTextEdit  *edit2= new QTextEdit("右中窗口", right);

      QTextEdit  *edit3= new QTextEdit("右下窗口");
      right->addWidget(edit3);


      //设置分割的比例  1:2
      hSplitter->setStretchFactor(0,1);
      hSplitter->setStretchFactor(1,2);

      //设置分割比例1:2:3
      right->setStretchFactor(0,1);
      right->setStretchFactor(1,2);
      right->setStretchFactor(2,3);

      //根据窗口获取索引
      int  index =  right->indexOf(edit2);
      qDebug("索引%d", index);

      //禁用调整手柄,第一个手柄的索引为1
       QSplitterHandle *  handle1= right->handle(1);
       handle1->setDisabled(true);
     //  QSplitterHandle *  handle2= right->handle(2);
      // handle2->setDisabled(true);

     //添加信号槽
       connect(right , SIGNAL(splitterMoved(int,int)),this ,SLOT(splitterMoved(int,int)));
}


void MainWindow::splitterMoved(int pos, int index)
{
    //pos  手柄的所在的坐标值，  index 是手柄的索引
    qDebug("分割移动: %d     %d",pos,index);
}

MainWindow::~MainWindow()
{
    delete ui;
}
