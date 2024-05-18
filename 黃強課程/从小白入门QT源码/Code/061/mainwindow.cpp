#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //为actionXJXM添加一个信号槽
    connect(ui->actionXJXM,SIGNAL(triggered(bool)),this, SLOT(XJXM_Click(bool)));

    //设置为可以带勾
    ui->actionXJXM->setCheckable(true);



    //定义两个菜单项(下面没有子菜单)
    QAction * actionOpen=new QAction(QIcon(":/new/prefix1/imgs/computer.png"),"打开");
    actionOpen->setToolTip("提示打开文件");
    actionOpen->setStatusTip("这是提示");
    actionOpen->setShortcut( QKeySequence::Open );//设置快捷键

     QAction * actionClose=new QAction("关闭");
    //actionClose->setIcon(QIcon(":/new/prefix1/imgs/music.png"));
    actionClose->setCheckable(true);//菜单前是否可以显示 勾


    //定义一个菜单(可以有子菜单的)
     QMenu  *menuFile= new QMenu("文件");
     menuFile->setToolTipsVisible(true);//设置提示可见
     menuFile->addAction(actionOpen);//添加菜单项
     menuFile->addAction(actionClose);
     menuFile->insertSeparator(actionClose);//插入分隔线

    //向菜单栏上添加菜单QMenu
     this->menuBar()->addMenu(menuFile);

     //为actionOpen添加一个信号槽
     connect(actionOpen,SIGNAL(triggered(bool)),this, SLOT(Open_Click(bool)));



     //向菜单栏上添加菜单项QAction
     QAction * actionOther=new QAction("其他");
     this->menuBar()->addAction(actionOther);
     //为actionOther添加一个信号槽
     connect(actionOther,SIGNAL(triggered(bool)),this, SLOT(Other_Click(bool)));


     //手动触发一个菜单点击
     actionOther->trigger();
}


void  MainWindow:: XJXM_Click(bool  b)
{
    QMessageBox::information(this,"标题","新建项目点击"+ QString::number((int)b));
}

void  MainWindow:: Open_Click(bool  b)
{
    QMessageBox::information(this,"标题","打开文件点击"+ QString::number((int)b));
}
void  MainWindow:: Other_Click(bool  b)
{
    QMessageBox::information(this,"标题","其他点击"+ QString::number((int)b));
}
MainWindow::~MainWindow()
{
    delete ui;
}
