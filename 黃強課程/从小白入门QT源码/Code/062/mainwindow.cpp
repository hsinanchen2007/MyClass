#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QToolButton>


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


     //向工具条添加QAction
     ui->mainToolBar->addAction(actionOpen);
     ui->mainToolBar->addAction(actionClose);
     ui->mainToolBar->addSeparator();
     ui->mainToolBar->addAction(actionOther);

     //向工具条添加QToolButton
     QToolButton * btn= new QToolButton;
     btn->setIcon(QIcon(":/new/prefix1/imgs/music.png"));
     btn->setText("音乐");
     btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     ui->mainToolBar->addWidget(btn);

      ui->mainToolBar->setToolButtonStyle( Qt::ToolButtonTextUnderIcon);

     //设置工具条禁止移动
   //ui->mainToolBar->setMovable(false);

     //设置停靠区域
     /*
        LeftToolBarArea = 0x1,
        RightToolBarArea = 0x2,
        TopToolBarArea = 0x4,
        BottomToolBarArea = 0x8,
*/
     ui->mainToolBar->setAllowedAreas(Qt::LeftToolBarArea);

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
