#include<iostream>
using namespace  std;

class  A
{
public:

	int  a; 
};

//����̳�
class B :  virtual   public  A
{
public:
	B()
	{
		a = 200;
	}
};

//����̳�
class C :  virtual public  A
{
public:
	C()
	{
		a = 300;
	}
};
 

class  D : public  B, public  C
{

};

int  main()
{
	 
	D  d;
	//B��C�ж���a��Ա������  D�̳�BCʱ������a����������
	//cout << d.a << endl;

	//�������һ����ȷ���ã����Ƕ��a
	cout << d.B::a << endl;
	cout << d.C::a << endl;


	//����������������
	cout << d.a << endl;//�˿�ֻ��һ��a����


	return 0;
}