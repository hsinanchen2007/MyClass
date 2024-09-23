#include<iostream> 
#include<thread> 

using  namespace  std; 

//命名空间this_thread有所有的线程辅助函数  get_id()   yield()  sleep_for()   sleep_until
using namespace std::this_thread;

//命名空间chrono有seconds模板类、milliseconds模板类
using  namespace  std::chrono;

void   ThreadFun(string  &str);
void   ThreadTest(string  &str);

int  main()
{
	thread t1(ThreadFun, string("hello"));
	thread t2(ThreadTest, string("Test 1"));
	thread t3(ThreadTest, string("Test 2"));
	thread t4(ThreadTest, string("Test 3"));
	thread t5(ThreadTest, string("Test 4"));
	thread t6(ThreadTest, string("Test 5"));
	thread t7(ThreadTest, string("Test 6"));
	thread t8(ThreadTest, string("Test 7"));
	thread t9(ThreadTest, string("Test 8"));
	thread t10(ThreadTest, string("Test 9"));

	cout << t1.get_id() << endl;

	//等待子线程完成
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();

	return 0;
}

void   ThreadFun(string  &str)
{
	cout <<"线程ID:"<< get_id() << endl;//获取线程ID

	while (true)
	{
		cout << str.c_str() << endl;
		// sleep_for(seconds(1));//让线程睡眠1秒

		yield();//让线程睡眠一个极小的时间片，给其他线程执行
		sleep_until(system_clock::now() + milliseconds(1000));//让线程睡眠当前时间+1秒
	}
}

void   ThreadTest(string  &str)
{
	cout <<"线程ID:"<< get_id() << endl;//获取线程ID

	while (true)
	{
		cout << str.c_str() << " " << __TIME__ << endl;
		// sleep_for(seconds(1));//让线程睡眠1秒

		yield();//让线程睡眠一个极小的时间片，给其他线程执行
		sleep_until(system_clock::now() + milliseconds(1234));//让线程睡眠当前时间+1.234秒, make it like random
	}
}


 