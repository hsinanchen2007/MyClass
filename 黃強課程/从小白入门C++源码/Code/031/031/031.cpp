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

	A(const  A  &  a1)
	{
		a = a1.a;
		cout << "�����Զ��忽�����캯����" << endl;
	}

	void print()
	{
		cout << a << endl;
	}

	//�Զ���=��ֵ��������غ���
	A   &  operator = (const A  &a1)
	{
		if (this == &a1)//�Լ���ֵ�Լ�
		{
			return *this;//ֱ�ӷ����Լ�
		}

		a = a1.a;//���и�ֵ
		cout << "�Զ���=��ֵ��������غ���" << endl;
		return   *this;//���ض�����
	}


private:
	int  a;
};


int  main()
{
	A  a(111);//�����вεĹ��캯��

	A     b(a);//���ÿ������캯�� 
	A    c = a;//���ÿ������캯��


	A   e(222);//�����вεĹ��캯��

	//��ʵ�ϣ�������Ĭ�ϵ� =��������غ���, �����˸�ֵ
	a = e;//û�е��ÿ������죬���ʱ�򣬶���û�з������죬a��͹������
	a.print();

	a = a;//�Լ���ֵ���Լ�
	a.print();

	return 0;
}