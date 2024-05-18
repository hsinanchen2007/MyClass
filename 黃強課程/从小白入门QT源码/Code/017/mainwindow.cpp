#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //在QMainWinodow项目中，自己动态创建的控件，应该放在centralWidget
    QPushButton  * btn = new QPushButton("纯代码的创建", ui->centralWidget);

    //设置按钮的大小和位置
    btn->setGeometry(300,100, 200,80);

    //设置按钮图标
    btn->setIcon(QIcon(":/new/prefix1/imgs/computer.png"));

    //设置图标大小
    btn->setIconSize(QSize(50,50));

    //通过样式表设置按钮背景图片
    btn->setStyleSheet(
    " QPushButton {  border-image: url(:/new/prefix1/imgs/bg1.png);   } "
    " QPushButton:hover { border-image: url(:/new/prefix1/imgs/bg2.png);  } "
    " QPushButton:pressed { border-image: url(:/new/prefix1/imgs/bg3.png);   }"
    );

    //连接按钮的clicked()信号和槽
   connect(btn,SIGNAL(clicked(bool)), this, SLOT(my_slot()));

}

void  MainWindow::my_slot()
{
    qDebug()<<"按钮被我点击"<<endl;
}


MainWindow::~MainWindow()
{
    delete ui;
}
