#include<stdio.h>
#include"005.h"
#include"005.h"//重复包含

//去除警告指令
//#pragma  warning(disable:4700)



//#define  A   

int  main()
{  
 //条件编译1
#ifdef   A 
	printf("定义了符号A\n");
#endif


	//条件编译2
#ifdef   A 
	printf("定义了符号A\n"); 
#else 
	printf("无符号A\n");
#endif
	  
	//条件编译3
#ifndef   A 
	printf("无符号A\n");
#else 
	printf("定义了符号A\n");
#endif


	//条件编译4
#if     22 
	printf("条件为真\n");
#else 
	printf("条件为假\n");
#endif


	//条件编译4
#if    0 
	printf("第一种情况\n");
#elif   33
	printf("第二种情况\n");
#else 
	printf("其他情况\n");
#endif


 //#error指令
#define   B    2
#if  B>3
#error   B   is  larger then  3!
#endif


printf("%d   ,  %s \n", __LINE__, __FILE__);
#line   666   "1.txt"
printf("%d   ,  %s \n", __LINE__, __FILE__);

 
int  a;
int  b = a;


return 0;
}