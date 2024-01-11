#include <iostream>
#include <list>
#include <string>
#include <cstdio>
#include <thread>
#include <mutex>
using namespace std;
/*
	No.1 第一种加锁方式
	mutex类(互斥量) 创建mutex类的对象
	1.1 通过调用lock函数进行加锁
	1.2 通过调用unlock进行解锁
	注意点： lock必须与unlock出现
	No.2 第二种加锁方式
	lock_guard 对象实现加锁
		lock_guard类的构造函数中调用lock函数
		lock_gurad类的析构函数调用了unlock函数
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
			printf("增加一个女朋友:%d", i);
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
				printf("分手一个女朋友:%d\n", mm.back());
				mm.pop_back();
				//m_mutex.unlock();
			}
			else 
			{
				printf("海王变单身狗!\n");
			}
		}
	}
protected:
	list<int> mm;
	mutex m_mutex;				//首先第一步构建一个互斥量对象
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