#include<iostream>
using namespace  std;

class  A
{
	//������Ԫ�������������˽�г�Ա����Ȩ
	friend  void  print(A   a);

public:
	A()
	{
		a = 100;
	}

private:
	int  a; //˽�г�Ա
};


void  print(A   a)
{
	//���󣬶����޷�������ı�����˽�г�Ա
	//����Ϊ��Ԫ�󣬼��ɷ���
	cout << "��Ԫ����"<<a.a << endl;
}


int  main()
{
 
	A   a;
	print(a);

	return 0;
}