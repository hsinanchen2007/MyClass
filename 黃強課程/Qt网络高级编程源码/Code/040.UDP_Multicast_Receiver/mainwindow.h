#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QUdpSocket>

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
    void on_pushButtonBind_clicked();

    void on_pushButtonJoin_clicked();

    void on_pushButtonLeave_clicked();

  void  slotReadyRead();

private:
    Ui::MainWindow *ui;

    //定义UDP套接字对象
    QUdpSocket m_udp;
};
#endif // MAINWINDOW_H
