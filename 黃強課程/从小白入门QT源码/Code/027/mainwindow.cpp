#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置可编辑的
    ui->comboBox->setEditable(true);

    //设置图标大小
    ui->comboBox->setIconSize(QSize(50,50));

    // 添加下拉选项
    ui->comboBox->addItem(QIcon(":/new/prefix1/imgs/computer.png"),"编程");

    // 添加下拉选项
    ui->comboBox->addItem("跳舞");

    // 在索引index前面插入下拉选项
    ui->comboBox->insertItem(1, QIcon(":/new/prefix1/imgs/music.png"),"音乐");

    //一次添加多个选项
    ui->comboBox->addItems( {"运动","其他"}  );

    //设置当前选择的索引
    ui->comboBox->setCurrentIndex(1);//选择第2个

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QMessageBox::information(this,"提示", arg1);
}
