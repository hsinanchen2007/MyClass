#ifndef CARTHREAD_H
#define CARTHREAD_H
#include<QThread>
#include<QDebug>
#include<QMutex>
#include<QSemaphore>

class CarThread : public QThread
{
public:
    CarThread(   QString name);


    void run() override;

private:
    QString name;
};

#endif // CARTHREAD_H
