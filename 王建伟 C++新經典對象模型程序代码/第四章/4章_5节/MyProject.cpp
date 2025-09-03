// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

//class FAC  //父类
//{
//public:
//	int m_fai;
//	int m_faj;
//};
//class MYACLS : public FAC  //子类
//{
//public:
//	int m_i;
//	int m_j;
//};

//class Base
//{
//public:
//	int m_i1;
//	char m_c1;
//	char m_c2;
//	char m_c3;
//};

class Base1
{
public:
	int m_i1;
	char m_c1;
};

class Base2 :public Base1
{
public:
	char m_c2;
};

class Base3 :public Base2
{
public:
	char m_c3;
};


int main()
{
	/*{
		printf("MYACLS::m_i = %d\n", &FAC::m_fai);
		printf("MYACLS::m_i = %d\n", &FAC::m_faj);
		printf("MYACLS::m_i = %d\n", &MYACLS::m_fai);
		printf("MYACLS::m_i = %d\n", &MYACLS::m_faj);
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

	}

	{
		FAC facobj;
		MYACLS myaclobj;
	}*/

	/*{
		cout << sizeof(Base) << endl;

		printf("Base::m_i1 = %d\n", &Base::m_i1);
		printf("Base::m_c1 = %d\n", &Base::m_c1);
		printf("Base::m_c2 = %d\n", &Base::m_c2);
		printf("Base::m_c3 = %d\n", &Base::m_c3);

	}*/

	{
		cout << sizeof(Base1) << endl; //8
		cout << sizeof(Base2) << endl; //12
		cout << sizeof(Base3) << endl; //16
	}
	{
		printf("Base3::m_i1 = %d\n", &Base3::m_i1);
		printf("Base3::m_c1 = %d\n", &Base3::m_c1);
		printf("Base3::m_c2 = %d\n", &Base3::m_c2);
		printf("Base3::m_c3 = %d\n", &Base3::m_c3);
	}

	Base3 aaa;
	aaa.m_c2 = 5;
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
