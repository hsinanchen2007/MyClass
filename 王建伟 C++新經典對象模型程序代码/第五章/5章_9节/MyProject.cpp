// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

__int64  mytest(int mv)
{
	int i = 0;
	__int64 icout = 0;
	for (int i = 1; i <= 1000000; i++)
	{
		icout += 1;
		if (i == 10000 && mv == 999)
		{
			printf("---\n");
		}
	}
	return icout;
}

class A
{
public:
	A()
	{
		cout << "A::A()" << endl;
	}
public:
	virtual void myvirfunc() {}
};

class A1
{
public:
	A1()
	{
		cout << "A1::A1()" << endl;
	}

};


class B :public A
//class B :public A, public A1
{
public:
};

class C : public B
{
public:
	C()
	{
		cout << "C::C()" << endl;
	}
};

int main()
{	
	//{
	//	clock_t start, end;  //记得包含头文件#include <ctime>
	//	__int64 mycount = 1;
	//	start = clock();
	//	for (int i = 1; i <= 1000; i++)
	//	{
	//		mycount += mytest(6);			 //参数如果是固定值，那么就很快，参数如果是一个i可变值就很慢
	//		//mycount += mytest(i); //参数如果是固定值，那么就很快，参数如果是一个i可变值就很慢
	//	}
	//	end = clock();
	//	cout << "用时(毫秒):" << end - start << endl;
	//	cout << "mycount = " << mycount << endl;
	//}

	{
		C c;
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
