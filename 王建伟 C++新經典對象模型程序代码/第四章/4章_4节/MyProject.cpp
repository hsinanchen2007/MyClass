// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class FAC
{
public:
	int m_fai;
	int m_faj;
};


//class MYACLS 
class MYACLS : public FAC
{
public:
	int m_i;
	static int m_si; //这是声明不是定义
	int m_j;

public:
	void myfunc()
	{
		m_i = 5;
		m_j = 6;
	}	
};
int MYACLS::m_si = 0; //这才是定义


int main()
{

	{
		MYACLS myobj;
		MYACLS* pmyobj = new MYACLS();
		cout << MYACLS::m_si << endl;
		cout << myobj.m_si << endl;
		cout << pmyobj->m_si << endl;

		MYACLS::m_si = 1;
		myobj.m_si = 2;
		pmyobj->m_si = 3;

		printf("myobj.m_i = %p\n", &myobj.m_i);
		printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
		printf("MYACLS::m_si = %p\n", &MYACLS::m_si);
		printf("MYACLS::m_si = %p\n", &myobj.m_si);
		printf("MYACLS::m_si = %p\n", &pmyobj->m_si);

		pmyobj->myfunc();

		printf("MYACLS::m_i = %d\n", &MYACLS::m_i); //0
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j); //4

		pmyobj->m_faj = 7;  //给父类的成员变量赋值

		//cout << "设置断点" << endl;
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
