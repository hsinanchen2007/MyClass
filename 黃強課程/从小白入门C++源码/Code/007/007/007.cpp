#include<iostream> 
using namespace std;


//�������ã��������ʵ�εı���,ʵ���˺�ָ��һ����Ч��
void  swap(int  & a, int  &b)
{
	int  temp = a;
	a = b;
	b = temp;
}

int  main()
{

	int  a = 111;
	int & a1 = a ;// a1 ��a���������ͣ� ��a1����a�ı�����������ͬһ������

	cout << a << "," << a1 << endl;
	cout << &a << "," << &a1 << endl;//a��a1��ַһģһ������ͬһ������

	a1 = 222;//ͬʱ�ı�a��ֵ
	cout << a << "," << a1 << endl;


	int  b = 333;
	swap(a, b);
	cout << a << "," << b << endl;

	cout << a1 << endl;

	//int  &c;//�������ñ����ʼ��


	return 0;
}
