#include<stdio.h>
#include<stdarg.h>

//函数的参数是从右至左传入的
void   fun1(int  a, char *b, int  c)
{
	printf("%p\n" ,&a); 
	printf("%p\n", &b);
	printf("%p\n", &c); //c在高地址、栈低是在高地址，C在栈底
}

//利用...表示可变参数函数
void   fun2(int  a, char *b, int  c)
{
	//获取第一个参数的首地址
	char *p = (char *)&a;

	//第二个参数的首地址
	char *p2 = p + sizeof(int);

	//第三个参数的首地址
	char *p3 = p2 + sizeof(char *);

	printf(" %d ,  %s , %d \n", *((int *)p),  (*((int*)p2) ),   *((int *)p3) ); 
}


// 利用 va_list类型( char *  ) 
// va_start获取参数首地址     va_arg取参数的值  va_end清空指针
//可变参数个数的求和函数
int   var_sum(int  n, ...) //人为约定n为参数的个数
{
	int  sum = 0;

	va_list  ap;
	va_start(ap, n);//初始化ap为首地址

	for (size_t i = 0; i <  n ; i++)
	{
	    int  val= 	va_arg(ap, int); //返回每个参数的值
		sum += val;
	}

	va_end(ap);//指针置0， 结束参数遍历

	return  sum;
}

//模拟实现printf函数
int    MyPrintf(const char *  fmt, ...)
{
	va_list  ap;
	va_start(ap, fmt);//初始化ap为首地址

	const char *p = fmt;
	while (*p)
	{
		if (*p == '%')
		{ 
			++p;
			if (*p == 'd')
			{
			   int  i =	va_arg(ap, int);
			   printf("%d",i);
			}
			else   if(*p == 's')
			{
				char *  s = va_arg(ap, char *);
				printf("%s", s);
			}
			else   if (*p == 'c')
			{
				char   c= va_arg(ap, char );
				printf("%c", c);
			}
		} 
		else
		{ 
			putchar(*p);
		} 

		++p;
	} 

	va_end(ap);

	return 0;
}

int  main()
{

	//打印函数参数栈内存地址
	fun1(111,"222",333);


	//演示利用地址来访问参数
	fun2(111, "222", 333);


	//测试可变参数函数var_sum
	printf("%d \n", var_sum(2  ,33,44));
	printf("%d \n", var_sum(5, 1,2,3,4,5));

	//系统的printf函数
	   printf("int:%d    str:%s    char:%c   \n" ,  666,   "aaa",    'A' );

	//测试MyPrintf
	   MyPrintf("int:%d    str:%s    char:%c \n", 666, "aaa", 'A');


	return    0;
}