#include<stdio.h>

void  main()
{

	int  a = 10;
	int  b = 20;
	//格式化打印函数（输出到屏幕）
	printf("%d  ,  %d\n", a, b);
	printf("a是：%d   b是：%d\n", a, b);

	//从键盘由用户手动输入（和printf正好对于）
	scanf("%d%d", &a, &b);
	printf("a是：%d   b是：%d\n", a, b);


	//格式化控制符 
	char g = 'A';
	printf("%c\n", g);

	short  h = 10;
	printf("%d\n", h);

	int   i= 100;
	printf("%d\n", i);

	long   j = 200;
	printf("%ld\n", j);


	float   k = 1.234;
	printf("%f\n", k);

	double  l = 1.345678;
	printf("%f\n", l);

}