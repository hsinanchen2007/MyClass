#include<stdio.h>
 

void  main()
{
   //字符串常量就是一个地址，相当于一个无名的字符数组
	printf("%p\n", "hello");

	//把首地址赋给指针变量p，终于相当于有名字了
	char   *p = "hello";
	char   *p2 = p;

	//1指针变量当成数组名用
	for (int i = 0; i < 6; ++i)
	{
		printf("%c", p[i]);
	}

	printf("\n" );

	//2指针变量自己移动,最后移动到了数组末尾、后面的内容我们不得而知
	for (int i = 0; i < 6; ++i)
	{
		printf("%c",  *(p++));
	}

	printf("\n");

	//3指针不动，偏移量增加, 指针值不变
	p = p2;
	for (int i = 0; i < 6; ++i)
	{
		printf("%c", *(p+i));
	}


	printf("\n");
	//改成hallo
	 p[1] = 'a';//字符串常量的值不能改变！
	printf("%s", p);

}