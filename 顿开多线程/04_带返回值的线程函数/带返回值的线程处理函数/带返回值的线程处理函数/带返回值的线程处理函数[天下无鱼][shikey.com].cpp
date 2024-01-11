#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;
int returnValue() 
{
	return 100;
}
/*
	第一步:采用async：启动一个异步任务,(创建线程，并且执行线程处理函数),返回值future对象
	第二步:通过future对象中get()方法获取线程函数返回值
*/
//No.1 带返回值的普通函数充当线程处理函数
int testThreadOne() 
{
	return 1001;
}
//No.2 带返回值的类的成员函数充当线程处理函数
class MM 
{
public:
	int mmThread(int num) 
	{
		cout << "MMthread_id:" << this_thread::get_id() << endl;
		num *= 2;
		chrono::milliseconds duration(5000);
		this_thread::sleep_for(duration);
		return num;
	}
};
void testAsync() 
{
	future<int>  result = async(testThreadOne);
	cout << result.get() << endl;
	MM mm;
	auto  temp = async(&MM::mmThread, &mm, 1999);
	cout << temp.get() << endl;
	//async的其他参数
	//launch::async			:  创建线程，执行线程处理函数
	//launch::deferred		:  线程处理函数延迟到 我们调用wait和get方法时候才会执行，本质是没有创建子线程
	auto testDerred = async(launch::deferred, &MM::mmThread,&mm,1000);
	cout << testDerred.get() << endl;
	auto testAsyncParam = async(launch::async, &MM::mmThread, &mm, 100);
}
//No.3 用thread处理带返回值的线程处理函数
//1.通过类模板  packaged_task 包装线程处理函数
//2.通过packaged_task的对象调用get_future获取future对象，再通过get()方法得到子线程处理函数的返回值
void testPackaged_task() 
{
	//No.1 打包普通函数
	packaged_task<int(void)> taskOne(testThreadOne);
	thread  testOne(ref(taskOne));
	testOne.join();
	cout << taskOne.get_future().get() << endl;
	MM mm;
	//No.2 打包类的成员函数
	packaged_task<int(int)> taskTwo(bind(&MM::mmThread, &mm, placeholders::_1));
	thread testTwo(ref(taskTwo), 20);
	testTwo.join();
	cout << taskTwo.get_future().get() << endl;
	//No.3 打包Lambda表达式
	packaged_task<int(int)> taskThree([](int num)
		{
			cout << "thread_id:" << this_thread::get_id() << endl;
			num *= 10;
			return num;
		});
	thread testThree(ref(taskThree), 7);
	testThree.join();
	cout << taskThree.get_future().get() << endl;
}

//No.4 promise 获取线程处理函数"返回值" 
//第一步:通过promise类模板构建对象,通过调用set_value 是存储函数需要返回的值
//第二步:通过get_future获取future对象，再通过get()方法获取线程处理函数中值
void testPromiseThread(promise<int>& temp, int data)
{
	cout << "thread_id" << this_thread::get_id() << endl;
	data *= 3;
	temp.set_value(data);
}
void testPromiseToThread(future<int>& temp) 
{
	int num = temp.get();
	cout << num << endl;
}
void testPromise() 
{
	promise<int> temp;
	thread testp(testPromiseThread, ref(temp), 18);
	testp.join();
	cout << temp.get_future().get() << endl;
	//temp.set_value(888);
	promise<int> data;
	data.set_value(999);
	auto num = data.get_future();
	thread test(testPromiseToThread, ref(num));
	test.join();
}

int main() 
{
	thread t1(returnValue);
	t1.join();
	//testAsync();
	//testPackaged_task();
	testPromise();
	return 0;
}