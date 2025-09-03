// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

class Base
{
public:
	int ba;
	int bb;
	Base(int tmpa, int tmpb) //构造函数
	{
	}
};

class CSub
{
public:
	CSub(int tmpvalue)
	{

	}
};


class A :public Base
{
public:
	int m_x;
	int m_y;
	int &m_yy;
	const int m_myc;
	CSub cmysub;
	//A() :m_x(0), m_y(0)
	//{
	//}
	//A(int &tmpvalue):m_yy(tmpvalue), m_myc(tmpvalue)

	A(int& tmpvalue) :m_yy(tmpvalue), m_myc(tmpvalue), Base(tmpvalue, tmpvalue), cmysub(tmpvalue)
	{
		//m_yy = tmpvalue; //错误，不可以，必须在初始化列表中进行绑定
		m_x = 0;
		m_y = 0;
		m_yy = 160;	//就等于修改外界的abc变量值
	}

};

class X
{
public:
	int m_i;
	X(int value = 0) :m_i(value) //类型转换构造函数
	{
		printf("this = %p", this);
		cout << "X类的X(int)构造函数被调用" << endl;
	}
	X(const X& tmpv)
	{
		printf("this = %p", this);
		cout << "X类的拷贝构造函数被调用" << endl;
	}
	X& operator=(const X& tmpTime)
	{
		printf("this = %p", this);
		cout << "X类的拷贝赋值运算符被调用" << endl;
		return *this; //返回一个该对象的引用
	}
	~X()
	{
		printf("this = %p", this);
		cout << "X类的析构函数被调用" << endl;
	}
};

class XA
{
public:
	X  xobj;
	int m_test;
	int m_test2;  //定义在后面，则后得到值
	//XA(int tmpvalue)
	//XA(int tmpvalue) : xobj(1000)
	XA(int tmpvalue) :xobj(1000), m_test2(500), m_test(m_test2)
	{
		//xobj = 1000;
		m_test = 500;
	}
};

int main()
{
	
	/*{
		int abc = 1;
		A a(abc);
	}*/
	{
		XA myaobj(1000);
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
