#include<iostream>
using namespace  std;

//定义sum函数模板
template<typename T>
T  sum(T  a, T  b)
{
	return  a + b;
}

int  main()
{
	//int求和的模板函数
	cout << sum<int>(111, 222) << endl;

	//float求和的模板函数
	cout << sum<float>(1.234f, 4.567f) << endl;

	//double求和的模板函数
	cout << sum<double>(1.234, 4.567) << endl;


	return 0;
}