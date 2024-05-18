#include<iostream>
using  namespace  std;


class  Student
{
public:
	int  age;//年龄

	void  ListenClass()
	{
		cout << "听课！" << endl;
	}  
};


int  main()
{
	Student   stu;//定义一个类的对象

	//对象用 .   访问公有成员变量与成员函数
	stu.age = 18;
	stu.ListenClass();

	//定义类指针
	Student  *  pStu = &stu;//赋值为类变量（对象）的地址

	//对象指针用 ->  访问公有成员变量与成员函数
	cout << pStu->age << endl;
	pStu->ListenClass();

	 
	return 0;
}