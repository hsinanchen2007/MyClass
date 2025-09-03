// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>
#include <time.h>
#include <cstdio>

#include "mytemplate.h"

using namespace std;

//template class ATPL<double>;
template void ATPL<double>::func2() const;

//
//template<class T>
//T funadd(const T& a, const T& b)
//{
//	T addhe = a + b;
//	return addhe;
//}
//
//template<class T>
//class ATPL
//{
//public:
//	enum ECURRSTATUS
//	{
//		E_CS_Busy,
//		E_CS_Free,
//	};
//
//
//public:
//	T m_i, m_j;
//	ATPL(T tmpi = 0, T tmpj = 0) //构造函数
//	{
//		m_i = tmpi;
//		m_j = tmpj;
//	}
//
//public:
//	static int m_sti;
//	static T m_sti2;
//
//public:
//	void func1() const { cout << "ATPL::func1()" << endl; }
//	void func2() const { cout << "ATPL::func2()" << endl; }
//
//
//};
//
//template <class T> 	int ATPL<T>::m_sti = 10;
//template <class T> 	T ATPL<T>::m_sti2 = 10;

void myfunc()
{
	ATPL<int> myobj;
	myobj.m_sti2 = 18;
	cout << myobj.m_sti2 << endl;
}


int main()
{
	//{
	//	cout << funadd(12, 14) << endl;
	//}
	//{
	//	ATPL<int>::ECURRSTATUS myenum;  //注意要加这个<int>
	//	myenum = ATPL<int>::E_CS_Busy;

	//	ATPL<int>::ECURRSTATUS myenum2;
	//	myenum2 = ATPL<int>::E_CS_Free;

	//	ATPL<double>::ECURRSTATUS myenum3;
	//	myenum3 = ATPL<double>::E_CS_Free;

	//}

	/*{
		ATPL<int>::m_sti = 18;
		cout << ATPL<int>::m_sti << endl;

		ATPL<float>::m_sti = 21;
		cout << ATPL<float>::m_sti << endl;

		ATPL<int>::m_sti2 = 132;
		ATPL<float>::m_sti2 = 1050;
		cout << ATPL<int>::m_sti2 << endl;
		cout << ATPL<float>::m_sti2 << endl;		
	}*/

	//{
	//	//ATPL<int>* pobj = NULL;
	//}
	//{
	//	const ATPL<int>& yobj = 0; //因为构造函数允许缺省参数，这里有隐式类型转换
	//	//cout << sizeof(ATPL<int>) << endl;
	//	yobj.func1();
	//}


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
