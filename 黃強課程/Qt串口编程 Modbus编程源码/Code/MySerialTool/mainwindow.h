#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSerialPort>//��������ͷ�ļ�
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

    //��ʼ������ؼ�
    void InitUI();

private slots:
    void on_openButton_clicked();

   //�ۺ���
    void serialReadData();
    void bytesWriteData(qint64 bytes);
    void timeUp();

    void on_sendButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    //���崮����Ķ���
    QSerialPort m_serial;

    //��ʱ������
    QTimer  m_timer;

};
#endif // MAINWINDOW_H
