#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char  * fun()
{
	char arr[10];
	 return  arr;
 }//arr是栈内存，离开此花括号，栈被释放回收


int main()
{
	//1.访问到野指针指向的区域，越界访问
	char  *p;//没有初始化，野指针，乱指一气
	//strcpy(p, "hello");//非法越界访问

	//2.数组下标越界访问
	int   * p2 = (int *)calloc(10, sizeof(int));
	for (size_t i = 0; i <= 10; i++)
	{
		p2[i] = i;//很难察觉的越界访问， 下标越界
	}

	//3.使用已经释放的内存
	char *p3 = (char *)malloc(10);
	free(p3);
	if (p3 != NULL)//这里if不起作用
	{
		strcpy(p3, "hello");//错误，p3已经被释放
	}


	//4.企图访问一段释放的栈空间
	char *p4 = fun();  //p4指向的栈空间已经被释放
	strcpy(p4, "hello");
	printf("%s\n",p4);


	//5.容易忽略 字符串后面的\0
	char  *p5 = (char *)malloc(strlen("hello"));//忘记加1
	strcpy(p5, "hello");//导致p5的长度不够，越界


	return 0;
}