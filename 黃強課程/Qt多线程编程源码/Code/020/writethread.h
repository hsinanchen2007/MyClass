#ifndef WRITETHREAD_H
#define WRITETHREAD_H
#include<QThread>
#include<QDebug>
#include<QReadWriteLock>


class WriteThread : public QThread
{
public:
    WriteThread(  QString name);

    void run() override;

public:
    QString name;
};

#endif // WRITETHREAD_H
