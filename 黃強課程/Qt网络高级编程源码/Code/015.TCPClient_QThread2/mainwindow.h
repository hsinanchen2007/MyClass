#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpsocket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //虚函数
    virtual  void  closeEvent(QCloseEvent *event);

private slots:
    void  on_pushButtonConnect_clicked();
    void  slotPrint(QString info,  bool conn);


    void on_pushButtonSend_clicked();

signals:
    //这些信号是为了触发 TcpSocket中类对应的槽函数
    //（因为TcpSocket已经被移动到线程中，所以槽函数都会在线程中执行）
    void sigConnect(QString ip, quint16   port); //连接
    void sigSend(QByteArray  arr);//发送
    void sigClose();//关闭套接字

private:
    Ui::MainWindow *ui;

    //步骤一，新建一个类继承自QObject，
    //把要在线程中执行的内容写成槽, 定义相关对象
    TcpSocket m_tcp;

    //步骤二,定义一个QThread类的对象
    QThread  m_thread;

};
#endif // MAINWINDOW_H
