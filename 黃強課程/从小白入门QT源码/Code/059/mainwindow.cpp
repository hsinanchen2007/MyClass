#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
#include<QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加一个子窗口
    QTextEdit *w1= new QTextEdit();
    w1->setHtml("内容11111111");

    //向mdiArea加入子窗口
    ui->mdiArea->addSubWindow(w1);


    //再添加子窗口
    QTextEdit *w2= new QTextEdit();
    w2->setHtml("内容22222222");
    ui->mdiArea->addSubWindow(w2);

    QTextEdit *w3= new QTextEdit();
    w3->setHtml("内容33333333");
    ui->mdiArea->addSubWindow(w3);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newBtn_clicked()
{
  QMdiSubWindow *subWnd   = new  QMdiSubWindow();
  subWnd->setWindowTitle("标题");
  subWnd->setWidget( new QTextEdit("新创建的") );
  subWnd->setAttribute(Qt::WA_DeleteOnClose);//关闭 后删除窗口
  ui->mdiArea->addSubWindow(subWnd);


  subWnd->show(); //在构造函数以外，需要show
}

void MainWindow::on_closeBtn_clicked()
{
    //关闭当前窗口
   ui->mdiArea->closeActiveSubWindow();
   //关闭所有窗口
  // ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_cdBtn_clicked()
{
//层叠排列
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_ppBtn_clicked()
{
    //平铺排列
     ui->mdiArea->tileSubWindows();
}

void MainWindow::on_tabBtn_clicked()
{
    //选项卡视图
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
}


