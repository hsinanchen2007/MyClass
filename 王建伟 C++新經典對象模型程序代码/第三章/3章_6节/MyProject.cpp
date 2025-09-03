// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>

using namespace std;

class X
{
public:
	int x;
	int y;
	int z;
	/*X() :x(0), y(0), z(0)
	{
		cout << "X类的构造函数被执行" << endl;
	}*/
	X()
	{
		memset(this, 0, sizeof(X));
		cout << "X类的构造函数被执行" << endl;
	}

	/*X(const X& tm) :x(tm.x), y(tm.y), z(tm.z)
	{
		cout << "X类的拷贝构造函数被执行" << endl;
	}*/
	X(const X& tm)
	{
		memcpy(this, &tm, sizeof(X));
		cout << "X类的拷贝构造函数被执行" << endl;
	}
public:
	virtual ~X()
	{
		cout << "X类的析构函数被执行" << endl;
	}
	virtual void virfunc()
	{
		cout << "虚函数virfunc()执行了" << endl;
	}
	void ptfunc()
	{
		cout << "普通函数ptfunc()执行了" << endl;
	}

};


int main()
{
	//{
	//	X x0; //调用构造函数
	//	x0.x = 100;
	//	x0.y = 200;
	//	x0.z = 300;
	//	x0.virfunc();
	//	X x1(x0); //调用拷贝构造函数 
	//	cout << "x1.x=" << x1.x << " x1.y=" << x1.y << " x1.z=" << x1.z << endl;

	//}

	//{
	//	X* px0 = new X();
	//	px0->ptfunc();  //可以正常调用普通该函数
	//	px0->virfunc(); //无法正常调用该虚函数
	//	delete px0;     //无法正常调用析构函数
	//}

	//{
	//	int i = 9;
	//	printf("i的地址 = %p\n", &i); //会发现每次i的地址输出出来都不一样

	//	X x0;
	//	printf("ptfunc的地址 = %p\n", &X::ptfunc); //正常函数地址可以这样输出

	//	/*long* pvptr = (long*)(&x0);
	//	long* vptr = (long*)(*pvptr);
	//	printf("vptr[1] = %p\n",  vptr[1]); */

	//	x0.ptfunc();
	//	x0.virfunc(); //虚函数是可以正常调用的
	//	cout << "断点设置在这里" << endl;
	//}

	{
	/*	X* pX0 = new X();
		pX0->ptfunc();
		pX0->virfunc();*/

		X x1;
		X& x1y = x1; //引用		
		x1y.virfunc();//也报异常，因为虚函数表指针被清零导致无法找到虚函数表，从而也无法执行虚函数

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
