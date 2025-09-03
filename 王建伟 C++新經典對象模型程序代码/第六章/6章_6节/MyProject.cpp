// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A::A()构造函数执行" << endl;
	}
	A(const A& tmpobj)
	{
		m_i = tmpobj.m_i;
		cout << "A::A()拷贝构造函数执行" << endl;
	}
	~A()
	{
		cout << "A::~A()析构函数执行" << endl;
	}

public:
	A& operator=(const A& tmpaobj)
	{
		cout << "A::operaotor=()拷贝赋值运算符执行" << endl;
		printf("tmpaobj的地址为%p\n", &tmpaobj);
		return *this; //返回一个该对象的引用
	}
public:
	int m_i;
};
A operator+(const A& obj1, const A& obj2)
{
	A tmpobj; //调用一次构造函数
//	printf("tmpobj的地址为%p\n", &tmpobj);

	//这里可以做一些加法计算
	//......
//	printf("---------\n");
	tmpobj.m_i = obj1.m_i + obj2.m_i;
	return  tmpobj; //执行后调用了一次拷贝构造函数，一次析构函数,说明有临时对象生成
}


int main()
{
	//{
	//	A myobj1; //调用一次构造函数
	//	printf("myobj1的地址为%p\n", &myobj1);
	//	A myobj2; //调用一次构造函数 
	//	printf("myobj2的地址为%p\n", &myobj2);

	//	//A resultobj = myobj1 + myobj2;
	//	A resultobj;
	//	resultobj = myobj1 + myobj2;
	//	printf("resultobj的地址为%p\n", &resultobj);
	//}

	//{
	//	A myobj1; //调用一次构造函数			
	//	A myobj2; //调用一次构造函数 					
	//	myobj1 + myobj2;
	//}

	{
		A myobj1; //调用一次构造函数			
		myobj1.m_i = 1;
		A myobj2; //调用一次构造函数 					
		myobj2.m_i = 2;
		printf("(myobj1 + myobj2).m_i = %d\n", (myobj1 + myobj2).m_i); //临时对象，打印其m_i值

		cout << "-------------begin" << endl;
		//if ((myobj1 + myobj1).m_i > 3 || (myobj1 + myobj2).m_i > 5)
		if ((myobj1 + myobj1).m_i > 1 || (myobj1 + myobj2).m_i > 5)
		{
			cout << "条件成立" << endl;
		}
		cout << "-------------end" << endl;
	}

	//{
	//	const char* p = (string("123") + string("456")).c_str(); //这就有问题，临时对象被摧毁了
	//	printf("p = %s\n", p); //无法打印正确结果，无效内存
	//	cout << "断点设置在这里" << endl;
	//}

	{
		string aaa = (string("123") + string("456"));
		const char* q = aaa.c_str();
		printf("q = %s\n", q);
	}
	{
		const string& aaa = (string("123") + string("456"));
		printf("aaa = %s\n", aaa.c_str());

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
