// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

class X
{
public:
	int m_i;
	int* p_mi; //整型指针，其他类型指针都可以，道理相同
	//X(const X& tmpx)
	//{
	//	//m_i = tmpx.m_i;
	//	cout << "X类的拷贝构造函数被调用" << endl;
	//}
	X(const X& tmpx)
	{
		p_mi = new int(100); //为指针类型成员变量单独分配内存
		memcpy(p_mi, tmpx.p_mi, sizeof(int));
		m_i = tmpx.m_i;
		cout << "X类的拷贝构造函数被调用" << endl;
	}

	X() 
	{
		m_i = 0;
		p_mi = new int(100);
		cout << "X类的构造函数被调用" << endl;
	}
	~X()
	{
		delete p_mi;
		cout << "X类的析构函数被调用" << endl;
	}
	//explicit X(int value) :m_i(value) //类型转换构造函数（带有一个形参的拷贝构造函数）
	X(int value) :m_i(value) //类型转换构造函数（带有一个形参的拷贝构造函数）
	{
		p_mi = new int(100);
		cout << "X类的X(int)构造函数被调用" << endl;
	}



};


int main()
{
	
	//{
	//	cout << "----begin----" << endl;
	//	X x10(1000);
	//	cout << "--------" << endl;
	//	X x11 = 1000;
	//	cout << "--------" << endl;
	//	X x12 = X(1000);
	//	cout << "--------" << endl;
	//	X x13 = (X)1000;
	//	cout << "----end----" << endl;

	//}

	//{
	//	//编译器视角
	//	X x10;   //编译器视角是不调用构造函数的
	//	x10.X::X(1000);
	//}
	//{
	//	//编译器视角
	//	X _tmp0;          //编译器生成的临时对象
	//	_tmp0.X::X(1000); //带一个参数的构造函数被调用
	//	X x12; 
	//	x12.X::X(_tmp0);  //拷贝构造函数被调用
	//	_tmp0.X::~X();    //调用析构
	//}
	
	{
		X x0;
		x0.m_i = 150;
		X x1(x0);
		cout << x1.m_i << endl;
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
