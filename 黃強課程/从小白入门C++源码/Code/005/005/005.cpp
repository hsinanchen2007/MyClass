#include <iostream>
using namespace  std;

int main()
{
	//单字节字符，1个字节
	char  a = 'A'; 
	//宽字节字符,两个字节
	wchar_t b = L'B';
	wchar_t  c = L'中'; 

	cout << a << "   " <<sizeof( a )<< endl; 
	//宽字符输出用wcout
	wcout << b << "   " << sizeof(b) << endl; 
	//默认Locale是EN_US， 需设置为chs
	wcout.imbue(locale("chs"));
	wcout << c << "   " << sizeof(c) << endl;



	//布尔值只有两种0   1
	bool   b1 = true;
	bool   b2 = false;
	bool   b3 = 0;//0为假
	bool   b4 = -1;//非0为真

	//布尔类型占1个字节
	cout << "size: "<<sizeof(b1) << endl;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b4 << endl;



	//扩展8字节的数据
	long  c1 = 4294967296;//2的32次方
	cout << sizeof(c1) <<"  "<< c1 << endl;
	long long c2= 4294967296;//2的 64次方
	cout << sizeof(c2) << "  " << c2 << endl;


	//auto类型
	auto   d1 = 99;
	auto   d2 = 'B';
	auto   d3 = L'C';
	auto   d4 = 1.23f;
	auto   d5 = &d1;

	//auto    d6;//需要初始值

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