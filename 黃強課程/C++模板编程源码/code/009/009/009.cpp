#include<iostream>
using namespace  std;

 //T1,T2,T3�������Ͳ���,�����������Ǵ������Ͳ���
template <typename T1, typename T2, typename T3>
T3   sum(T1  a, T2  b)
{
	T3 tmp = a + b;
	return tmp;
}

void  main()
{
	//  ���Ͳ��� ����Ķ������ͣ�����int, float ,double
	sum<int, float, double>(111,1.234f);

}