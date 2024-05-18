#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置键序列

    //标准快捷键
    ui->keySequenceEdit->setKeySequence(  QKeySequence(QKeySequence::Open) );

    //字符串设置
    ui->keySequenceEdit->setKeySequence(  QKeySequence("Ctrl+C"));

    // 键设置
    ui->keySequenceEdit->setKeySequence(  QKeySequence(Qt::SHIFT + Qt::ALT + Qt::Key_F  ));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence)
{
    if( ! keySequence.isEmpty())
    {
            qDebug()<<keySequence<<endl;
    }

}
