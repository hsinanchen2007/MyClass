#include<iostream>
using  namespace  std;
 
//����
class  A
{
public:
	A()
	{
		a = 100;
	}

	void  print()
	{
		cout << "A::print()" << endl;
	}

	int  a;//�ϰֵĲƲ�
};
 

//����
class  B : public  A
{
	//ʲô���������������
};


int  main()
{
	B   b;
	cout<<b.a<<endl;//ʹ�ø���ĳ�Ա����
	b.print();//ʹ�ø���ĳ�Ա����


	return 0;
}