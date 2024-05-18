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

void  SellThread(string  & str )
{

	while (tickets>0)
	{
	
		int t = rand() % 5000;

		printf("%s 开始尝试锁定 \n", str.c_str());
		bool b = m3.try_lock_for(seconds(3));//再次加锁
		printf("%s 锁定结果 %d \n", str.c_str(), b);
		if (b &&  tickets > 0)
		{ 
			printf("%s 卖出 %d 票\n" , str.c_str(),  tickets-- );  
		 
			 //卖票所需时间
			 sleep_for(milliseconds(t)); 

			 printf("%s 解锁了！\n", str.c_str() );
			 m3.unlock();//去除加锁 
			
		} 
		 
		 printf("%s 结束尝试%d \n", str.c_str(), b);
	}

}

int  main()
{
	srand(time(0));
	thread  t1(SellThread, string("售票窗口A: "));
	thread  t2(SellThread, string("售票窗口B: "));
	 
	t1.join();
	t2.join();

	return 0;
}