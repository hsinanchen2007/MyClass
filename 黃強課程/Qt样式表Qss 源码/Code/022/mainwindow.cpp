#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //背景色qss生效
      ui->tabWidget->setAttribute(Qt::WA_StyledBackground);


}

MainWindow::~MainWindow()
{
    delete ui;
}

