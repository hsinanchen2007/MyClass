#include<iostream>
using namespace std;

//1.����ģ�����Ͳ���T��Ҳ������class T����
template<typename T>
class A
{
public:
	//2.ָ��iterator��һ������
	typename  T::iterator *  iter;  //������typename ����Ȼ���� 

};

class B
{
public:
	typedef   int     iterator;//��Ƕ����
};



void main()
{
	//ģ����
	A<B>  a;

	cout <<  typeid( a.iter ).name()<< endl;

}