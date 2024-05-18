#include<iostream> //cin，cout的头文件
#include <iomanip>// setw   setfill的头文件
using  namespace  std;
 
int  main()
{
 
	printf("%s%d%c\n", "hello", 100, 'A');

	//更方便快捷
	cout << "hello" << 100 << 'A' << endl;

	int  a;
	char b[100] = {0};
	char  c;
	//scanf("%d", &a);
	//scanf("%s", b);
	//scanf("%c", &c);
	//printf("%d%s%c\n", a, b, c);


	//使用cin,更方便
	cin >> a >> b >> c;
	cout << a << b << c << endl;


	//格式控制符
	int  d = 16;
	cout << dec << d << endl;
	cout << hex << d << endl;
	cout << oct << d << endl;

	cout << setw(10) << setfill('*') << d;

	return 0;
}