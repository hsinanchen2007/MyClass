#include<stdio.h>

//第一种写法
/*
void   main()
{
	printf("函数入口main！\n");
}


//第二种写法
int  main()
{
	printf("函数入口main！\n");
	return 0;
}
*/

//完整的main函数

int   main(int  argc, char *argv[])//int   main(int  argc, char **argv)
{
	/*
	printf("argc代表argv数组的元素个数：%d\n"  ,argc);//argc一定是>=0的

	printf("argv[0]代表程序路径：%s\n", argv[0]); 

	for (int i =1; i < argc; ++i)
	{
		printf("第%d个参数：%s\n", i, argv[i]);
	} 
	*/

	//模拟echo命令
	for (int i = 1; i < argc; ++i)
	{
		printf("%s      ",  argv[i]);
	}
	printf("\n");

}