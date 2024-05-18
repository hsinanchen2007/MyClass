#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QModbusDataUnit>
#include<QModbusClient>
#include<QModbusRtuSerialMaster>
#include<QModbusTcpClient>

#include<QModbusServer>
#include<QModbusRtuSerialSlave>
#include<QModbusTcpServer>

#include<QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //��ʼ����վ��UI
    void InitMasterUI();
    //��ʼ����վ��UI
    void InitSlaveUI();


private slots:
    void on_mType_currentIndexChanged(const QString &arg1);

    void on_sType_currentTextChanged(const QString &arg1);

    void on_mConBtn_clicked();

    void on_m03Btn_clicked();

    void on_m06Btn_clicked();

    void on_m16Btn_clicked();

    void on_sConBtn_clicked();

    void on_tableSlave_cellChanged(int row, int column);

    void on_sTable_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    //������վ������󣬷�������new QModbusRtuSerialMaster  ���� new QModbusTcpClient
    QModbusClient * master= nullptr;

    //�����վ������󣬷�������new QModbusRtuSerialSlave  ���� new QModbusTcpServer
    QModbusServer * slave= nullptr;

};
#endif // MAINWINDOW_H
