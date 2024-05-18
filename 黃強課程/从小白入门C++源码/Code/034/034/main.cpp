#include<iostream>
using  namespace  std;
 



void    fun2()
{
	static   int n = 0;//3. 静态存储区的变量，只初始化一次，生命周期为整个程序期间
	cout << ++n << endl;
}


//4.修饰成员变量和函数，使其变成静态的成员，属于所有对象公有的
class A
{
public:
	//静态成员函数
	static  void  print()
	{
		cout << "静态成员函数！" << endl;
	}
private:
	static  int  a;//静态成员变量  
};


int  main()
{
	
	extern  int  a;//只是声明
	//cout << a << endl;

	extern  void fun();//函数的声明
	//fun();



	//fun2调用3次
	fun2();
	fun2();
	fun2();


	//用类名调用静态方法
	A::print();

	return 0;
}