#include "mythread.h"

MyThread::MyThread()
{

}


 void MyThread::run()
 {
     //ѭ��100��Σ�Ȼ��ÿ�ζ����ð�ť���ı�Ϊ��ǰ����
    for(int i=0;i<=1000000;++i)
    {
        //ͨ���źŲ����ı�UI����ʾ
        emit  mySig(QString::number(i));
        //��ֹCPUһֱִ�����̣߳��Ӷ�����main�߳��޷�ִ��
        QThread::usleep(1);
    }
  }
