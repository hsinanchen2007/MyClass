#include<stdio.h>
#include<thread>
#include<mutex>

using namespace std;
using namespace  std::this_thread;
using namespace  std::chrono;

int   tickets = 100;
 
//定义一个互斥对象
mutex  m;
recursive_mutex   m2;//可以递归加锁
timed_mutex  m3;//可以指定锁住的时间

void  SellThread(string  & str)
{

	while (tickets>0)
	{
		 
		m3.try_lock_for(seconds(3));//再次加锁
		if (tickets > 0)
		{ 
			sleep_for(milliseconds(100));
			printf("%s 卖出 %d 票\n" , str.c_str(),  tickets-- ); 
		} 
		//m3.unlock();//去除加锁 

		//sleep_for(milliseconds(100));
	}

}

int  main()
{
	thread  t1(SellThread, string("售票窗口A: "));
	thread  t2(SellThread, string("售票窗口B: "));

	t1.join();
	t2.join();

	return 0;
}