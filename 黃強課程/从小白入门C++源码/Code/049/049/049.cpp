#include<iostream>
using namespace  std;
 
class  A
{
	//������Ԫ��
	friend  class  B;

public: 
	A()
	{
		a = 100;
	}

private:
	int  a; //˽�г�Ա
};

 
class  B
{
public:

	//��ΪA����Ԫ����
	void  print(A  a)
	{
		cout << a.a << endl;
	}

	//��ΪA����Ԫ��������&�����ı�a�ĳ�Ա����
	void  setValue(A &  a,  int  a2)
	{
		a.a= a2;
	}
	 
};



int  main()
{

	A  a;
	B  b;

	//�����������A��˽�г�Ա
	b.setValue(a, 200);
	b.print(a);
 

	return 0;
}