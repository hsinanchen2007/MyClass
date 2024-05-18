#include<stdio.h>


void  main()
{
 //循环结构- for
	int  sum = 0;
	for (int i = 1; i <= 100; ++i)//没有++i，则条件一直为真，那么死循环
	{
		sum += i;//sum  = sum +i;
	}
	printf("for  %d\n", sum );


	//循环结构-while
	sum = 0;
	int j = 1;
	while (j <= 100)
	{
		sum += j;

		++j;//不能忘记，改变条件状态，否则就是死循环
	}
	printf("while  %d\n", sum);


	//循环结构-do while
	sum = 0;
	int k = 1;
	do//一定会执行一次
	{
		sum += k;
		++k;
	} while (0);
	//while (k <= 100);
	printf("do while  %d\n", sum);

}