#include<iostream>
using namespace std;

//�ⲿ��ģ��
template<typename T1>
class  Outer
{
public:
	//�ڲ���ģ��
	template<typename T2>
	class  Inner
	{
	public:
		T2   i;
		void print();
	};


public:
	T1 o;
	void  print(); 
};


template<typename T>
void Outer<T>::print()
{
	cout << "Outer print!" << endl;
}
  
//��Ҫ���������޶�,ͬʱ��Ҫ����ģ������
template<typename T1>
template<typename T2>
void Outer<T1>::Inner<T2>::print()
{
	cout << "Inner print!" << endl;
}



void main()
{
	//�ⲿ��
	Outer<int>  o;
	o.print();

	//�ڲ��� 
	Outer<int>::Inner<float> i;//ͬ������::�������޶���
	i.print();

}