#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
#include<stdlib.h> //系统头文件，包含了malloc,free等系统函数的声明

void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
	//定义了3个变量
	char  a = 'A';
	int b = 10;
	float c = 1.234f;

	//char *,  int  *,   float  *
   //void  * 可以指向任何类型的变量的地址
	void  *pA = &a;
	void  *pB = &b;
	void  *pC= &c;

	//错误，不允许使用不完整的类型
	//printf("%c",  *pA);

	//需要强制转换后，才能使用
	 char  *pAA = (char *)pA;
	 int  *  pBB = (int *)pB;
	 float  *pCC = (float *)pC;
	 printf("%c\n", *pAA);
	 printf("%d\n", *pBB);
	 printf("%f\n", *pCC);


	 //void *可以承接任何类型的地址，所以具有兼容性
	 int  *p = (int *)malloc(4);//可以分配任何类型的空间
	 int  *p2 = (char  *)malloc(4);
	 float  *p3= (float  *)malloc(4);
	 *p3 = 1.234f;
	 

	 printf("%p\n", p3);
	 free(p3);//释放内存了，但是不会让指针的值置NULL，需要手动=NULL，否则就是野指针
	 printf("%p\n", p3);
	 //此刻你再去访问p3的内存，事实上是非法访问!
	 p3 = NULL;//需要手动置空，避免野指针
	 if(p3!=NULL)
	 { 
	     printf("%f\n", *p3);//此刻已经是乱值了
	 }

	 //随机定义一个指针变量，不初始化
	 int  *p4; // 应该p4 = NULL;
	 printf("%p\n", NULL);
	//printf("%p\n",p4);//乱的地址值，乱指一气

}

