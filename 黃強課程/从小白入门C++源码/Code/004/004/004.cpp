#include<iostream>
using namespace std;

struct A {};

int  main()
{
	//ֱ�������������
	cout<<typeid(int).name()<<endl;

	//ֱ�������������
	cout << typeid(A).name() << endl;

	//�������������
	char  c = 'A';
	cout << typeid(c).name() << endl;

	//������ʽ������
	cout << typeid(  1.23*45    ).name() << endl;

	//����ַ���������
	cout << typeid( "hello").name() << endl;

	//ָ������
	int *p =  NULL;
	cout << typeid( p ).name() << endl;

	//const����
	const char *p2 = NULL;
	cout << typeid(p2).name() << endl;



	return 0;
}