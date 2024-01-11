#include <thread>
#include <mutex>
#include <iostream>
#include <stack>
#include <vector>
#include <exception>
using namespace std;
//�쳣����
struct empty_stack :public exception
{
	const char* what() const noexcept 
	{
		return "stack is empty !!!";
	}
};
//��װ�̰߳�ȫջ
template <class T>
class threadsafe_stack
{
private:
	mutable mutex m;
	stack<T> data;
public:
	//���캯��
	threadsafe_stack() {  }
	threadsafe_stack(const threadsafe_stack& other)
	{
		lock_guard<mutex> lock(other.m);	//��������
		data = other.data;
	}
	threadsafe_stack& operator=(const threadsafe_stack&) = delete;
	//����ͺ���
	bool empty() const 
	{
		lock_guard<mutex> lock(m);
		return data.empty();
	}
	size_t size() const
	{
		lock_guard<mutex> lock(m);
		return data.size();
	}
	//��ȡ����
	void push(T value) 
	{
		lock_guard<mutex> lock(m);
		data.push(move(value));
	}
	void pop(T& value) 
	{
		lock_guard<mutex> lock(m);
		if (data.empty())
			throw empty_stack();
		value = move(data.top());
		data.pop();
	}
};
//��װ�̴߳�����
void insertData(threadsafe_stack<int>& stack, int value) 
{
	stack.push(value);
}
void deleteData(threadsafe_stack<int>& stack) 
{
	try 
	{
		int value = 0;
		stack.pop(value);
		printf("data:%d\n", value);
	}
	catch (empty_stack re) 
	{
		printf("%s\n", re.what());
	}
}
int main() 
{
	vector<thread> t;
	threadsafe_stack<int> test;
	for (int i = 0; i < 5; i++) 
	{
		t.push_back(thread(insertData, ref(test), i));
		t.push_back(thread(deleteData, ref(test)));
	}
	for (auto& v : t) 
	{
		v.join();
	}
	cout << "size:" << test.size() << endl;
	return 0;
}

