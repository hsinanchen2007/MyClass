#include<iostream>
using namespace  std;


//���ؼ̳з�ʽһ
class  A
{
public:
	A(int  a1)
	{
		cout << "A���캯����" << endl;
		a = a1;
	}
public:
	int  a;
};


class  B  
{
public:
	B(int  b1) 
	{
		cout << "B���캯����" << endl;
		b = b1;
	}
public:
	int  b;
};

class  C : public A ,  public  B //����AB˳���������˳��
{
public:
	//�ó�ʼ���б��츸��������Ĺ��캯��
	C(int  a1, int b1, int  c1) : A(a1 ) , B(b1)//����AB˳������ν
	{
		cout << "C���캯����" << endl;
		c = c1;
	}
public:
	int  c;
};




int  main()
{

	C   c(111, 222, 333);

	cout << c.a << c.b << c.c << endl;


	return  0;
}