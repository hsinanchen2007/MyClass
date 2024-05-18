#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       //设为可以被选中的
     ui->action->setCheckable(true);
      ui->action_2->setCheckable(true);

      ui->actionC->setCheckable(true);
       ui->actionC_2->setCheckable(true);

       //C  C_2菜单为一组
       QActionGroup  *group= new QActionGroup(this);
       group->setExclusive(true);//排他的，一组只能选中一项
       group->addAction(ui->actionC);
       group->addAction(ui->actionC_2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

