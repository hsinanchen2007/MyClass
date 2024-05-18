#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //不自动设置大小
    ui->scrollArea->setWidgetResizable(false);

    //设置滚动区域的显示内容
    ui->scrollArea->setWidget(  ui->widget  );

    //保证某个小部件可见
    ui->scrollArea->ensureWidgetVisible(ui->label_2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
