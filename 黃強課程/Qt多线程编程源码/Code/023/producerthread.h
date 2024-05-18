#ifndef PRODUCERTHREAD_H
#define PRODUCERTHREAD_H

#include<QThread>
#include<QDebug>
#include<QWaitCondition>
#include<QMutex>


class ProducerThread : public QThread
{
public:
    ProducerThread(QString name);

    void run() override;

private:
   QString name;
};

#endif // PRODUCERTHREAD_H
