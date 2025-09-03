// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class MYACLS
{
public:
	virtual void myvirfunc1()
	{
		cout << "虚函数MYACLS::myvirfunc1()执行了" << endl;
	}
	virtual void myvirfunc2()
	{
		cout << "虚函数MYACLS::myvirfunc2()执行了" << endl;
	}
};


int main()
{	
	{
		printf("MYACLS::myvirfunc()地址 = %p\n", &MYACLS::myvirfunc1);
		printf("MYACLS::myvirfunc()地址 = %p\n", &MYACLS::myvirfunc2);
		cout << sizeof(MYACLS) << endl;  //4字节
		MYACLS* pmyobj = new MYACLS();
		pmyobj->myvirfunc1();
		pmyobj->myvirfunc2();
		cout << "断点设置在这" << endl;
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
