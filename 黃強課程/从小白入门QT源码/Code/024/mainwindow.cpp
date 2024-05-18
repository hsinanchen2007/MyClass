#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置 文本的对齐方式
    ui->label_text->setAlignment(Qt::AlignRight);

    //设置是否点击链接直接打开  浏览器
    // ui->label_text->setOpenExternalLinks(true);

    //设置一些交互权限，比如能否选择文本，点击链接
    ui->label_text->setTextInteractionFlags(  Qt::TextSelectableByMouse |  Qt::LinksAccessibleByMouse  );

    //设置默认选中
    ui->label_text->setSelection(3,2);

    //获取焦点，以方便观察选中的区域
    ui->label_text->setFocus();

    //获取选择的文本
   QString str= ui->label_text->selectedText();
   qDebug()<<str<<endl;

   //通过Qss 设置 字体颜色，背景色
   ui->label_text->setStyleSheet(QString(
                                     "color: rgb(255, 0, 0);"
                                     "background-color: yellow;"
                                     ));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_text_linkActivated(const QString &link)
{
    qDebug()<<"链接被点击了"<<endl;
}

void MainWindow::on_label_text_linkHovered(const QString &link)
{
    qDebug()<<"鼠标滑过链接"<<endl;
}
