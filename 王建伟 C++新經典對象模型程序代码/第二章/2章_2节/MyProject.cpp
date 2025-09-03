// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成   ，内含优质视频教程，欢迎关注

#include <iostream>

using namespace std;
//class A
//{
//	int a = 100;
//};
//class A
//{
//	static int a;
//	static int b;
//};

//class A
//{
//	static void sfunc() {};
//	void myfunc() {};
//};

class A
{
	virtual void myfunc3() {};
	virtual void myfunc4() {};	
};

class myobject
{
public:
	myobject() {}; //构造函数
	virtual ~myobject() {}; //析构函数

	float getvalue() const //普通成员函数
	{
		return m_value;
	}
	static int s_getcount() //静态成员函数
	{
		return ms_scount;
	}
	virtual void vfrandfunc() {}; //虚函数

protected:
	float m_value; //普通成员变量 
	static int ms_scount; //静态成员变量
};


int main()
{
	//{
	//	A aobj;  //sizeof(aobj)=4
	
	//{
	//	A aobj;  //sizeof(aobj)=1,不管几个静态成员变量，sizeof的大小不增加
	//	std::cout << sizeof(aobj) << std::endl;
	//}

	//{
	//	A aobj;  //sizeof(aobj)=1
	//	std::cout << sizeof(aobj) << std::endl;
	//}
	//{
	//	int ilen2 = sizeof(char*); //4
	//	int ilen3 = sizeof(int*); //4
	//}
	{
		myobject obj;
		int ilen = sizeof(obj);
		cout << ilen << endl;
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
