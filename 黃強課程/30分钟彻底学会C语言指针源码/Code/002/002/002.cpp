#include<iostream>
using  namespace  std;

struct  A
{
	int a;
	int b; 
};

int  main()
{
	 
	//验证指针类型的本质
	cout << sizeof(unsigned  int) << endl;//占4个字节


	cout << sizeof(char *) << endl;//字符指针类型，占4个字节
	cout << sizeof(int*) << endl;//整型指针类型，占4个字节
	cout << sizeof(short*) << endl;//短整型指针类型，占4个字节
	cout << sizeof(float*) << endl;//浮点型指针类型，占4个字节
	cout << sizeof(double*) << endl;//浮点型指针类型，占4个字节
	cout << sizeof(A*) << endl;//结构体型指针类型，占4个字节

	//由此可以论证，32位系统下， 指针就是一个内存地址（无符号的32位的整数值）

	return 0;
}