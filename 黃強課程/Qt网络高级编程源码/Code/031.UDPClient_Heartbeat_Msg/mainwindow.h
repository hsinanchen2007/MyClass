#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QBuffer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


//消息类型
enum MsgID
{
    HEART,
    NORMAL
};

//消息结构
struct Msg
{
    int  id;//消息类型
    QString data;//消息内容

    QByteArray  toByteArray()
    {
        QByteArray  arr;

        //QBuffer 将QByteArray当做文件来打开并写入数据
        QBuffer  buf(&arr);
        buf.open(QIODevice::WriteOnly);
        buf.write((char *)&id, sizeof(int) ); //将id写入到QByteArray中了
        buf.write( data.toUtf8(), data.toUtf8().size()); //将data写入到QByteArray中了
        buf.close();

        return arr;
    }

    void fromByteArray( QByteArray  arr )
    {
        //QBuffer 将QByteArray当做文件来打开并写入数据
        QBuffer  buf(&arr);
        buf.open(QIODevice::ReadOnly);
        buf.read((char *)&id, sizeof(int) ); //将id读取到QByteArray中了

        data = buf.readAll();//除了id之外，剩下的就是data了
        buf.close();
    }

};



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
