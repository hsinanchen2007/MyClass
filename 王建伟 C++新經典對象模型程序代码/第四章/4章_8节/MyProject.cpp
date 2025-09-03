// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

//class Grand //爷爷类
//{
//public:
//	int m_grand;
//};
//class A1 : public  Grand 
//{
//public:
//};
//class A2 : public  Grand
//{
//public:
//};
//class C1 :public A1, public A2
//{
//public:
//};

class Grand //爷爷类
{
public:
	int m_grand;
};
class A1 : virtual public  Grand //注意这里用了virtual
{
public:
	int m_a1;
};
class A2 : virtual  public  Grand//注意这里用了virtual
{
public:
	int m_a2;
};
class C1 :public A1, public A2 //这里不需要virtual
{
public:
	int m_c1;
};


int main()
{
	
	//{
	//	cout << sizeof(Grand) << endl;
	//	cout << sizeof(A1) << endl;
	//	cout << sizeof(A2) << endl;
	//	cout << sizeof(C1) << endl;
	//}

	//{
	//	C1 c1;
	//	//c1.m_grand = 12; //这句编译时会报错
	//	c1.A1::m_grand = 5;
	//	c1.A2::m_grand = 8;


	//}

	//{
	//	C1 c1;
	//	c1.m_grand = 12; //这句编译时不会再报错
	//}
	
	{
		cout << sizeof(Grand) << endl;
		cout << sizeof(A1) << endl;
		cout << sizeof(A2) << endl;
		cout << sizeof(C1) << endl;
	}

	{
		A1 a1;
		A2 a2;
		cout << "设置断点" << endl;
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
