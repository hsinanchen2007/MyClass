#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
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

void MainWindow::on_btnOpen_clicked()
{
    //参数分别是：父窗口、标题、默认打开目录、文件过滤器
     QString file_name = QFileDialog::getOpenFileName(this,"我的打开",
         "C:\\Users\\Administrator\\Desktop","Text File(*.txt);;image(*.jpg *.png)");

     //正常返回选择文件的路径，如果点取消，则返回""
     qDebug() << file_name;

}

void MainWindow::on_btnOpenDir_clicked()
{
    //参数分别是：父窗口、标题、默认打开目录
    QString folder_name = QFileDialog::getExistingDirectory(NULL,"我的打开目录",".");

    //正常返回选择目录的路径，如果点取消，则返回""
    qDebug() << folder_name;

}

void MainWindow::on_btnSave_clicked()
{
    //参数分别是：父窗口、标题、默认保存目录、保存后缀名
     QString path = QFileDialog::getSaveFileName(this,"另存为了",   "."  ,"Text File(*.txt)");

     //正常返回要保存文件的路径，如果点取消，则返回""
     qDebug() << path;

}
