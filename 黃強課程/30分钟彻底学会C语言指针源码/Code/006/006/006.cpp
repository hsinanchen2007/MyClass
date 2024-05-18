#include<stdio.h> 
#include<stdlib.h> 


int  main()
{
	//给指针变量赋地址值
	int  *p = (int *)malloc(sizeof(int));
	*p = 666;//给内存区域赋值
	printf("%p  ,  %d\n", p,   *p);
	//野指针情况1 
	free(p);//把分配的内存销毁，此刻p沦为野指针，因为它指向已销毁的内存

	printf("%p  ,  %d\n", p,  *p);//已经变成乱码


    //野指针情况2
	int  *p2 = (int *)0x34458934;//乱指一气的野指针
	//*p2 = 100;//非法修改内存的内容
	//printf("%d\n",  *p2);//访问无权限的内存

	//如果指针不初始化，那么它的值是CCCCCCCC，野指针
	int  *p3;
	printf("%p \n", p3); 

	//避免野指针的方法
	//1.初始化为NULL
	int  *p4 = NULL;

	
	//2.free后置为NULL
	p4 = (int *)malloc(sizeof(int));
	*p4 = 888;
	free(p4);
	p4 = NULL; 
	if (p4 != NULL)
	{
		//才使用p4
		printf("%p  ,  %d\n", p4, *p4); 
	}



	return 0;
}