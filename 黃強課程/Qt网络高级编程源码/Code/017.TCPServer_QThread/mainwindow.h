#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QThread>
#include"tcpserver.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonSend_clicked();

    void  slotPrint(QString info,  bool conn);

private:
    Ui::MainWindow *ui;

    //定义服务端对象
   TcpServer m_tcpServer;

};
#endif // MAINWINDOW_H
