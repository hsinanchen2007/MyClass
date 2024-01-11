#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
/*
	condition_variable类
	1.调用wait函数 阻塞线程
	2.unique_lock 加锁线程
	3.notify_one notify_all 唤醒线程
*/
condition_variable cv;
mutex cv_m;
int i = 0;				//描述唤醒条件
bool done = false;		//充当开关

void waits_one() 
{
	unique_lock<mutex> lk(cv_m);
	cout << "等待中...." << endl;
	cv.wait(lk, [] {return i == 1; });
	cout << "运行结束..." << endl;
	done = true;
}
void signals_one() 
{
	this_thread::sleep_for(1s);
	cout << "不做条件变量唤醒操作" << endl;
	cv.notify_one();

	unique_lock<mutex> lk(cv_m);
	i = 1;
	while (!done) 
	{
		cout << "条件变量满足的唤醒操作" << endl;
		lk.unlock();
		cv.notify_one();
		this_thread::sleep_for(1s);
		lk.lock();
	}
}
void testNotifyOne() 
{
	thread t1(waits_one), t2(signals_one);
	//thread t3(waits_one);
	t1.join();
	//t3.join();
	t2.join();
	//当存在多个阻塞线程时候，notify_one 会存在 阻塞问题。程序是不稳定
}
void waits_thread(int id)
{
	unique_lock<mutex> lk(cv_m);
	cout <<id <<":等待中...." << endl;
	cv.wait(lk, [] {return i == 1; });
	//this_thread::sleep_for(chrono::seconds(id));
	cout<<id << ":运行结束..." << endl;
	done = true;
}
void signals_all() 
{
	this_thread::sleep_for(1s);
	{
		unique_lock<mutex> lk(cv_m);
		cout << "无条件变量改变的唤醒" << endl;
		cv.notify_all();
	}
	this_thread::sleep_for(1s);
	{
		unique_lock<mutex> lk(cv_m);
		i = 1;
		cout << "带条件变量改变的唤醒操作" << endl;
		cv.notify_all();
	}
}
void testNotify_all() 
{
	thread t1(waits_thread,1), t2(waits_thread,2), t3(waits_thread,3);
	thread t4(signals_all);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
int main() 
{
	//testNotifyOne();
	testNotify_all();
	return 0;
}