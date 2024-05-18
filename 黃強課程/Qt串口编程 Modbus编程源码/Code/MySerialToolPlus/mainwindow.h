#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSerialPort>//包含串口头文件
#include<QDateTime>
#include<QTimer>
#include<QDebug>
#include<QThread>
#include"myserialport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //初始化界面控件
    void InitUI();

    //初始化串口
    void InitCOM();


    //窗口关闭时调用
     void closeEvent(QCloseEvent *event);

private slots:
    void on_openButton_clicked();

    void on_sendButton_clicked();

    void timeUp();

    void on_checkBox_stateChanged(int arg1);

signals:
    //定义一些信号，方便去调用线程中的 MySerialPort中的槽函数
    void  sigStart(MySerialPort::Settings  s);
    void  sigStop();
    void  sigSend(QByteArray  data);

 public slots:
    void started();
    void stoped(int status);
    void recieved(QByteArray data);

private:
    Ui::MainWindow *ui;

    //步骤一、自定义的串口类对象
    MySerialPort m_serial;

    //步骤二、创建一个线程对象
    QThread m_thread;


    //定时器对象
    QTimer  m_timer;
};
#endif // MAINWINDOW_H
