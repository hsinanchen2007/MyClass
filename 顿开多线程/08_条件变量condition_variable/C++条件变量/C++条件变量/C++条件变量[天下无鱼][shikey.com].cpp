#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
/*
	condition_variable��
	1.����wait���� �����߳�
	2.unique_lock �����߳�
	3.notify_one notify_all �����߳�
*/
condition_variable cv;
mutex cv_m;
int i = 0;				//������������
bool done = false;		//�䵱����

void waits_one() 
{
	unique_lock<mutex> lk(cv_m);
	cout << "�ȴ���...." << endl;
	cv.wait(lk, [] {return i == 1; });
	cout << "���н���..." << endl;
	done = true;
}
void signals_one() 
{
	this_thread::sleep_for(1s);
	cout << "���������������Ѳ���" << endl;
	cv.notify_one();

	unique_lock<mutex> lk(cv_m);
	i = 1;
	while (!done) 
	{
		cout << "������������Ļ��Ѳ���" << endl;
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
	//�����ڶ�������߳�ʱ��notify_one ����� �������⡣�����ǲ��ȶ�
}
void waits_thread(int id)
{
	unique_lock<mutex> lk(cv_m);
	cout <<id <<":�ȴ���...." << endl;
	cv.wait(lk, [] {return i == 1; });
	//this_thread::sleep_for(chrono::seconds(id));
	cout<<id << ":���н���..." << endl;
	done = true;
}
void signals_all() 
{
	this_thread::sleep_for(1s);
	{
		unique_lock<mutex> lk(cv_m);
		cout << "�����������ı�Ļ���" << endl;
		cv.notify_all();
	}
	this_thread::sleep_for(1s);
	{
		unique_lock<mutex> lk(cv_m);
		i = 1;
		cout << "�����������ı�Ļ��Ѳ���" << endl;
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