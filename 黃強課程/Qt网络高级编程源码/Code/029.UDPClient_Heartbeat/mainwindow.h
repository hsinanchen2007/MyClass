#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   virtual void timerEvent(QTimerEvent *event);

private slots:
    void on_pushButtonSend_clicked();

    void  slotReadyRead();

     void slotStateChanged(QAbstractSocket::SocketState);

     void slotError(QAbstractSocket::SocketError);

private:
    Ui::MainWindow *ui;


    //定义UDP套接字类对象
    QUdpSocket  m_udp;

};
#endif // MAINWINDOW_H
