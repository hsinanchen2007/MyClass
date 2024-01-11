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
	��һ��:����async������һ���첽����,(�����̣߳�����ִ���̴߳�����),����ֵfuture����
	�ڶ���:ͨ��future������get()������ȡ�̺߳�������ֵ
*/
//No.1 ������ֵ����ͨ�����䵱�̴߳�����
int testThreadOne() 
{
	return 1001;
}
//No.2 ������ֵ����ĳ�Ա�����䵱�̴߳�����
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
	//async����������
	//launch::async			:  �����̣߳�ִ���̴߳�����
	//launch::deferred		:  �̴߳������ӳٵ� ���ǵ���wait��get����ʱ��Ż�ִ�У�������û�д������߳�
	auto testDerred = async(launch::deferred, &MM::mmThread,&mm,1000);
	cout << testDerred.get() << endl;
	auto testAsyncParam = async(launch::async, &MM::mmThread, &mm, 100);
}
//No.3 ��thread���������ֵ���̴߳�����
//1.ͨ����ģ��  packaged_task ��װ�̴߳�����
//2.ͨ��packaged_task�Ķ������get_future��ȡfuture������ͨ��get()�����õ����̴߳������ķ���ֵ
void testPackaged_task() 
{
	//No.1 �����ͨ����
	packaged_task<int(void)> taskOne(testThreadOne);
	thread  testOne(ref(taskOne));
	testOne.join();
	cout << taskOne.get_future().get() << endl;
	MM mm;
	//No.2 �����ĳ�Ա����
	packaged_task<int(int)> taskTwo(bind(&MM::mmThread, &mm, placeholders::_1));
	thread testTwo(ref(taskTwo), 20);
	testTwo.join();
	cout << taskTwo.get_future().get() << endl;
	//No.3 ���Lambda���ʽ
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

//No.4 promise ��ȡ�̴߳�����"����ֵ" 
//��һ��:ͨ��promise��ģ�幹������,ͨ������set_value �Ǵ洢������Ҫ���ص�ֵ
//�ڶ���:ͨ��get_future��ȡfuture������ͨ��get()������ȡ�̴߳�������ֵ
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