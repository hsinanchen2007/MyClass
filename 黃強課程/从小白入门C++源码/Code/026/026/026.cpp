#include<iostream>
using  namespace  std;

class  A
{
public:
	A(int  a1)
	{
		a = a1;
		cout << "���ù��캯����" << endl;
	}

	//�̶�д����������Ϊ�ǹ��캯��������
	A(const  A   & a1)
	{
		a = a1.a;
		cout << "���ÿ������캯����" << endl;
	}


	void print()
	{
		cout << a << endl;
	}

private:
	int a;
};


int  main()
{
	A  a(111);//�����вεĹ��캯��

	A   b(a);//�����ʱ���ö����ʼ�������ÿ������캯��
	A   c = a;//�����ʱ���ö����ʼ�������ÿ������캯��
 

	//��������ĳ�Ա����a��ֵһ��
	a.print();
	b.print();
	c.print();

	return 0;
}