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
 


	//�Զ����const���ε�&��������غ���
	//1.ǰһ��const������ָ�򳣶����ָ��
	//2.��һ��const, ��ʾ��һ������Ա������  ������ֻ�ܵ��ó���Ա����
	const   A  *  operator  &()  const
	{
		cout << "�Զ����const���ε�&��������غ���" << endl;
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
 

	//������
	const  A  a2(222);
	//ʵ���ϵ�����ϵͳĬ���ṩ�Ĵ�const���ε�& ��������غ���
	cout << &a2 << endl;

	return 0;
}