#include<stdio.h>

//     #将参数转化为字符串数组
#define   STR( s )     #s


//     ##  将参数链接起来
#define  STRUCT(name)        struct My##name##Struct \
                                              {\
                                                   int   m_##name;    \
											  };


//   #@ 将参数转化为字符
#define  CHAR(c)      #@c

// __VA_ARGS__       可变参数宏
#define    PRT(...)      printf(__VA_ARGS__)


//演示宏的问题
#define   fun()  \
	{ printf("语句1\n"); printf("语句2\n"); }

#define  fun2()   do {\
printf("语句1\n"); printf("语句2\n");\
}while (0)

int  main()
{
	//测试#
	printf("#特殊符    %s\n", STR(123456));
	printf("#特殊符    %s\n", STR("123456"));
	printf("#特殊符    %s\n", STR(中国));

	//测试##
	STRUCT(AA);
	STRUCT(BB); 
	MyAAStruct  a;
	a.m_AA = 111; 
	MyBBStruct  b;
	b.m_BB = 222;

	//测试#@
	printf("#@特殊符    %c\n",  CHAR(1));
	printf("#@特殊符    %c\n", CHAR(11));
	printf("#@特殊符    %c\n", CHAR(A));


	//测试__VA_ARGS__
	PRT("%d\n" ,  1); //2个参数传给宏
	PRT("%d    %s\n",  1  ,  "hello");//3个参数传给宏


    //测试预定义宏,一般用于日志输出，很方便
	printf("__LINE__    %d\n",   __LINE__);//行号
	printf("__FUNCTION__    %s\n", __FUNCTION__);//函数名
	printf("__FILE__     %s\n", __FILE__);//文件名
	printf("__DATE__    %s\n", __DATE__);//日期
	printf("__TIME__    %s\n", __TIME__);//日期

	//演示宏问题
	if (false) fun();

	if (false) fun() //使用不统一
	else  printf("语句3！\n");

	//测试do while
	if (false) fun2(); 
	if (false) fun2();
	else  printf("语句3！\n");


	return 0;
}