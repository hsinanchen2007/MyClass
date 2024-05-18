#include<stdio.h>

int  main()
{

	//指针+ 整数N  ，表示往后偏移N*sizeof(类型)
	int  a = 100;
	int *p1 = &a;
	printf("%p    %p\n", p1, p1 + 2);//006FFE14 与 006FFE1C相差2*  sizeof(int)字节

	char  b = 'A';
	char *p2 = &b;
	printf("%p    %p\n", p2, p2 + 2);//008FFDFF与 008FFE01相差2*  sizeof(char)字节

	//++指针， 表示偏移sizeof(类型)，  指针本身的值会改变
	int *p3 = &a;
	printf("%p  ",  p3); 
	printf("%p  ", ++p3);
	printf("%p  \n", p3);//++后指针自身的值改变

	  //指针- 整数N  ，表示往前偏移N*sizeof(类型) 
	int *p4 = &a;
	printf("%p    %p\n", p4, p4 - 2);//006FFE0C  006FFE04 相差2*  sizeof(int)字节

	//--指针， 表示偏移sizeof(类型)，  指针本身的值会改变
	int *p5 = &a;
	printf("%p  ", p5);
	printf("%p  ", --p5);
	printf("%p  \n", p5);//--后指针自身的值改变


	//指针-指针
	int *p6 = &a;
	int *p7 = &a + 3;
	printf("%d \n", p7-p6);//结果3
	printf("%d \n", (unsigned int )p7 - (unsigned int)p6);// 3*sizeof(类型)



	return 0;
}