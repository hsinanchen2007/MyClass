#include<iostream> 
using namespace std;

void main2()
{
	int  a = 111;
	int  b = 222;
	int  sum = 0;
	__asm //��������Ƕ���... 
	{
		mov eax, a; //a��ֵ��eax�Ĵ���
		mov ebx, b;
		lea eax, [eax + ebx];
		mov sum, eax; //����ֱ�ӽ�eax��ֵ->c 
	}
	cout << sum;
}
