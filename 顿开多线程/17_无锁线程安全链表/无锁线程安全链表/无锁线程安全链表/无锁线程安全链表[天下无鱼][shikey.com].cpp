/*
	compare_exchange_weak(oldValue,newValue)
	当前值与期望值 相等时， 修改当前值为设置值，返回true
	当前值与期望值 不等时， 讲期望值修改当前值，返回false
	一般在循环中使用，不然就需要使用strong版本
*/
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;
class threadsafe_list
{
protected:
	struct Node
	{
		int value;
		Node* next;
		Node(int data, Node* next) :value(data), next(next) {}
	};
	atomic<Node*> list_head;
public:
	void push_front(int data)
	{
		Node* oldHead = list_head;
		Node* newNode = new Node(data, oldHead);
		while (!list_head.compare_exchange_weak(oldHead, newNode)) 
		{
			newNode->next = oldHead;
		}
	}
	void printList() 
	{
		for (Node* it = list_head; it != nullptr; it = it->next) 
		{
			cout << it->value << " ";
		}
		cout << endl;
	}
	~threadsafe_list()
	{
		Node* it;
		while (it = list_head) 
		{
			list_head = it->next;
			delete it;
		}
	}
};
int main()
{
	vector<thread> t;
	threadsafe_list test;
	for (int i = 0; i < 5; i++) 
	{
		t.push_back(thread(&threadsafe_list::push_front, &test, i));
	}
	//2 3 4 0 1
	for (auto& v : t) 
	{
		v.join();
	}
	test.printList();
	return 0;
}
