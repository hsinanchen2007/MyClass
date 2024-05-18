#include<iostream>
using namespace std;


//��ģ��
template <typename T1, typename  T2>
class A
{
private:
	T1  a1;
	T2   a2;
public:
	void print()
	{
		cout << "A <T1,T2>: print!" << endl;
	}
};

//���ȫ�ػ�,�ṹ����ģ������һ�£� ��ͽ�˽�˶���
template <>
class A<int ,float>
{

public:
	void print()
	{
		cout << "A <int,float>: print!" << endl;
	}

	void show()
	{
		cout << "A <int,float>: show!" << endl;
	}
};


//���ȫ�ػ�,�ṹ����ģ������һ�£� ��ͽ�˽�˶���
template <>
class A<float, float>
{

public:  
	void show()
	{
		cout << "A <int,float>: show!" << endl;
	}
};


//���ƫ�ػ�
template <typename  T1>
class A<T1, float>
{
public:
	void show()
	{
		cout << "A <T1,float>: show!" << endl;
	}
};


//������ģ��
template <typename T1, typename T2>
void  test(T1  a, T2  b)
{
	cout << "test<T1,T2>��" << endl;
}

//������ȫ�ػ�
template <>
void  test(int  a,  int  b)
{
	cout << "test<int,int>��" << endl;
}


//����û��ƫ�ػ�����Ϊ���˺�������
template <typename T1>
void  test(T1  a, double  b)
{
	cout << "test<T1,char>��" << endl;
}

void main()
{
	//��ͨ��
	A<int, int> a;
	a.print();
	//a.show();//û�������Ա��������������ػ�������

	//��ȫ�ػ���
	A<int, float> a2;
	a2.print();
	a2.show();

	A<float, float> a3;
	//a3.print();//û�������Ա��������������ػ�������
	a3.show();


	//ƫ�ػ�
	A< char, float> a4;
	a4.show();


	//��ͨ�ĺ���ģ��
	test<int, float>(1,2.0f);

	//ȫ�ػ���ģ��
	test<int, int>(1, 2);

	//����ƫ�ػ�
	test<int, double>(1,1.234);
}