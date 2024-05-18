#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明

void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
 
	printf("%p   \n", "hello");//字符串常量实际上就是一个首地址

	char *p = "hello";//给一个无名的字符数组，给了一个名字
	                            //把“hello”的首地址赋给字符型指针变量



	//1.指针作为数组名来访问字符串,无形的\0
	for (int i = 0; i <6; ++i)
	{
		printf("%c",  p[i]);
	} 


	printf("\n"); 

    //2.指针p的值一直不变
	for (int i = 0; i <6; ++i)
	{
		printf("%c", *(p+i));
	}


	printf("\n");
  
	char *p2 = p;//保存“hello”首地址

	//3.指针p的值时刻改变++
	for (int i = 0; i <6; ++i)
	{
		printf("%c",* (p++));
	}

	printf("\n");

	p = p2;//相当于，把指针p重新指向“hello”的首地址
	// 再循环一遍，打印
	for (int i = 0; i <6; ++i)
	{
		printf("%c", *(p++));
	}



	char *p3 = NULL;
	p3 = "hello";//把hello的首地址给p3
	printf("\n%p", p3);
	p3 = "world";//把world的首地址给p3，覆盖前一次的值
	printf("\n%p", p3);


	//把p3的第二个元素值o改为O
	//p3[1] = 'O';//错误，因为字符串是一个常量，不允许改变常量的值

}

