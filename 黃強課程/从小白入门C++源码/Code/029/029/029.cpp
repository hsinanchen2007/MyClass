#include<iostream>
using  namespace  std;
 
class  A
{
public: 
	A()
	{
		cout << "自定义默认的构造函数！" << endl;
	}


	~A()
	{
		//做清理扫尾工作
		cout << "自定义的析构函数！" << endl;
	}


};


int  main()
{
	A  a;//a创建的时候构造，销毁的时候析构

	A   *p = new  A;//调用构造函数
   delete p;//调用析构函数



	return 0;
}