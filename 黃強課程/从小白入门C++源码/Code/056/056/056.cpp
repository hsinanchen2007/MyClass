#include<iostream>
using namespace  std;
 

//������ģ��
template<typename T>
class Math
{
public:
	//�����ڲ�������
	T  Sum(T  a, T  b); 

	//������ڲ�����ʵ��
	T   Max(T  a, T  b)
	{
		return a > b ? a : b;
	}

private:
	T   a;//��Ա����

};

//����ⲿʵ�ֳ�Ա����
template<typename T>
T  Math<T>::Sum(T  a, T  b)
{
	return  a + b;
}


int  main()
{
 
	//int�͵�ģ����Math
	Math<int >  m1;
	cout << m1.Sum(111, 222) << endl;


	//float�͵�ģ����Math
	Math<float >  m2;
	cout << m2.Max(1.234, 4.567) << endl;

	return 0;
}