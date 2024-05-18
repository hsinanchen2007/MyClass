#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"carthread.h"

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


void MainWindow::on_c5p1Button_clicked()
{
     CarThread  c1("AAA");
     CarThread  c2("BBB");
     CarThread  c3("CCC");
     CarThread  c4("DDD");
     CarThread  c5("EEE");


     c1.start();
     c2.start();
     c3.start();
     c4.start();
     c5.start();

     c1.wait();
}

void MainWindow::on_c5p3Button_clicked()
{
    CarThread  c1("AAA");
    CarThread  c2("BBB");
    CarThread  c3("CCC");
    CarThread  c4("DDD");
    CarThread  c5("EEE");


    c1.start();
    c2.start();
    c3.start();
    c4.start();
    c5.start();

    c1.wait();
}
