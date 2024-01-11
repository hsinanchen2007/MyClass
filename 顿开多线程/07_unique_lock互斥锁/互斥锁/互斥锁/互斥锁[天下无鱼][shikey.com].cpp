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
			//No.1 unique_lock 加锁过程
			//unique_lock<mutex> unique(mtx);
			//No.2 unique_lock其他参数
			//2.1 adopt_lock 先进行lock操作,不使用，程序会调用abort函数终止程序
			//mtx.lock();			
			//unique_lock<mutex> unique(mtx, adopt_lock);
			//2.2 defer_lock ,需要自己手动lock，创建是一个没有lock的锁
			//unique_lock<mutex> unique(mtx, defer_lock);
			//unique.lock();
			//2.3 try_to_lock 调用owns_lock()判定
			unique_lock<mutex> unique(mtx, try_to_lock);
			cout << "上厕所" << endl;
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
				cout << "洗澡" << endl;
				num.pop_back();
			}
			else 
			{
				cout << "正在做事" << endl;
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