#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <list>
using namespace std;
class DoSomething
{
public:
	void wc() 
	{
		for (int i = 0; i < 10000; i++) 
		{
			//No.1 unique_lock ��������
			//unique_lock<mutex> unique(mtx);
			//No.2 unique_lock��������
			//2.1 adopt_lock �Ƚ���lock����,��ʹ�ã���������abort������ֹ����
			//mtx.lock();			
			//unique_lock<mutex> unique(mtx, adopt_lock);
			//2.2 defer_lock ,��Ҫ�Լ��ֶ�lock��������һ��û��lock����
			//unique_lock<mutex> unique(mtx, defer_lock);
			//unique.lock();
			//2.3 try_to_lock ����owns_lock()�ж�
			unique_lock<mutex> unique(mtx, try_to_lock);
			cout << "�ϲ���" << endl;
			if (unique.owns_lock())
			{
				num.push_back(i);
			}
		}
	}
	void bath() 
	{
		for (int i = 0; i < 10000; i++) 
		{
			if (!num.empty()) 
			{
				unique_lock<mutex> unique(mtx);
				cout << "ϴ��" << endl;
				num.pop_back();
			}
			else 
			{
				cout << "��������" << endl;
			}
		}

	}
protected:
	list<int> num;
	mutex mtx;
};
int main() 
{
	DoSomething people;
	thread t1(&DoSomething::wc, &people);
	thread t2(&DoSomething::bath, &people);
	t1.join();
	t2.join();
	return 0;
}