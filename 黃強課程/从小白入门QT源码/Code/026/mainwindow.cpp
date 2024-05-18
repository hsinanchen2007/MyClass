#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置提示文本
    ui->textEdit->setPlaceholderText("请输入些内容....");

    //插入纯文本( 不解析html标签的)
     ui->textEdit->insertPlainText("<p>纯文内容</p>");

    //插入html
    ui->textEdit->insertHtml("<p style='font-family:楷体;color:blue;font-size:20px;'>文本</p>");

    //增加文本
    ui->textEdit->append("<img src=':/new/prefix1/imgs/computer.png'   height='50' width='50' />");


     //部分选择(不同于单行编辑框的SetSection方法)
       QTextCursor cur = ui->textEdit->textCursor();//返回当前光标对象
       cur.setPosition(3, QTextCursor::MoveAnchor);//将光标和锚点的起始位置设置为3
      //保持锚点不变仍在3，光标位置变成为7，则将选中之间的文本
       cur.setPosition(7, QTextCursor::KeepAnchor);
      ui->textEdit->setTextCursor(cur);//将光标设置回去

    //设置选中文本的颜色
      ui->textEdit->setTextColor(QColor(255,0,0));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
      //qDebug()<<"文本改变"<<ui->textEdit->toHtml()<<endl;
       qDebug()<<"文本改变"<<ui->textEdit->toPlainText()<<endl;
}

void MainWindow::on_selectBtn_clicked()
{
    //全选
    ui->textEdit->selectAll();
}

void MainWindow::on_cutBtn_clicked()
{
    //剪切
    ui->textEdit->cut();
}

void MainWindow::on_pasteBtn_clicked()
{
    //粘贴
    ui->textEdit->paste();
}
