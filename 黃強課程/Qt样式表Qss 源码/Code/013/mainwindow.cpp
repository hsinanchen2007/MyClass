#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QListView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置视图
    ui->comboBox->setView(new QListView());

}

MainWindow::~MainWindow()
{
    delete ui;
}

