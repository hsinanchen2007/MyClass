#include<iostream>
using  namespace  std;


class   A
{
public:

	//1.�ڹ��캯�����ڳ�ʼ��
	/*
	A(int a, int b)
	{
		//  ��Ա����a �� b ���ﲢû�б���ֵ����Ϊ�����a��bȫ�������βΣ��ѳ�Ա����������
		a = a;
		b = b;
		cout << "�Զ����вι��캯����" << endl;
	}

	//�������һ��  �β����Ա��������ͬ����
	A(int a1, int b1)
	{
		a = a1;
		b = b1;
		cout << "�Զ����вι��캯����" << endl;
	}
	

	//�����������  ʹ��thisָ��
	A(int a, int b)
	{
		this->a = a;//��ȷ��ָ���Ƕ����Լ���a��b
		this->b = b;
		cout << "�Զ����вι��캯����" << endl;
	}
	*/

	//2.ʹ�ó�ʼ���б���г�Ա�����ĳ�ʼ��
	A(int a1, int b1):  b(b1), a(a1)
	{ 
		cout << "�Զ����вι��캯����" << endl;
	}
	 
	void  print()
	{
		cout << a<<"   " <<b<< endl; 
	}

private:
	int  a;//���մ˴��Ķ���˳���ʼ��
	int  b; 
};


int  main()
{
 
	A  a(111,222);
	a.print();

	return 0;
}