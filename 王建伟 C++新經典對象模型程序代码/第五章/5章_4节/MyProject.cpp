// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class Base
{
public:
	void myfunc()
	{
		cout << "Base::myfunc()" << endl;
	}
	/*virtual void myvirfunc()
	{
		cout << "Base::myvirfunc()" << endl;
	}*/
	virtual void myvirfunc(int value = 1)
	{
		cout << "Base::myvirfunc(),value=" << value << endl;
	}


};
class Derive : public Base
{
public:
	void myfunc()
	{
		cout << "Derive::myfunc()" << endl;
	}
	//virtual void myvirfunc()
	//{
	//	cout << "Derive::myvirfunc()" << endl;
	//}
	virtual void myvirfunc(int value = 2)
	{
		cout << "Derive::myvirfunc(),value=" << value << endl;
	}


};
class Derive2 : public Base
{
public:
};

class A 
{
public:
	virtual void myvirfunc() {}
};


int main()
{	
	//{
	//	Base base;   //静态类型是Base
	//	Derive derive; //静态类型是Derive
	//	Base* pbase;  //别管指向啥，反正定义的时候定义的是Base *，所以静态类型是Base *
	//	Base* pbase2 = new Derive();//静态类型依旧是Base *
	//	Base* pbase3 = new Derive2();//静态类型依旧是Base *
	//}

	{
		Derive derive;
		Derive* pderive = &derive;
		pderive->myfunc();   //Derive::myfunc()
		
		Base* pbase = &derive;
		pbase->myfunc();   //Base::myfunc(),这里调用的居然是父类的myfunc，是个陷阱，写程序时一定要注意

		Base base;
		pderive->myvirfunc(); //Derive::myvirfunc()
		pbase->myvirfunc();   //Derive::myvirfunc()
		pbase = &base;
		pbase->myvirfunc();   //Base::myvirfunc()
	}

	{
		A* pa = new A();
		pa->myvirfunc(); //这是不是多态，是多态的

		A a;
		a.myvirfunc(); //这个就不是多态的

		A* ya = &a;
		ya->myvirfunc(); //这个也是多态

	}
	{
		Base* pbase2 = new Derive(); //释放内存请读者自行释放，笔者在这里没演示
		pbase2->myvirfunc(); //Derive::myvirfunc()

	}

	{
		Derive derive2;
		Base& yinbase = derive2;
		yinbase.myvirfunc(); //Derive::myvirfunc()
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
