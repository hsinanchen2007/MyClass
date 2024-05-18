#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSerialPort>//��������ͷ�ļ�
#include<QDateTime>
#include<QTimer>
#include<QDebug>
#include<QThread>
#include"myserialport.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //��ʼ������ؼ�
    void InitUI();

    //��ʼ������
    void InitCOM();


    //���ڹر�ʱ����
     void closeEvent(QCloseEvent *event);

private slots:
    void on_openButton_clicked();

    void on_sendButton_clicked();

    void timeUp();

    void on_checkBox_stateChanged(int arg1);

signals:
    //����һЩ�źţ�����ȥ�����߳��е� MySerialPort�еĲۺ���
    void  sigStart(MySerialPort::Settings  s);
    void  sigStop();
    void  sigSend(QByteArray  data);

 public slots:
    void started();
    void stoped(int status);
    void recieved(QByteArray data);

private:
    Ui::MainWindow *ui;

    //����һ���Զ���Ĵ��������
    MySerialPort m_serial;

    //�����������һ���̶߳���
    QThread m_thread;


    //��ʱ������
    QTimer  m_timer;
};
#endif // MAINWINDOW_H
