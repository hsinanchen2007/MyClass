#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QProgressDialog>
#include<QDebug>
#include<QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int  steps=0;

void MainWindow::on_btn_clicked()
{
    //设置定时器模拟处理过程
      QTimer  t ;
      connect(&t, SIGNAL(timeout()), this, SLOT(timerFun()));
      t.start(100);
      steps=0;


    //创建进度条对话框
     QProgressDialog  dlg(this);
     dlg.setObjectName("pd");


     //设置大小
     dlg.setFixedSize(400,200);

     //设置标题
     dlg.setWindowTitle("我的进度");

     //设置进度条的范围
     dlg.setRange(0,100);

     //设置详细文本
     dlg.setLabelText("处理任务期间");


     //去除对话框的问号？
     dlg.setWindowFlags(  dlg.windowFlags() &(  ~ Qt::WindowContextHelpButtonHint) );


     //去除对话框的关闭按钮
     dlg.setWindowFlags(  dlg.windowFlags() &(  ~ Qt::WindowCloseButtonHint) );

     //设置取消按钮的文本
     dlg.setCancelButtonText("小心");

     //隐藏取消按钮
    // dlg.setCancelButton(nullptr);


     //连接信号和槽
     connect(&dlg,SIGNAL(canceled()),this, SLOT(cancelFun()));



     //显示模态对话框
     dlg.exec();

}

void MainWindow::timerFun()
{
    //根据对象名找到对象
        QProgressDialog * pd =  findChild<QProgressDialog*>("pd");

        if(pd== nullptr) return ;
         //设置进度
         pd->setValue(  ++ steps);

}


 void MainWindow::cancelFun()
 {
         qDebug()<<"点击取消按钮"<<endl;
 }
