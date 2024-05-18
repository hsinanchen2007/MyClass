#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWidget *  w= new  QWidget(ui->centralWidget);
    w->setGeometry(QRect(150, 350, 451, 171));

    //网格布局
    QGridLayout  *layout= new QGridLayout(w);

    //创建4个按钮
    QPushButton *btn1= new QPushButton("one");
    QPushButton *btn2= new QPushButton("two");
    QPushButton *btn3= new QPushButton("three");
    QPushButton *btn4= new QPushButton("four");

    //向布局中加入按钮
    layout->addWidget(btn1,0,0);//放在第1行，第1列，跨1行1列
    layout->addWidget(btn2,0,1);//放在第1行，第2列，跨1行1列
    layout->addWidget(btn3,1,0);//放在第2行，第1列，跨1行1列
    layout->addWidget(btn4,2,0,1,2);//占一行两列

    //设置与四面的间隔
    layout->setContentsMargins(20,0,20,0);
    //设置小部件水平的间距
    layout->setHorizontalSpacing(50);

}

MainWindow::~MainWindow()
{
    delete ui;
}
