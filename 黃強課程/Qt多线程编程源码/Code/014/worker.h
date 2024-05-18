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
    //����ۺ�����ͨ���ź���ִ���̺߳���
    void  Do();

};

#endif // WORKER_H
