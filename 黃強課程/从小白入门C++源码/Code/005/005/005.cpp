#include <iostream>
using namespace  std;

int main()
{
	//���ֽ��ַ���1���ֽ�
	char  a = 'A'; 
	//���ֽ��ַ�,�����ֽ�
	wchar_t b = L'B';
	wchar_t  c = L'��'; 

	cout << a << "   " <<sizeof( a )<< endl; 
	//���ַ������wcout
	wcout << b << "   " << sizeof(b) << endl; 
	//Ĭ��Locale��EN_US�� ������Ϊchs
	wcout.imbue(locale("chs"));
	wcout << c << "   " << sizeof(c) << endl;



	//����ֵֻ������0   1
	bool   b1 = true;
	bool   b2 = false;
	bool   b3 = 0;//0Ϊ��
	bool   b4 = -1;//��0Ϊ��

	//��������ռ1���ֽ�
	cout << "size: "<<sizeof(b1) << endl;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b4 << endl;



	//��չ8�ֽڵ�����
	long  c1 = 4294967296;//2��32�η�
	cout << sizeof(c1) <<"  "<< c1 << endl;
	long long c2= 4294967296;//2�� 64�η�
	cout << sizeof(c2) << "  " << c2 << endl;


	//auto����
	auto   d1 = 99;
	auto   d2 = 'B';
	auto   d3 = L'C';
	auto   d4 = 1.23f;
	auto   d5 = &d1;

	//auto    d6;//��Ҫ��ʼֵ

	int  e[2][3];

	auto   d6 = e;

	cout << typeid(d1).name() << endl;
	cout << typeid(d2).name() << endl;
	cout << typeid(d3).name() << endl;
	cout << typeid(d4).name() << endl;
	cout << typeid(d5).name() << endl;
	cout << typeid(d6).name() << endl;


	return 0;
}