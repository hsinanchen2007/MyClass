#include<iostream> //cin��cout��ͷ�ļ�
#include <iomanip>// setw   setfill��ͷ�ļ�
using  namespace  std;
 
int  main()
{
 
	printf("%s%d%c\n", "hello", 100, 'A');

	//��������
	cout << "hello" << 100 << 'A' << endl;

	int  a;
	char b[100] = {0};
	char  c;
	//scanf("%d", &a);
	//scanf("%s", b);
	//scanf("%c", &c);
	//printf("%d%s%c\n", a, b, c);


	//ʹ��cin,������
	cin >> a >> b >> c;
	cout << a << b << c << endl;


	//��ʽ���Ʒ�
	int  d = 16;
	cout << dec << d << endl;
	cout << hex << d << endl;
	cout << oct << d << endl;

	cout << setw(10) << setfill('*') << d;

	return 0;
}