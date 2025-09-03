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
	void myfunc(int abc) 
	{		
		//m_i += abc;
		mystfunc(); //这绝对没有问题
	}
	virtual void myvirfunc()
	{
		printf("myvirfunc()被调用,this = %p\n", this);
		//myvirfunc2();
		MYACLS::myvirfunc2();
	}
	virtual void myvirfunc2()
	{
		printf("myvirfunc2()被调用,this = %p\n", this);
	}
	static void mystfunc() 
	{
		printf("mystfunc()被调用\n");
	}

};

//全局函数gmyfunc
void gmyfunc(MYACLS* ptmp, int abc)
{
	ptmp->m_i += abc;
}


int main()
{	
	/*{
		MYACLS  myacls;
		myacls.myvirfunc();
		MYACLS* pmyacls = new MYACLS;
		pmyacls->myvirfunc();
		delete pmyacls;
	}*/
	   	 	
	{
		MYACLS  myacls;
		myacls.mystfunc();
		MYACLS* pmyacls = new MYACLS;
		pmyacls->mystfunc();
		((MYACLS*)0)->mystfunc();  //这样调用静态成员函数没问题
		((MYACLS*)0)->myfunc(12);
		pmyacls->mystfunc();
		printf("MYACLS::mystfunc()地址 = %p\n", MYACLS::mystfunc);
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
