#include<iostream>
using  namespace  std;

class  A
{
public:

	//构造函数
	A(char * str)
	{
		int len = strlen(str) + 1;
		p = new  char[len];
		memcpy(p, str, len);
	}

	void  print()
	{
		cout << p << endl;
	}


	//自定义的拷贝构造函数- 深拷贝
	A(const  A  &  a1)
	{
		int len = strlen(a1.p) + 1;
		p = new char[len];
		memcpy(p, a1.p, len);
	}


	char *p;//指针变量 

};




int  main()
{
	//调用构造函数
	A  a("hello");
	a.print();

	A   b(a);//浅拷贝： 调用默认的拷贝构造函数，仅仅值拷贝，相当于 b.p= a.p;
	            //深拷贝：使用自定义的拷贝构造函数，相当于进行了内存的拷贝
	b.print();

	strcpy(a.p, "world");
	a.print();

	//此刻b中p的值也被改变了，很明显是错误。
	b.print();

	 
	return 0;
}