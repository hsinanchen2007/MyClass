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
	 
	void print()
	{
		cout << a << endl;
	}

	//�Զ���&��������غ���
	A  *  operator  &()
	{
		cout << "�Զ���&��������غ���" << endl;
		return  this;//thisָ��ǰ����ĵ�ַ
	}
	  

private:
	int  a;
};


int  main()
{
 
	A  a(111);

	//ʵ���ϵ�����ϵͳĬ���ṩ��& ��������غ���
	cout << &a << endl;


	return 0;
}