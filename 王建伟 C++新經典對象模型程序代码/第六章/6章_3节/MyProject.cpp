// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A::A()缺省构造函数执行了" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行了" << endl;
	}
	int m_i; 	
};

void myfunc()
{
	A obja; //obja定义在这里并不合适
	if (1 == 1)
	{
		//这里会被编译器插入调用obja对象析构函数的代码，影响执行效率完全没必要
		return;
	}
	//A obja; //obja定义在这里才合适
	//这里才会用到obja对象，所以obja对象定义在这里才会合适
	obja.m_i = 10;
	cout << "obja.m_i的值为" << obja.m_i << endl;
	return;
}

A g_aobj;

int main()
{
	/*{
		A obja;
	}*/
	//{
	//	A obja;
	//	int mytest = 1;
	//	if (mytest == 0)
	//	{
	//		return 0;
	//	}
	//	//myfunc();
	//}

	g_aobj.m_i = 6; //没有问题


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
