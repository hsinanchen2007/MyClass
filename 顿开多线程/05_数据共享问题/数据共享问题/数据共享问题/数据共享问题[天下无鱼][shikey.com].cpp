#include <iostream>
#include <thread>
#include <vector>
#include <cstdio>
#include <list>
using namespace std;
//No.1 ͨ������ȥ��������߳�
void print(int index) 
{
	//cout << "�߳����:" << index << endl;
	printf("�߳����:%d\n", index);
}
void TestCreateThread() 
{
	vector<thread*> test;
	for (int i = 0; i < 10; i++) 
	{
		test.push_back(new thread(print, i));
	}
	for (auto v : test) 
	{
		v->join();
	}
	cout << "���߳�" << endl;
}
//No.2 ���ݹ����������
//2.1 ֻ�����ݣ� �ȶ���ȫ������Ҫ���⴦��ֱ�Ӷ�ȡ����
vector<int>  g_data = { 1,2,3 };
void printTest(int num) 
{
	printf("���߳����:%d\n", num);
	for (auto v : g_data) 
	{
		printf("%d\t", v);
	}
	cout << endl;
}
void visitedData() 
{
	vector<thread*>  test;
	for (int i = 0; i < 10; i++) 
	{
		test.push_back(new thread(printTest, i));
	}
	for (auto v : test) 
	{
		v->join();
	}
	cout << "���߳�" << endl;
}
//2.2 �ж���д��ʱ����Ҫ�������⴦���ó���ֻ�Թ�����������һ������
class Seaking
{
public:
	void makeFriend() 
	{
		for (int i = 0; i < 10000; i++) 
		{
			cout << "Ů��������һ��\n";
			mm.push_back(i);
		}
	}		//д
	void breakUp()
	{
		for (int i = 0; i < 10000; i++) 
		{
			if (!mm.empty()) 
			{
				//cout << "Ů���Ѽ���һ��\n";
				printf("Ů���Ѽ���һ��:%d\n", mm.back());
				mm.pop_back();
			}
			else 
			{
				cout << "����״̬\n";
			}
		}
	}			//��
protected:
	list<int> mm;					//��д
};
void testSeeaking() 
{
	Seaking seaman;
	thread t1(&Seaking::makeFriend, &seaman);
	thread t2(&Seaking::breakUp, &seaman);
	t1.join();
	t2.join();
}

int main() 
{
	//TestCreateThread();
	//visitedData();
	testSeeaking();
	return 0;
}