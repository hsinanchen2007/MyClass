#include<iostream>
using  namespace  std;

class  A
{
public:
	A(int a1)
	{
		a = a1;
	}
	//��ͨ��Ա����
	void  print1()
	{
		a = 200;
		cout << a << endl;
	}

	//����Ա����
	void  print2()  const
	{
		//a = 200;//����Ա�����в����޸��κγ�Ա������ֵ
		cout << a << endl;
	}

private:
	int  a;
};


int  main()
{
 
	const   A    a(111);// a�ǳ�����ֻ�ܵ��ó���Ա����
	a.print2();
	//a.print1();//���ܵ��÷ǳ���Ա����


	return 0;
}