#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//头文件
#include<QTcpSocket>
#include<QMetaEnum>

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

    //槽函数
      void   slotConnected();
      void   slotDisconnected();
      void   slotStateChanged(QAbstractSocket::SocketState);
      void   slotError(QAbstractSocket::SocketError);

      void   slotReadyRead();

      void on_pushButtonSend_clicked();

private:
    Ui::MainWindow *ui;

    //定义一个QTcpSocket对象
    QTcpSocket  m_tcpClient;
};
#endif // MAINWINDOW_H
