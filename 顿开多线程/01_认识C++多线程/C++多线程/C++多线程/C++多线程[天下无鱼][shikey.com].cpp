/*
	No.1 并发
	两个或者多个独立活动同时发生(一个程序执行多个独立的任务)
	并发假象: 单核CPU通过上下文的方式实现进程并发
	No.2 进程
	计算机中的程序关于数据集合上的一次运行活动
	No.3 线程
	每个进程都有一个主线程，并且主线程是唯一的，每一个进程只有一个线程
	线程: 就是一个代码的运行通道
	No.4 并发实现
		4.1 多个进程实现并发
			主要解决进程间通信问题：
				同一台电脑上行，主要提供过管道，文件，消息队列，内存共享实现
				不同电脑主要网络编程实现
		4.2 单进程，多个线程实现并发
			一个进程中所有线程共享内存空间的方式
			资源竞争
	No.5 C++中的多线程
	   5.1 #include <thread>
	   5.2 创建线程，线程处理函数
	   5.3 创建线程未做任何处理，调用abort终止我们的程序
	   5.4 join(): 加入/汇合线程，阻塞主线程
	   5.5 detach(): 分离 驻留后台
	   5.6 对于同一个线程，join 和detach只能做一次
	   5.7 joinable() 判断当前线程时候可以被join与detach ，如果可以返回true，不可以返回false
*/
#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;
void print() 
{
	cout << "干活..." << endl;
}
void printData() 
{
	Sleep(5000);
	cout << "睡觉....." << endl;
}
int main() 
{
	thread t1(printData);
	//t1.join();
	if(t1.joinable())
		t1.detach();
	//t1.join();
	print();
	return 0;
}