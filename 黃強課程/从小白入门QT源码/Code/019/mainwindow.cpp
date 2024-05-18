#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //创建菜单
       QMenu *menu=new QMenu();
       menu->addMenu("新建");
       menu->addMenu("查找");

       //设置菜单的弹出方式
       ui->toolButton_5->setPopupMode(QToolButton::InstantPopup );//立刻弹出
       //ui->toolButton_5->setPopupMode(QToolButton::DelayedPopup );//长按弹出
       //ui->toolButton_5->setPopupMode(QToolButton::MenuButtonPopup );//多一个按钮

       //设置工具按钮的菜单
       ui->toolButton_5->setMenu(menu);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QMessageBox::information(this,"提示","按钮点击");
}
