#include<iostream>
using namespace  std;


class A;//ǰ������

class B
{public:	//ֻ��������ʵ��	void  print(A  a); 

};


class  A
{

public:
	//������ĳ�Ա����Ϊ��Ԫ����
	friend  void  B::print(A   a);

	A()
	{
		a = 100;
	}

private:
	int  a; //˽�г�Ա
};

//ֻ�а����Ա������ʵ�ַŵ�A����ĺ��棬���ܹ�ʶ��A
void  B::print(A  a)
{
	cout << a.a << endl;//��ĳ�Ա��������A˽�г�Ա
}
 

int  main()
{
	A   a;
	B   b;
	b.print(a);

	return 0;
}