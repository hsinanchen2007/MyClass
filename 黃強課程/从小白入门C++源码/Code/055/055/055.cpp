#include<iostream>
using namespace  std;

//����sum����ģ��
template<typename T>
T  sum(T  a, T  b)
{
	return  a + b;
}

int  main()
{
	//int��͵�ģ�庯��
	cout << sum<int>(111, 222) << endl;

	//float��͵�ģ�庯��
	cout << sum<float>(1.234f, 4.567f) << endl;

	//double��͵�ģ�庯��
	cout << sum<double>(1.234, 4.567) << endl;


	return 0;
}