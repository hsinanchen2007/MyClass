#include<iostream>
#include<future>
#include<thread>
using namespace  std;
using  namespace  std::this_thread;
using namespace   std::chrono;

//��ʱ�Ĳ���
int   work(int  a, int  b)
{
	cout << "��ʼ���㣺" << endl; 
	sleep_for(seconds(5));//��������ʱ5��
	return  a + b; 
}


int  main()
{
	//�����Ľ��
	future<int> result = async(work, 123, 456);//move��ֵ����

	result.wait();//�ȴ��������������Ż����ִ��
	cout << "��������" << endl;
	int  sum= result.get();//��ȡ���
	cout << "���յĽ���ǣ�" << sum << endl;

	return 0;
}
