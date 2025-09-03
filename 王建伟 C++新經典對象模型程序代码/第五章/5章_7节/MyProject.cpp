// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

//
//class Base
//{
//public:
//	virtual void f() { cout << "Base::f()" << endl; }
//	virtual void g() { cout << "Base::g()" << endl; }
//	virtual void h() { cout << "Base::h()" << endl; }
//
//	virtual ~Base()
//	{
//		cout << "Base::~Base()" << endl;
//	}
//
//public:
//	virtual Base* clone() const
//	{
//		return new Base();
//	}
//
//};
//
//class Base2
//{
//public:
//	virtual void hBase2() { cout << "Base2::hBase2()" << endl; }
//
//	/*~Base2()
//	{
//		cout << "Base2::Base2()" << endl;
//	}*/
//
//	virtual ~Base2()
//	{
//		cout << "Base2::~Base2()" << endl;
//	}
//
//public:
//	virtual Base2* clone() const
//	{
//		return new Base2();
//	}
//
//};
//
//class Derive : public Base, public Base2 {
//public:
//	virtual void i() { cout << "Derive::i()" << endl; }
//	virtual void g() { cout << "Derive::g()" << endl; }
//	void myselffunc() {} //只属于Derive的函数
//
//	virtual ~Derive()
//	{
//		cout << "Derive::~Derive()" << endl;
//	}
//
//public:
//	virtual Derive* clone() const
//	{
//		return new Derive();
//	}
//
//};

class Base
{
public:
	virtual void f() {}
	virtual ~Base() {}

	int m_basei;
};

class Derive :public virtual Base
{
public:
	virtual ~Derive() {}

	int m_derivei;
};


int main()
{	
	//{
	//	Base2* pb2 = new Derive();
	//	delete pb2;  //这里调用了Derive类的虚析构函数

	//}
	//{
	//	Derive* pd2 = new Derive();
	//	pd2->hBase2();
	//	cout << "断点设置在这里" << endl;
	//}
	//{
	//	Derive* pd2 = new Derive();
	//	cout << "断点设置在这里" << endl;
	//}
	//{
	//	Base2* pb1 = new Derive();
	//	Base2* pb2 = pb1->clone(); //执行Derive::clone()
	//	cout << "断点设置在这里" << endl;
	//}

	//{
	//	cout << sizeof(Derive) << endl;  //16
	//	Derive dobj;
	//	dobj.m_basei = 2;   //13-16字节
	//	dobj.m_derivei = 5; //5-8字节
	//	Derive* pdobj = new Derive();
	//	pdobj->f();

	//}

	/*{
		Base* pbase = new Derive();
		pbase->m_basei = 6;
	}*/

	{
		Derive* pderive = new Derive();
		Base* pbase2 = (Base*)pderive;
		pbase2->m_basei = 7;

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
