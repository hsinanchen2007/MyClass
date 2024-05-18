#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取标准按钮的枚举值
    QDialogButtonBox::StandardButtons  flag=  ui->buttonBox->standardButtons();

    //在原来的基础上，添加一个save标准按钮
    ui->buttonBox->setStandardButtons(  flag  |  QDialogButtonBox::Save |  QDialogButtonBox::Help  );

    //添加一个自定义的按钮
    QPushButton *btn= new QPushButton("自定义的");
    ui->buttonBox->addButton(btn , QDialogButtonBox::RejectRole );

    //获取Box里面的所有按钮
    QList<QAbstractButton *> list= ui->buttonBox->buttons();
    foreach( QAbstractButton * b,   list ){
        if(b->text()=="OK"){
            b->setText("确定");
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonBox_accepted()
{
      qDebug()<<"表示同意"<<endl;
}

void MainWindow::on_buttonBox_clicked(QAbstractButton *button)
{
       qDebug()<<button->text()<<"按钮被我点击"<<endl;
}

void MainWindow::on_buttonBox_helpRequested()
{
    qDebug()<<"表示帮助"<<endl;
}

void MainWindow::on_buttonBox_rejected()
{
     qDebug()<<"表示拒绝"<<endl;
}
