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
	int m_i;
	int m_j;
	int m_k;
};

void myfunc(int MYACLS::* mempoint, MYACLS& obj)
{
	obj.*mempoint = 260; //注意写法
}


int main()
{
	{
		MYACLS myobj;
		myobj.m_i = myobj.m_j = myobj.m_k = 0;
		printf("myobj.m_i = %p\n", &myobj.m_i); //用对象名.成员变量名，这里输出成员变量的内存地址

		MYACLS* pmyobj = new MYACLS();
		printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
		printf("pmyobj->m_j = %p\n", &pmyobj->m_j);

		int* p1 = &myobj.m_i; //对象成员变量指针
		int* p2 = &pmyobj->m_j;
		*p1 = 15;
		*p2 = 30;
		printf("p1地址 = %p,p1值=%d\n", p1, *p1);
		printf("p2地址 = %p,p2值=%d\n", p2, *p2);



		cout << "打印成员变量偏移值---------------" << endl;
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i); //打偏移值用%d更容易看懂
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);



		//成员变量指针	
		int MYACLS::* mypoint = &MYACLS::m_j;
		printf("MYACLS::m_j偏移值 = %d\n", mypoint);

		mypoint = &MYACLS::m_i;
		printf("MYACLS::m_i偏移值 = %d\n", mypoint);

		myobj.*mypoint = 22;   //注意写法
		pmyobj->*mypoint = 19; //注意写法

		myfunc(mypoint, myobj);  //注意调用方法
		myfunc(mypoint, *pmyobj); //注意调用方法
		cout << "sizeof(mypoint) = " << sizeof(mypoint) << endl;  //也是4字节

		int MYACLS::*mypoint2;
		mypoint2 = 0;
		mypoint2 = NULL;
		
		//mypoint2 += 1; //语法错误，普通指针可以，但成员变量指针不可以 
		//mypoint2++; //语法错误
		//mypoint2 = ( (&MYACLS::m_i) + 1);//语法错误


		printf("mypoint2 = %d\n", mypoint2);
		
		int MYACLS::* mypoint10 = &MYACLS::m_i;
		if (mypoint == mypoint10) //本条件是成立的
		{
			cout << "条件成立" << endl;
		}

		cout << "断点设置在这里" << endl;
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
