#include <iostream>
#include <list>
#include <string>
#include <cstdio>
#include <thread>
#include <mutex>
using namespace std;
/*
	No.1 ��һ�ּ�����ʽ
	mutex��(������) ����mutex��Ķ���
	1.1 ͨ������lock�������м���
	1.2 ͨ������unlock���н���
	ע��㣺 lock������unlock����
	No.2 �ڶ��ּ�����ʽ
	lock_guard ����ʵ�ּ���
		lock_guard��Ĺ��캯���е���lock����
		lock_gurad�����������������unlock����
*/
class SeaKing 
{
public:
	void makeFriend() 
	{
		lock_guard<mutex> lgObject(m_mutex);
		for (int i = 0; i < 10000; i++) 
		{
			//m_mutex.lock();
			printf("����һ��Ů����:%d", i);
			mm.push_back(i);
			//m_mutex.unlock();
		}
	}
	void breakUp() 
	{
		for (int i = 0; i < 10000; i++) 
		{
			if (!mm.empty()) 
			{
				lock_guard<mutex> lgObject(m_mutex);
				//m_mutex.lock();
				printf("����һ��Ů����:%d\n", mm.back());
				mm.pop_back();
				//m_mutex.unlock();
			}
			else 
			{
				printf("�����䵥��!\n");
			}
		}
	}
protected:
	list<int> mm;
	mutex m_mutex;				//���ȵ�һ������һ������������
};

int main() 
{
	SeaKing man;
	thread t1(&SeaKing::makeFriend, &man);
	thread t2(&SeaKing::breakUp, &man);
	t1.join();
	t2.join();
	return 0;
}