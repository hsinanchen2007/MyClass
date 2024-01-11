#include <new>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
template <class T>
class threadsafe_queue
{
private:
	struct node
	{
		shared_ptr<T> data;
		unique_ptr<node> next;
	};
	//FIFO
	mutex head_mutex;
	unique_ptr<node> head;		//表示整个队列的容量(链表)
	mutex tail_mutex;
	node* tail;
	node* get_tail()
	{
		lock_guard<mutex> tail_lock(tail_mutex);
		return tail;
	}
	unique_ptr<node> pop_head() 
	{
		lock_guard<mutex> head_lock(head_mutex);
		if (head.get() == get_tail()) 
		{
			return nullptr;
		}
		unique_ptr<node> old_head = move(head);
		head = move(old_head->next);
		return old_head;
	}
public:
	threadsafe_queue() :head(new node), tail(head.get()) {}
	threadsafe_queue(const threadsafe_queue& other) = delete;
	threadsafe_queue& operator=(const threadsafe_queue& other) = delete;
	void push(T new_value) 
	{
		shared_ptr<T> new_data(make_shared<T>(move(new_value)));
		unique_ptr<node> p(new node);
		node* const new_tail = p.get();
		lock_guard<mutex> tail_lock(tail_mutex);
		tail->data = new_data;
		tail->next = move(p);
		tail = new_tail;
	}
	shared_ptr<T> try_pop() 
	{
		unique_ptr<node> old_head = pop_head();
		return old_head ? old_head->data : shared_ptr<T>();
	}
};
void insertData(threadsafe_queue<int>& test, int data) 
{
	test.push(data);
}
void deleteData(threadsafe_queue<int>& test) 
{
	shared_ptr<int> result = test.try_pop();
	if (result == nullptr) 
	{
		printf("queue is mepty!!!\n");
	}
	else 
	{
		printf("%d\n", *result);
	}
}
int main() 
{
	vector<thread> t;
	threadsafe_queue<int> test;
	for (int i = 0; i < 5; i++) 
	{
		t.push_back(thread(insertData, ref(test), i));
		t.push_back(thread(deleteData, ref(test)));
	}
	for (auto &v: t) 
	{
		v.join();
	}
	return 0;
}