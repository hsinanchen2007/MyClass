#include <iostream> 
#include<atomic>//ԭ�Ӳ���ͷ�ļ�
#include<thread>
using  namespace  std;
 
atomic<int >   N = 0;//��atomic��֤��N�Ĳ�����ԭ����

void  ThreadFun()
{
	for (int i = 0; i < 1000000; ++i)
	{
		++N;//�̲߳������� �Ӳ��� �ص�������ԭ�Ӳ�������˿϶�����2000000
	}

}


int main()
{
	//ÿ���߳�100��+1
	thread  t1(ThreadFun);
	thread  t2(ThreadFun);

	t1.join();
	t2.join();

	cout << N << endl;//Ӧ����2000000

}