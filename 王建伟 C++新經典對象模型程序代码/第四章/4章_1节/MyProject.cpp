// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;
//
//string myvar;  //定义全局量，字符串型
//
////定义一个类
//class A
//{
//public:
//	/*int myfunc()	
//	{
//		return myvar;
//	}*/
//	int myfunc();
//private:
//	int myvar; //同全局量同名的成员变量
//};
//
//int A::myfunc()
//{
//	return myvar;
//	//return ::myvar;
//}
//
//int  myfunc()
//{
//	return myvar;
//}

typedef string mytype;
class A
{
	typedef int mytype;
public:
	void myfunc(mytype tmpvalue);
	//void myfunc(mytype tmpvalue) //这个mytype是string类型
	//{
	//	m_value = tmpvalue;
	//}

private:
	//typedef int mytype;
	mytype m_value;	//这个mytype是int类型	
};

void A::myfunc(mytype tmpvalue) //这个mytype又变成了int类型，但若在类中定义myfunc，那么参数中出现的mytype是string类型
{
	m_value = tmpvalue;
}

void myfunc(mytype tmpvalue)//这个mytype就是string类型
{
	string mvalue = tmpvalue;
}


int main()
{

	

	
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
