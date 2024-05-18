#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QThread>
#include<QDebug>

//头文件
#include<QTcpSocket>
#include<QMetaEnum>

#include"recvthread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonConnect_clicked();

      void  slotPrint(QString info,  bool conn);

      void on_pushButtonSend_clicked();

private:
    Ui::MainWindow *ui;


    //定义一个线程对象
    RecvThread    thread;

};
#endif // MAINWINDOW_H
