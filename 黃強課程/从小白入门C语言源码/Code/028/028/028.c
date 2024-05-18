#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明

//定义一个共用体类型MyUnion
union   MyUnion
{
	char      a[9];
	int         b;
	float      c; 
};

void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
 
	//定义一个MyUnion共用体变量
	union  MyUnion  u1;

	strcpy(u1.a, "hello");//已经把b,c覆盖了
	printf("a:%s\n",  u1.a);

	 u1.b = 10;//已经把a,c覆盖了
	 printf("b:%d\n", u1.b);
	 printf("a:%s\n", u1.a);

	 u1.c = 10.11f;//已经把b,a覆盖了
	 printf("c:%f\n", u1.c);
	 printf("b:%d\n", u1.b);
	 printf("a:%s\n", u1.a);


	 //共用体大小为最大数据成员的大小，最后必须为4的倍数
	 printf("size :%d\n", sizeof(union  MyUnion));


}

