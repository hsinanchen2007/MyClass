#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>
#include<QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QString name);

    void run() override;

private:
    QString name;//Ïß³ÌÃû³Æ
};

#endif // MYTHREAD_H
