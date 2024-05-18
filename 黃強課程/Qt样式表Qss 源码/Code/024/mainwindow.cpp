#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //方式二：QWidget::setStyleSheet设置控件样式
    ui->widget->setStyleSheet( " background-color: red; ");


    //方式三： 通过加载文件中的内容来设置样式
    QFile file(":/qss.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    //读取文件内容
    QString css = in.readAll();

    //全局设置(优先级最低)
    qApp->setStyleSheet(css);


}

MainWindow::~MainWindow()
{
    delete ui;
}

