#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

//�ۺ���
 void  Worker::Do()
 {
     //ѭ��100��Σ�Ȼ��ÿ�ζ����ð�ť���ı�Ϊ��ǰ����
    for(int i=0;i<=1000000;++i)
    {
        emit mySig( QString::number(i) );
        //  ��ֹ���߳�һֱռ��CPU���Ӷ�main�߳� �ò���ִ��
        QThread::usleep(1);
    }
 }
