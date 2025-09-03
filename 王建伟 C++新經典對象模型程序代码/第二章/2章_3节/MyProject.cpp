// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>

using namespace std;

class A
{
public:
	int a;
	A()
	{
		printf("A::A() 的 this指针是：%p!\n", this);
	}
	void funA() { printf("A::funcA: this = %p\n", this); }

};

class B
{
public:
	int b;
	B()
	{
		printf("B::B() 的 this指针是：%p!\n", this);
	}
	void funB() { printf("B::funcB: this = %p\n", this); }

};

class C : public A, public B
{
public:
	int c;
	C()
	{
		printf("C::C() 的 this指针是：%p!\n", this);
	}
	void funC() { printf("C::funcC: this = %p\n", this); }
	void funB() { printf("C::funcB: this = %p\n", this); } //定义在C类中
};


int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	C myc;
	myc.funA();
	myc.funB();
	myc.B::funB();
	myc.funC();


	
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
