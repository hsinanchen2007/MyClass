// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class JI
{
public:
	JI()
	{
		cout << "JI::JI()缺省构造函数执行了" << endl;
	}

public:
	virtual ~JI() 
	{
		cout << "JI::~JI()析构函数执行了" << endl;
	}
};


//class A
class A :public JI
{
public:
	int m_i, m_j;

//private:
//	A& operator=(const A& tmp);
//	A(const A& tmptime);

//public:
//	A& operator=(const A& tmp) = delete;
//	A(const A& tmptime) = delete;
public:
	A& operator=(const A& tmp)
	{
		m_i = tmp.m_i;
		m_j = tmp.m_j;
		cout << "A::operator=(const A&)拷贝赋值运算符执行了" << endl;
		return *this;
	}
	A(const A& tmptime) 
	{
		m_i = tmptime.m_i;
		m_j = tmptime.m_j;
		cout << "A::A(const A&)拷贝构造函数执行了" << endl;
	}
	A()
	{
		cout << "A::A()缺省构造函数执行了" << endl;		
	}
public:
	~A()
	{
		cout << "A::A()析构函数执行了" << endl;
	}
};

class ParC
{
public:
	virtual ~ParC()
	{
		cout << "ParC::~ParC()虚析构函数执行了" << endl;
	}
};
class MemC
{
public:
	ParC m_j;

public:
	~MemC()
	{
		cout << "MemC::~MemC()析构函数执行了" << endl;
	}
};

int main()
{
	//{
	//	A aobj;
	//	aobj.m_i = 15;
	//	aobj.m_j = 20;

	//	A aobj2 = aobj; //执行拷贝构造

	//	A aobj3;
	//	aobj3.m_i = 13;
	//	aobj3.m_j = 16;
	//	aobj2 = aobj3;	//执行拷贝复制运算符

	//	cout << "设置断点" << endl;
	//}
	/*{
		A aobj;
	}*/

	/*{
		MemC mobj;
	}*/

	{
		A aobj;
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
