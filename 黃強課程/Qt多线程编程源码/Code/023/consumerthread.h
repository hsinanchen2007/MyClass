#ifndef CONSUMERTHREAD_H
#define CONSUMERTHREAD_H

#include<QThread>
#include<QDebug>
#include<QWaitCondition>
#include<QMutex>

class ConsumerThread : public QThread
{
public:
    ConsumerThread(  QString name);
     void run() override;
private:
   QString name;
};

#endif // CONSUMERTHREAD_H
