// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>

using namespace std;

class M0TX
{
public:
	M0TX()//默认构造函数
	{
		cout << "Ogood!" << endl;		
	}
};

class MATX
{
public:
	MATX() //默认构造函数
	{
		cout << "goodHAHAHA" << endl;
	}
};

class MBTXPARENT
{
public:
	MBTXPARENT()
	{
		cout << "MBTXPARENT()构造函数执行了" << endl;
	}
};

//class MBTX
//{
//public:
//	int m_i;
//	int m_j;
//
//	void funct()
//	{
//		cout << "Iamverygood" << endl;
//	}
//
//public:
//	//MATX ma;  //类类型成员变量
//	//M0TX m0; //注意定义顺序，先定义的ma，再定义的m0
//
//		
//	M0TX m0; //调换成员变量定义顺序
//	MATX ma;  //类类型成员变量
//};
//class MBTX:public MBTXPARENT
//{
//public:
//	int m_i;
//	int m_j;
//	
//	void funct()
//	{
//		cout << "Iamverygood" << endl;
//	}
//};

//class MBTX
//{
//public:
//	int m_i;
//	int m_j;
//
//	void funct()
//	{
//		cout << "Iamverygood" << endl;
//	}
//	virtual void mvirfunc() //虚函数
//	{
//		cout << "mvirfunc" << endl;
//	}
//};
class MBTX:public MBTXPARENT
{
public:
	int m_i;
	int m_j;

	MBTX() //缺省构造函数
	{
 		m_i = 15;
	}

	void funct()
	{
		cout << "Iamverygood" << endl;
	}
	virtual void mvirfunc() //虚函数
	{
		cout << "mvirfunc" << endl;
	}
};

class Grand //爷爷类
{
public:
};
class A : virtual public  Grand  //注意virtual 
{
public:
};
class A2 : virtual  public  Grand //注意virtual 
{
public:
};
class C :public A, public A2 //这里不需要virtual
{
public:
	C()  //默认 构造函数
	{
		cout << "C::C()默认构造函数执行了" << endl;
	}
};

class Time
{
public:
	Time() {
		cout << "C::C()默认构造函数执行了" << endl;
	}
	int Second{ 10 };
};

int main()
{
	//{
	//	MBTX myb;
	//}

	//{
	//	C cc; //生成C类对象
	//}
	Time mytime;
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
