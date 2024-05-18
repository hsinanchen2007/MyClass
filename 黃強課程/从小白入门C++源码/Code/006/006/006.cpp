#include<iostream> 
using namespace std;

void main2()
{
	int  a = 111;
	int  b = 222;
	int  sum = 0;
	__asm //下面是内嵌汇编... 
	{
		mov eax, a; //a的值给eax寄存器
		mov ebx, b;
		lea eax, [eax + ebx];
		mov sum, eax; //可以直接将eax的值->c 
	}
	cout << sum;
}
