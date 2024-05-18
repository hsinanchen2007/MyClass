#include<iostream>
using namespace  std;

 
//定义自定义的C++标准异常类
class  MyException : public  exception
{
public:
	//构造函数初始化列表来构造基类
	MyException(const char *p):exception(p)
	{
	}
};


int  main()
{
	/*
	//放可能出现异常的代码
	try
	{
		cout << "开头代码" << endl;

		int  a = 10;
		int  b = 0;
		int  c = a / b;//除0异常，从此处停止执行

		cout << "结尾代码" << endl;
	}
	catch (...)
	{
		cout << "捕获到异常，进行处理！" << endl;
	}
	*/


	/*
	try
	{
		cout << "开头代码" << endl;

		//throw  "字符错误";//抛出字符串类型的异常
		//throw  1000;//抛出整型类型的异常
		//throw   1.234f;//抛出浮点型类型的异常

		throw  1.456;//被默认的捕获

		cout << "结尾代码" << endl;
	}
	catch (const char  * p)
	{
		cout << "捕获到异常："<<p << endl;
	}
	catch (int   p)
	{
		cout << "捕获到异常：" << p << endl;
	}
	catch (float   p)
	{
		cout << "捕获到异常：" << p << endl;
	}
	catch (...)
	{
		cout << "捕获到异常，进行处理！" << endl;
	}
	*/



	/*
	try
	{
		for (int i = 0; i < 1000; ++i)
		{
			//会产生标准C++异常： bad_alloc异常
			new  int[1000000];
		}
	}
	catch (const exception&  e) //exception是C++标准异常类的基类
	{
		cout << e.what() << endl;
	}
	*/


	try
	{
		throw  MyException("自定义的C++标准异常！");
	}
	catch (const exception&  e)
	{
		cout << e.what() << endl;
	}


 
	return 0;
}