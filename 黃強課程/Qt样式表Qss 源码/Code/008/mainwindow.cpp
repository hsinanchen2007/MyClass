#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //第一个控件使用代码实现
    ui->label->setText("代码实现");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(QPixmap(":/img/plane.png"));
    ui->label->setScaledContents(true);
    ui->label->setMinimumSize(200,100);
   ui->label->setMaximumSize(200,100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

