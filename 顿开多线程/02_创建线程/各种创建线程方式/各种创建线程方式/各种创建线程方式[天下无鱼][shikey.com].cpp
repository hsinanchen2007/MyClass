#include <thread>
#include <iostream>
using namespace std;
//No.1 普通充当线程处理函数创建线程
void print() 
{
	cout << "线程处理函数启动.....";
	cout << endl;
}
void test1() 
{
	thread t1(print);
	t1.join();
}
//No.2 采用Lambda表达式充当线程处理函数
void test2()
{
	thread t1([]() {cout << "Lambda表达式充当线程处理函数" << endl; });
	t1.join();
}
//No.3 带参函数创建线程
//3.1 普通参数
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
//3.2 传引用
void printReference(int& num) 
{
	num = 1001;
	cout << "子线程:" << num << endl;
}
void test4() 
{
	int num = 0;
	thread t1(printReference, ref(num));			//ref:包装引用作为传递的值
	t1.join();
	cout << "主线程:" << num << endl;
}
//3.3 智能指针当做函数
void printPtr(unique_ptr<int> ptr) 
{
	cout << "智能指针:" << *ptr.get() << endl;
}
void test5() 
{
	unique_ptr<int> ptr(new int(100));
	cout<<"test5:" << ptr.get() << endl;
	thread t1(printPtr, move(ptr));
	t1.join();
	cout << "test5:" << ptr.get() << endl;
}
//No.4 通过类中的成员函数去创建
//4.1 仿函数形式:类名的方式调用
class Function 
{
public:
	void operator()()
	{
		cout << "重载()" << endl;
	}
};
void test6()
{
	//对象
	Function object;
	thread t1(object);
	t1.join();
	//匿名对象
	thread t2((Function()));
	t2.join();
}
//4.2 普通类中的成员函数
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