#include <iostream>
#include <future>
#include <thread>
using namespace  std;
using namespace  std::this_thread;
using namespace  std::chrono;
 
//费时操作
void  work1(promise<int> &prom, int  a, int b)
{
	cout << "work1开始计算：" << endl;
	sleep_for(seconds(3));
	prom.set_value(a+b);
}

int  work2( int  a, int b)
{
	cout << "work2开始计算：" << endl;
	sleep_for(seconds(2));
	return a + b;
}

int  work3(int  a, int b)
{
	cout << "work3开始计算：" << endl;
	sleep_for(seconds(2));
	return a + b;
}



int main()
{ 
	//promise内部包装了一个值
	promise<int>  prom;
	future<int> f1 = prom.get_future();//使用get_future成员函数获取future
	thread(work1, ref(prom), 1, 2).detach();
	f1.wait();//等待值设置
	cout<<"计算结果："<<f1.get()<<endl;//获取结果


	//packaged_task包装一个操作
	packaged_task<int(int, int)>  task(work2);
	future<int> f2 = task.get_future();//使用get_future成员函数获取future
	thread(move(task), 11, 22).detach();
	f2.wait();//等待结果
	cout << "计算结果：" << f2.get() << endl;//获取结果


	//async内部是一个线程
	future<int> f3 = async(work3,111,222);
	f3.wait();//等待结果
	cout << "计算结果：" << f3.get() << endl;//获取结果
}