#include<iostream>
using  namespace  std;
 

class  A
{
public:
	A(int  a1)
	{
		a = a1;
		cout << "�����Զ��幹�캯����" << endl;
	}

	//���������
	A   operator  +(const A  & a1)
	{
		return  A(a + a1.a);
	}


	void print()
	{
		cout << a << endl;
	}


private:
	int  a;
};


int  main()
{
 
	A  a(111);//�����вι��캯��
	A  b(222);//�����вι��캯��

	//����������ĺ�,  +�����������
	A   c = a + b;//�����вι��캯��
	c.print();

	return 0;
}