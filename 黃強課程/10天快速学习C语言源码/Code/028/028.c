
#include <stdio.h>

int main()
{
	char arr[5] = "good";//字符串末尾隐藏了一个'\0'字符，所有4+1
	char* p = arr;//数组名代表数组首地址,指针变量p指向arr

	p[0] = 'f';//更改第一个元素的值
	 
	for (int i = 0; i < 5; ++i)
	{
		printf("%c  ", p[i]);
	}


	char* p2 = "good";//字符串常量就代表这个字符串自己的首地址

	//p2[0] = 'f'; //错误，因为指针指向的是常量区内存，想改变常量区的内容，是错误的
	                     //语法是没问题的，但是运行时一定报错

	for (int i = 0; i < 5; ++i)
	{
		printf("%c  ", p2[i]);
	}

}
