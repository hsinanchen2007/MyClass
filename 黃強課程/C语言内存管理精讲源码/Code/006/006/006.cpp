#include<stdio.h>

//“AAA”是字符串常量，存放在常量区
char  *p = "AAA";

int  main()
{
	//p1是局部变量，在栈上， “AAA”是字符串常量，存放在常量区
	char  *p1 = "AAA";

	//p2是局部变量，在栈上，“AAA”不是字符串常量，她只是一种初始化的写法
	char  p2[]= "AAA";

	//p3是局部变量，在栈上， “AAA”是字符串常量，存放在常量区
	char  *p3 = "AAA";

	//p4是局部变量，在栈上， “AAB”是字符串常量，存放在常量区
	char  *p4 = "AAB";

	printf("%p\n", p);
	printf("%p\n", p1);
	printf("%p\n", p2);
	printf("%p\n", p3);
	printf("%p\n", p4);
}