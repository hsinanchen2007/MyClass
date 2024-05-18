#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//头文件
#include<QTcpServer> //代表TCP服务端类
#include<QTcpSocket> //代表一个TCP客户端类
#include<QMetaEnum>
#include<QList>

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
    void on_pushButtonStart_clicked();

    //槽函数
    void  slotNewConnection();
    void  slotReadyRead();
    void  slotDisconnected();
    void on_pushButtonSend_clicked();

private:
    Ui::MainWindow *ui;


    QTcpServer m_tcpServer;

    //保存所有连接过来的客户端
    QList<QTcpSocket *> clients;
};
#endif // MAINWINDOW_H
