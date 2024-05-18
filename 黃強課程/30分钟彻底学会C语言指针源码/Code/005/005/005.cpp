#include<stdio.h> 
 
void  fun()
{
	printf("fun()\n");
}

int   max(int a, int b)
{
	int  c = a > b ? a : b;
	printf("%d\n" ,c );
	return  c;
}


typedef  int(*PFUN3)(int); 
PFUN3    fun3(int  a)
{
	return   NULL;
}



int  main()
{
	//函数的内存首地址 就是 函数名 , 加&也可以
	printf("fun    %p   ,    %p\n", &fun, fun);


	//定义fun函数对应的  函数指针类型（推荐）
	typedef  void  (*PFUN)(); 
	//利用函数指针类型定义函数指针变量
	PFUN   pfun=NULL; 
	printf("函数指针类型：  %d\n",sizeof(PFUN));
	pfun = &fun;//赋地址值


	//不加typedef 可以直接定义函数指针变量，不推荐
	void(*pfun2)();
	pfun2 = &fun;//赋地址值

	//利用函数指针变量调用函数
	pfun();//指针变量当成函数名即可
	pfun2();


	//一个复杂点的函数指针
	typedef  int (*PMAX)(int ,int );
	PMAX  pmax = max;//定义函数指针变量
	max(555, 888);


	//一个更复杂的函数指针例子
	//typedef   PFUN3 (*PFUN4)(int);
	//PFUN4   f4 = fun3;

	typedef    int   (*  (*PFUN4)(int)   )(int);
	PFUN4  f4 = fun3;


	return 0;
}