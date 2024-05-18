#ifndef WORKER_H
#define WORKER_H
#include <QThread>
#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
     void mySig(QString num);
  public slots:
    //定义槽函数，通过信号来执行线程函数
    void  Do();

};

#endif // WORKER_H
