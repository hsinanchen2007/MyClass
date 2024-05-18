#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取tab页中的QWidget
    QWidget  *page1= ui->tabWidget->widget(0);
    page1->setStyleSheet("background-color:red");

    QWidget  *page2= ui->tabWidget->widget(1);
    page2->setStyleSheet("background-color:green");

    //设置tab页的标题，图标
    ui->tabWidget->setTabIcon(0, QIcon(":/new/prefix1/imgs/computer.png"));
    ui->tabWidget->setTabText(0,"第一");

    //设置显示关闭按钮
    ui->tabWidget->setTabsClosable(true);

    //移动tab页
    ui->tabWidget->setMovable(true);

    //添加一个tab页
    QWidget * page3= new QWidget;
    page3->setStyleSheet("background-color:blue");
    ui->tabWidget->addTab(page3, QIcon(":/new/prefix1/imgs/music.png"),"音乐");

    //设置当前选择的tab页
    ui->tabWidget->setCurrentIndex(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    qDebug("请求关闭%d",index);

    //根据索引删除某个tab页
    ui->tabWidget->removeTab(index);

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
       qDebug("当前页面%d",index);
}
