#include <thread>
#include <iostream>
using namespace std;
//No.1 ��ͨ�䵱�̴߳����������߳�
void print() 
{
	cout << "�̴߳���������.....";
	cout << endl;
}
void test1() 
{
	thread t1(print);
	t1.join();
}
//No.2 ����Lambda���ʽ�䵱�̴߳�����
void test2()
{
	thread t1([]() {cout << "Lambda���ʽ�䵱�̴߳�����" << endl; });
	t1.join();
}
//No.3 ���κ��������߳�
//3.1 ��ͨ����
void printData(const int num) 
{
	cout << "id:" << num << endl;
}
void test3() 
{
	int num = 1;
	thread t1(printData, num);
	t1.join();
}
//3.2 ������
void printReference(int& num) 
{
	num = 1001;
	cout << "���߳�:" << num << endl;
}
void test4() 
{
	int num = 0;
	thread t1(printReference, ref(num));			//ref:��װ������Ϊ���ݵ�ֵ
	t1.join();
	cout << "���߳�:" << num << endl;
}
//3.3 ����ָ�뵱������
void printPtr(unique_ptr<int> ptr) 
{
	cout << "����ָ��:" << *ptr.get() << endl;
}
void test5() 
{
	unique_ptr<int> ptr(new int(100));
	cout<<"test5:" << ptr.get() << endl;
	thread t1(printPtr, move(ptr));
	t1.join();
	cout << "test5:" << ptr.get() << endl;
}
//No.4 ͨ�����еĳ�Ա����ȥ����
//4.1 �º�����ʽ:�����ķ�ʽ����
class Function 
{
public:
	void operator()()
	{
		cout << "����()" << endl;
	}
};
void test6()
{
	//����
	Function object;
	thread t1(object);
	t1.join();
	//��������
	thread t2((Function()));
	t2.join();
}
//4.2 ��ͨ���еĳ�Ա����
class MM 
{
public:
	void print(int& id) 
	{
		cout << "id:" << id << endl;
	}
};
void test7() 
{
	MM mm;
	int id = 1;
	thread t1(&MM::print, mm, ref(id));
	t1.join();
}

int main() 
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}