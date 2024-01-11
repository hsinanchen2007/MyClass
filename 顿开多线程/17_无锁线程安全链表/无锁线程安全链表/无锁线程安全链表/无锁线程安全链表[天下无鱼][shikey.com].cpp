/*
	compare_exchange_weak(oldValue,newValue)
	��ǰֵ������ֵ ���ʱ�� �޸ĵ�ǰֵΪ����ֵ������true
	��ǰֵ������ֵ ����ʱ�� ������ֵ�޸ĵ�ǰֵ������false
	һ����ѭ����ʹ�ã���Ȼ����Ҫʹ��strong�汾
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
