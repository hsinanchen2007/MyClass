#include <iostream>
#include <thread>
#include <vector>
#include <cstdio>
#include <list>
using namespace std;
//No.1 通过容器去创建多个线程
void print(int index) 
{
	//cout << "线程序号:" << index << endl;
	printf("线程序号:%d\n", index);
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
	cout << "主线程" << endl;
}
//No.2 数据共享问题分析
//2.1 只读数据： 稳定安全，不需要特殊处理，直接读取即可
vector<int>  g_data = { 1,2,3 };
void printTest(int num) 
{
	printf("子线程序号:%d\n", num);
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
	cout << "主线程" << endl;
}
//2.2 有读有写的时候：需要经过特殊处理，让程序只对共享数据做单一操作。
class Seaking
{
public:
	void makeFriend() 
	{
		for (int i = 0; i < 10000; i++) 
		{
			cout << "女朋友增加一个\n";
			mm.push_back(i);
		}
	}		//写
	void breakUp()
	{
		for (int i = 0; i < 10000; i++) 
		{
			if (!mm.empty()) 
			{
				//cout << "女朋友减少一个\n";
				printf("女朋友减少一个:%d\n", mm.back());
				mm.pop_back();
			}
			else 
			{
				cout << "单身狗状态\n";
			}
		}
	}			//读
protected:
	list<int> mm;					//读写
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