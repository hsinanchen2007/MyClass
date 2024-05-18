#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QThread>
#include "UdpSocket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void closeEvent(QCloseEvent *event);

public  slots:
    void on_pushButtonSend_clicked();

    void slotPrint(QString info);

    void slotFinished();

 signals:
    //发送给QUdpSocket对象来发送消息的
    void  sigSend(QHostAddress addr,quint16 port, QByteArray arr  );


private:
    Ui::MainWindow *ui;


    //第一步，继承自QObject类的对象
    UdpSocket   socket;//派生自QUdpSocket类

    //第二步，定义QThread类的对象
    QThread  thread;
};


#endif // MAINWINDOW_H
