#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置提示文本
    ui->lineEdit->setPlaceholderText("请输入你的名");

    //启用最末尾的清除按钮
    ui->lineEdit->setClearButtonEnabled(true);

    //设置文本
    ui->lineEdit->setText("我们正在学习QT编程，快来加入我");

    //设置输入为密码模式
   // ui->lineEdit->setEchoMode(QLineEdit::Password);

    //设置最大输入字符数
    //ui->lineEdit->setMaxLength(2);

    //设置输入掩码
    //ui->lineEdit->setInputMask("000.000.000.000");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug()<<"内容改变"<<arg1<<endl;
}

void MainWindow::on_selectBtn_clicked()
{
    //全选文本
    //ui->lineEdit->selectAll();
    //部分选中
    ui->lineEdit->setSelection(2, 3);//从第二个开始选择，选3个字符

}

void MainWindow::on_cutBtn_clicked()
{
     ui->lineEdit->cut();
}

void MainWindow::on_pasteBtn_clicked()
{
        ui->lineEdit->paste();
}
