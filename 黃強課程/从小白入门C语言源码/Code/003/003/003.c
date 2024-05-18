#include <stdio.h>//包含头文件


//主函数，程序入口
void    main()
{
	//字符类型 （字母）
	printf("char:%d\n" ,sizeof(char));

	//整型（整数）
	printf("short:%d\n", sizeof(short));//短整型
	printf("int:%d\n", sizeof(int));//整型
	printf("long:%d\n", sizeof(long));//长整型

	//浮点型（小数）
	printf("float:%d\n", sizeof(float));//单精度
	printf("double:%d\n", sizeof(double));//双精度
}