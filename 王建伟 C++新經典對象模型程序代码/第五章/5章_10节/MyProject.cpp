// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>


using namespace std;


//将一个成员函数的地址转换成普通地址
template<typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
	return *static_cast<dst_type*>(static_cast<void*>(&src));
}
class TDF
{
public:
	void myf(int val)
	{
		cout << "myf()成员函数执行了" << endl;
	}
};

class A
{
public:
	void myfunc1(int tempvalue1)
	{
		cout << "tempvalue1 = " << tempvalue1 << endl;
	}
	void myfunc2(int tempvalue2)
	{
		cout << "tempvalue2 = " << tempvalue2 << endl;
	}
public:
	static void mysfunc(int tempvalue) 
	{ 
		cout << "A::mysfunc()静态成员函数执行了，tempvalue = " << tempvalue << endl; 
	}

public:
	virtual void myvirfuncPrev(int tempvalue) 
	{ 
		cout << "A::myvirfuncPrev()虚成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
	virtual void myvirfunc(int tempvalue) 
	{
		cout << "A::myvirfunc()虚成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
public:
	virtual ~A()
	{

	}
};

class B :public A
{
public:
	virtual void myvirfunc(int tempvalue) 
	{
		cout << "B::myvirfunc()虚成员函数执行了，tempvalue = " << tempvalue << endl; 
	}
	virtual ~B() 
	{
	}
};


int main()
{
	//{
	//	printf("TDF::myf的地址是%p\n", &TDF::myf);
	//	typedef void (*Func)();
	//	Func fun1 = pointer_cast<Func>(&TDF::myf);
	//	void* func2 = pointer_cast<void*>(&TDF::myf);
	//	fun1();  //把成员函数当普通函数调用
	//}

	{
		A mya;

		void (A:: * pmypoint)(int tempvalue) = &A::myfunc1; //定义一个成员函数指针并给初值
		pmypoint = &A::myfunc2; //给成员函数指针赋值

		//通过成员函数指针来调用成员函数
		(mya.*pmypoint)(15); //要使用成员函数指针来调用成员函数，必须要对象介入

		A* pmya = new A();
		(pmya->*pmypoint)(20); //用对象指针介入来使用成员函数指针 来调用成员函数
	}
	{
		void (*pmyspoint)(int tempvalue) = &A::mysfunc; //一个普通的函数指针，而不是成员函数指针
		pmyspoint(80); //从编译器角度看也是这个代码，不需要有个所谓的this指针

	}
	{
		void (A:: * pmyvirfunc)(int tempvalue) = &A::myvirfunc;

		A* pvaobj = new A;
		pvaobj->myvirfunc(190);
		(pvaobj->*pmyvirfunc)(190);
		printf("%p\n", &A::myvirfunc);

		pmyvirfunc = &A::myfunc2;
		(pvaobj->*pmyvirfunc)(33);

		cout << "断点行设置在这里" << endl;
	}

	{
		B* pmyb = new B();
		void (B:: * pmyvirfunc)(int tempvalue) = &A::myvirfunc;//成员函数指针
		//void (B:: * pmyvirfunc)(int tempvalue) = &B::myvirfunc;
		(pmyb->*pmyvirfunc)(190);

		printf("%p\n", &A::myvirfunc);
		printf("%p\n", &B::myvirfunc);

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
