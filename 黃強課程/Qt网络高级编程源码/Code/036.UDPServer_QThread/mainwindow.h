#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QThread>
#include "recvthread.h"

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

    void slotPrint(QString info ,bool bind);

    void slotFinished();

private slots:
    void on_pushButtonBind_clicked();

private:
    Ui::MainWindow *ui;


    //定义线程对象
    RecvThread *thread;

};
#endif // MAINWINDOW_H
