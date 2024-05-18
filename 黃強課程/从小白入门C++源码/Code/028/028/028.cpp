#include<iostream>
using  namespace  std;

class  A
{
public:

	A(int  a1)
	{
		a = a1;
		cout << "自定义的有参构造函数！"<<endl;
	}


	A( )
	{
		a = 100;
		cout << "自定义的默认构造函数！" << endl;
	}

	void  print()
	{
		cout << a << endl;
	}

	void  setValue(int  a1)
	{
		a = a1;
	}
	 
private:
	int  a;
};



int  main()
{

	//1.定义对象数组,并初始化
	A   arr[3] = { A(111) , A(222) , A(333) };


	//2.先定义对象数组
	A   arr2[3];//需要默认构造函数，否则报错
	//后赋值
	arr2[0].setValue(444);
	arr2[1].setValue(555);
	arr2[2].setValue(666);


	//遍历对象数组
	for (int i = 0; i < 3; ++i)
	{
		arr[i].print();
	}

	for (int i = 0; i < 3; ++i)
	{
		arr2[i].print();
	}

	return 0;
}