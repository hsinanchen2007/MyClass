#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
 

//定义了一个节日的枚举,默认会从0开始递增
enum  Festival
{
	GuoQing=4,
	ZhongQiu=33,
	DuanWu=8,
	ChunJie  
};

//定义一个星期的类型
enum week
{
	Sun=7,
	Mon=1,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat
};


void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
	int   festival = ZhongQiu;
	if (festival == ZhongQiu)//可读性特别强
	{
		printf("%d \n",ZhongQiu);
		printf("中秋节到了！\n");
	}

	 
	printf("请输入1~7之间的一个数字：\n");
	int day;
	scanf("%d", &day);     //输入一个 i  
	switch (day)
	{
	case Sun:	    printf("星期日\n"); break;
	case Mon:	printf("星期一\n"); break;
	case Tue:	    printf("星期二\n"); break;
	case Wed:	printf("星期三\n"); break;
	case Thu:	    printf("星期四\n"); break;
	case Fri:	    printf("星期五\n"); break;
	case Sat:	    printf("星期六\n"); break;
	}


}

