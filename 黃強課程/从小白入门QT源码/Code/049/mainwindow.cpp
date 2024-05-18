#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //也可以把布局设置到centralWidget
   // ui->centralWidget->setLayout(ui->horizontalLayout);

    QWidget *w = new QWidget(ui->centralWidget);

     w->setGeometry(QRect(100, 300, 471, 151));

    //创建水平布局
    QHBoxLayout *layout= new  QHBoxLayout();

    //创建3个按钮
    QPushButton *btn1= new QPushButton("one");
    QPushButton *btn2= new QPushButton("two");
    QPushButton *btn3= new QPushButton("three");

    //向布局中加入按钮
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);

   //将布局设置到w窗口上
    w->setLayout(layout);

    //设置四周的边距
   layout->setContentsMargins(20,0,20,0);

    //设置小部件直接的间隔
   layout->setSpacing(30);

}

MainWindow::~MainWindow()
{
    delete ui;
}
