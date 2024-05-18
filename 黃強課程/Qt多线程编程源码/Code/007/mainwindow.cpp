#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
   t.start();
}

void MainWindow::on_forceButton_clicked()
{
    //ǿ����ֹ�߳�ִ�У���ֹ�ĵط���ȷ��
    t.terminate();
}

void MainWindow::on_flagButton_clicked()
{
    //�ı��ǣ����߳�ѭ����ֹ���Ӷ������߳�
    t.flag =false;
}
