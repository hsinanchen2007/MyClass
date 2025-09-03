// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;


class Base
{
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
};
//class Derive : public Base {
//public:
//	virtual void i() { cout << "Derive::i()" << endl; }
//	virtual void g() { cout << "Derive::g()" << endl; }
//	void myselffunc() {} //只属于Derive的函数
//};
class Derive : public Base {
public:	
};

class BCXu {
public:
	virtual void pvfunc() = 0;
};

int main()
{	
	//{
	//	Derive myderive;
	//	Derive* pmyderive = &myderive;
	//	//注意下列虚函数的调用顺序
	//	pmyderive->f();
	//	pmyderive->g();
	//	pmyderive->h();
	//	pmyderive->i();
	//	cout << "断点设置在这里" << endl;
	//}

	//{
	//	Base* pb = new Derive();  //基类指针指向一个子类对象
	//	pb->g();

	//	Derive myderive;
	//	Base& yb = myderive;      //基类引用引用的是 一个子类对象
	//	yb.g();
	//}
	{
		Derive a1;
		Derive a2;
		Derive* pa3 = new Derive();

		Base b1;

		cout << sizeof(Derive) << endl;
		cout << "断点设置在这里" << endl;
	}

	{
		cout << sizeof(Base) << endl;
	}

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
