#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSerialPort>//包含串口头文件
#include<QDateTime>
#include<QTimer>
#include<QDebug>
#include<QThread>

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

private slots:
    void on_openButton_clicked();

   //槽函数
    void serialReadData();
    void bytesWriteData(qint64 bytes);
    void timeUp();

    void on_sendButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    //定义串口类的对象
    QSerialPort m_serial;

    //定时器对象
    QTimer  m_timer;

};
#endif // MAINWINDOW_H
