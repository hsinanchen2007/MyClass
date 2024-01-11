#include <iostream>
#include <thread>
#include <atomic>		//1.����ͷ�ļ�
using namespace std;
/*
	ԭ�Ӳ���: �Ա����Ķ�д�������ɷָ�
	atomic: ģ����
	atomic<int> foo(0);
	//��������͸�ֵ���㱻ɾ����
	atomic(const atomic&) = delete;
	atomic& operator=(const atomic&) = delete;
*/
int value = 0;
atomic<int> a_value = 0;
atomic<int> t_value = 0;
void testFunc() 
{
	for (int i = 0; i < 10000; i++) 
	{
		value++;
		a_value++;
		//t_value = t_value + 1; ������
		//if (t_value != 0)
		//	t_value = 1;
		t_value += 1;
	}
}
int main() 
{
	thread t1(testFunc);
	thread t2(testFunc);
	t1.join();
	t2.join();
	cout << value << endl;
	cout << a_value << endl;
	cout << t_value << endl;
	return 0;
}