#include<iostream>
using namespace  std;
 

class  A
{
public:
	void  print()
	{
		cout << "A" << endl;
	}
};

class  B
{
private:
	A  a;//������Ϊ��Ա���������˼�룬�����˼��
public:
	void  print()
	{
		cout << "B" << endl;
		a.print();
	}
};


template <typename  T>
class A1
{
public:
	void print();
};

template <typename T>
void A1<T>::print()
{
	cout << "A1" << endl;
}


//��������������ܱ�ʾT�Ǹ�ģ��
template <    template <typename X> typename     T  >
class B1
{
private:
	T<int>   a;//��ҪT��һ��ģ�壬��������дT<int>
public:
	void print();
};



template < template <typename X> typename   T>
void B1<T>::print()
{
	cout << "B1" << endl;
	a.print();
}




void  main()
{
	B b;
	b.print();

	//��ҪT��һ��ģ�壬��ģ��ʵ����
	B1<A1>  b1;
	b1.print();

}