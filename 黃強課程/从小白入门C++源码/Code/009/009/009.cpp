#include<iostream> 
using  namespace  std;//ʹ��std���ֿռ��µ����б���

int   a = 100;

namespace  A
{
	int  a = 200;
	int   b = 300;

	namespace  B//���ֿռ��Ƕ��
	{
		int  b = 400;
		int  z = 900;
	}


	namespace  B//�����ظ����������ռ䣬�൱������
	{
		int  m= 800; 
	}

	//namespace  E;//���󣬲���Ƕ������
}

namespace  C
{
	int  a = 500;
	int  b = 600;


	//���������ֿռ�
	namespace
	{
		int   c=1000;
	}
}
 
int  main()
{

	cout << a << endl;
	cout << A::a<< endl;
	cout << C::a << endl;


	cout << A::b << endl;
	cout << C::b << endl;

	cout << A::B::b << endl;

	//ʹ��B���ֿռ��µ����б���
	using  namespace A::B;
	cout << b << endl;//��ֱ��ʹ�ã�����ǰ׺
	cout << z << endl;
	cout << m << endl;

	//��ʾ�˼�ǰ׺��д�����������using  namespace  std�� �����ǰ׺std::cout
	std::cout << "hello!" << endl;



	//�����ռ�  A::B�ı���FF
	namespace   FF =   A::B; 
	cout << FF::z << endl;


	//ʹ�����������ֿռ�ı���
	cout << C::c << endl;

	return 0;
}