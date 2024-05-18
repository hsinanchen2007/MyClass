#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置可以打开浏览器显示外部网页
    ui->textBrowser->setOpenExternalLinks(true);

    //设置 页面内容
     QUrl  url("qrc:/new/prefix1/files/page1.html");

    //QUrl  url= QUrl::fromLocalFile("C:\\Users\\Administrator\\Desktop\\Code\\035\\files\\page2.html");

    //设置搜素目录
    //ui->textBrowser->setSearchPaths({"C:\\Users\\Administrator\\Desktop\\Code\\035\\files\\"});
   //QUrl  url("page2.html");

    ui->textBrowser->setSource(url);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnForward_clicked()
{
    ui->textBrowser->forward();
}

void MainWindow::on_btnBack_clicked()
{
      ui->textBrowser->backward();
}

void MainWindow::on_textBrowser_backwardAvailable(bool a)
{
    ui->btnBack->setEnabled(a);
}

void MainWindow::on_textBrowser_forwardAvailable(bool a)
{
      ui->btnForward->setEnabled(a);
}

void MainWindow::on_textBrowser_sourceChanged(const QUrl &arg1)
{
    qDebug()<<"源文件改变了"<<arg1<<endl;
}
