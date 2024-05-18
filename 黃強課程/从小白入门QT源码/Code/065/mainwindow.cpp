#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>

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

void MainWindow::on_msgBtn_clicked()
{
    //调用相关静态成员函数弹出对话框
    // QMessageBox::about(nullptr, "关于","这是关于的对话框");

    //  QMessageBox::information(this, "信息","这是信息的对话框");

    //  QMessageBox::warning(this, "警告","这是警告的对话框");

    //   QMessageBox::StandardButton  ret=QMessageBox::question(this, "询问","这是询问的对话框");
    //    qDebug("询问结果  yes %d     no  %d" ,ret ==QMessageBox::Yes  , ret==QMessageBox::No  );


    QMessageBox::critical(this, "严重","这是严重的对话框");
}


void MainWindow::on_customBtn_clicked()
{
    QMessageBox  msg;
    msg.setWindowTitle("标题");
    msg.setText("这是文本");
    // msg.setIcon(QMessageBox::Question);  //设置系统图标

    QPixmap  icon(":/new/prefix1/imgs/dance.png");
    msg.setIconPixmap(  icon.scaled(50,50) );//设置自定义图标

    // msg.setDetailedText("这是详细文本内容");
    msg.setInformativeText("这是详细文本内容");

    //设置显示的按钮
    msg.setStandardButtons( QMessageBox::Yes |  QMessageBox::Help|QMessageBox::Ok );
    msg.addButton(QMessageBox::Cancel);

    //添加自定义的按钮
    QPushButton  btn("自定义的按钮");
    msg.addButton(&btn ,QMessageBox::RejectRole);

    //获取对话框里面所有的按钮
    QList<QAbstractButton *>  list= msg.buttons();
    foreach ( QAbstractButton * b, list) {
        if(b->text()=="OK")
        {
            b->setText("确定");
        }
    }


    int  ret= msg.exec();//弹出模态对话框

    QAbstractButton *clickedBtn= msg.clickedButton();//获取被点击的按钮

    qDebug()<<"返回"<<ret<< "   "<<clickedBtn->text()<<endl;

    switch(ret)
    {
    case  QMessageBox::Yes:
        qDebug("Yes");
        break;
    case  QMessageBox::Help:
        qDebug("Help");
        break;
    case  QMessageBox::Ok:
        qDebug("Ok");
        break;
    case  QMessageBox::Cancel:
        qDebug("Cancel");
        break;

    }

}
