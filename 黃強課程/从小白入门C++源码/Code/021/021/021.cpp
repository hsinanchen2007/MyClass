#include<iostream>
using  namespace  std;
 
class A
{
public:
	//�Զ�����вι��캯��
	explicit   A(int a) //����explicit�ؼ��֣���ֹ��ʽת��
	{ 
		this->a = a;
	}

	void  print()
	{
		cout << a << endl;
	}

private:
	int   a;
};


int  main()
{ 
	//��׼��д���������вι��캯��
	A   a(111);
	a.print();

	//�ڶ���д��, �������Զ���ʽ������ת����A������Ϊ���캯����int����
	A   a2 = 222;
	a2.print();


	return 0;
}