#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;
//����ȫqueue����
#if 0
void insertData(queue<int>& data, int num) 
{
	data.push(num);
}
void testQueue() 
{
	queue<int> data;
	for (int i = 0; i < 10; i++) 
	{
		thread t(insertData, ref(data), i);
		t.detach();
	}
	this_thread::sleep_for(1s);
	while (!data.empty()) 
	{
		cout << data.front() << " ";
		data.pop();
	}
	cout << endl;
}
#endif
//��װһ���̰߳�ȫ����

template <class T>
class thread_safe_queue
{
protected:
	mutable mutex mut;
	queue<T> data_queue;
	condition_variable data_cond;
public:
	thread_safe_queue() {}
	thread_safe_queue(thread_safe_queue const& other)
	{
		lock_guard<mutex> lk(other.mut);
		data_queue = other.data_queue;
	}
	void push(T new_value)
	{
		lock_guard<mutex> lk(mut);
		data_queue.push(new_value);
		data_cond.notify_one();			//�����߳�
	}
	//�ȴ��̴߳洢���ݽ���������һ�����ݵĳ���
	void wait_and_pop(T& value)
	{
		unique_lock<mutex> lk(mut);
		data_cond.wait(lk, [this] {return !data_queue.empty(); });
		value = data_queue.front();
		data_queue.pop();
	}
	shared_ptr<T> wait_and_pop() 
	{
		unique_lock<mutex> lk(mut);
		data_cond.wait(lk, [this] {return !data_queue.empty(); });
		shared_ptr<T> res(make_shared<T>(data_queue.front()));
		data_queue.pop();
		return res;
	}
	bool empty() const 
	{
		lock_guard<mutex> lk(mut);
		return data_queue.empty();
	}
};

void insertData(thread_safe_queue<int>& data, int num) 
{
	data.push(num);
}
void threadSafeQueue() 
{
	thread_safe_queue<int> data;
	for (int i = 0; i < 10; i++)
	{
		thread t(insertData, ref(data), i);
		t.detach();
	}
	this_thread::sleep_for(1s);
	int num = 0;
	while (!data.empty())
	{
		data.wait_and_pop(num);
		cout << num << " ";
	}
	cout << endl;
}

int main() 
{
	//testQueue();
	threadSafeQueue();
	return 0;
}
