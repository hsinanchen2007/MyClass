
#include <stdio.h>

//共用体，占据同一块内存空间
union A
{
	char a;
	int b;
	double c;
};

int main()
{ 
	//共用体占的空间，是成员中最大的那个成员占得空间
	printf("公用体占的字节数： %d\n", sizeof(union A));

	//由于占用同一块内存空间，所以同一时刻，只能使用一个成员
	//对任意一个成员赋值，都会影响其它成员
	union  A   u;

	//使用a成员
	u.a = 'A';
	printf("三个成员的值： %c   %d    %f\n", u.a, u.b, u.c);

	u.b = 100;
	printf("三个成员的值： %c   %d    %f\n", u.a, u.b, u.c);

	u.c = 0.123;
	printf("三个成员的值： %c   %d    %f\n", u.a, u.b, u.c);

}
