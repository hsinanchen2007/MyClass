#include<iostream>
using  namespace  std;

 
class  A
{
public:
	//�������Ͳ�ͬ
	void  print(int  a)
	{
		cout <<"print(int  a)  "<< a << endl;
	}
	//�������Ͳ�ͬ
	void  print(char  a)
	{
		cout << "print(char  a)  " << a << endl;
	}

	//�����޷����ؽ�������ֵ��ͬ�ĺ���
	/*
	int  print(char  a)
	{
		cout << "print(char  a)  " << a << endl;
	}
	*/


	//�������Ͳ�ͬ
	void  print(float  a)
	{
		cout << "print(float  a)  " << a << endl;
	}

	//����������ͬ
	void  print(int  a,int  b)
	{
		cout << " print(int  a,int  b) " << a <<b<< endl;
	}
	 

};


int  main()
{
 
	A  a;

	//ͬһ�����������ݺ������أ��Զ�ƥ��
	a.print(123);
	a.print('A');
	a.print(1.234f);
	a.print(111, 222);



	return 0;
}