#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

//�ۺ���(��Ҫ�۲������ĸ��̱߳�����)
 void  Test::MySlot()
{
       qDebug()<<QStringLiteral("�ۺ����������ˣ����߳�")<<QThread::currentThreadId();
       QThread::sleep(5);
       qDebug()<<QStringLiteral("�ۺ���ִ����ϣ����߳�")<<QThread::currentThreadId();
 }
