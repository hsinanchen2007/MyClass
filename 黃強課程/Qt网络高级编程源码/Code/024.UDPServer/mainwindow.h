#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QSet>

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
    void on_pushButtonSend_clicked();

    void  slotReadyRead();

     void slotStateChanged(QAbstractSocket::SocketState);

     void slotError(QAbstractSocket::SocketError);

     void on_pushButtonBind_clicked();

private:
    Ui::MainWindow *ui;

    //定义UDP套接字类对象
    QUdpSocket  m_udp;

    //保存多个客户端的IP与端口
    //QSet 就是集合， 元素不能重复  ,  QPair代表了一对值
   QSet< QPair<QHostAddress , quint16>>  clients;

};
#endif // MAINWINDOW_H
