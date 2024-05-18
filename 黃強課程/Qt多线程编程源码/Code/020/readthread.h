#ifndef READTHREAD_H
#define READTHREAD_H
#include<QThread>
#include<QDebug>
#include<QReadWriteLock>

class ReadThread : public QThread
{
public:
    ReadThread( QString name);

    void run() override;

public:
    QString name;
};

#endif // READTHREAD_H
