#include<iostream>
using namespace std;

//typedef  string  T;


//����ģ��
 template  <typename  T>//�������ظ�����T
 inline  T  sum(T  a, T  b)//inline�ؼ��ֲ���д��templateǰ��
{
    //typedef  string  T;//�ŵ�ģ�������������󣬲�����T����

	//�����T�������ĸ���
	T  tmp = a + b;
	return  tmp;
}

//��ʾ������Ͳ���,���岻��
template  <typename  T1, typename T2,  class  T3 >//ÿ�����Ͳ���ǰ������class����typename
T3  sum(T1  a, T2  b)
{
	T3  tmp = a + b;
	return  tmp;
}


void main()
{
 
	//ģ�庯��

	//������ͺ���
    int  a= 	sum<int>(111, 999);
	cout << a << endl;
	 
	//��������ͺ���
	float  b = sum<float>(1.234f,  2.345f);
	cout << b << endl;

	//˫������ͺ���
	double  c= sum<double>(1.234f, 2.345f);
	cout << c << endl;


	//�ڶ��ֺ���ģ��
	double  d = sum<int ,float,double>(100, 2.345f);
	cout << d << endl;
 
}