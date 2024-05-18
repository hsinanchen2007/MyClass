#include <iostream> 
#include<atomic>//原子操作头文件
#include<thread>
using  namespace  std;
 
atomic<int >   N = 0;//用atomic保证对N的操作的原子性

void  ThreadFun()
{
	for (int i = 0; i < 1000000; ++i)
	{
		++N;//线程并发导致 加操作 重叠，不是原子操作，因此肯定少于2000000
	}

}


int main()
{
	//每个线程100次+1
	thread  t1(ThreadFun);
	thread  t2(ThreadFun);

	t1.join();
	t2.join();

	cout << N << endl;//应该是2000000

}