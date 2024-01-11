#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;
//No.1 获取线程id
void threadFunc() 
{
	cout << "id:" << this_thread::get_id() << endl;
	using namespace this_thread;
	cout << "id:" << get_id() << endl;
}
//No.2 sleep_for 延时函数
void threadSleep_for() 
{
	cout << "Sleep_for_id:" << this_thread::get_id() << "启动" << endl;
	this_thread::sleep_for(2s);
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Sleep_for_id:" << this_thread::get_id() << "结束" << endl;
}
//No.3 yield 让线程放弃执行 ，让操作系统调用另一个线程执行
void threadYield(chrono::microseconds duration)
{
	cout << "Yield id:" << this_thread::get_id() << "启动" << endl;
	auto startTime = chrono::high_resolution_clock::now();
	auto endTime = startTime + duration;
	do 
	{
		this_thread::yield();
		cout << 1 << endl;
	} while (chrono::high_resolution_clock::now() < endTime);
	cout << "Yield id:" << this_thread::get_id() << "结束" << endl;
}
//No.4 阻塞线程 知道sleep_time溢出
void threadSlee_until() 
{
	//this_thread::sleep_until(chrono::system_clock::from_time_t(100));
	time_t t = chrono::system_clock::to_time_t(chrono::system_clock::now());
	tm* ptm = new tm;
	localtime_s(ptm, &t);
	if (ptm != nullptr) 
	{
		this_thread::sleep_until(chrono::system_clock::from_time_t(mktime(ptm)));
	}
	cout << put_time(ptm, "%X") << endl;
}
int main() 
{
	cout << "id:" << this_thread::get_id() << endl;
	thread test(threadYield, chrono::microseconds(100));
	test.detach();
	thread t1(threadFunc);
	t1.join();
	thread t2(threadSleep_for);
	t2.join();
	threadSlee_until();
	return 0;
}