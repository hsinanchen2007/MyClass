#include<stdio.h>

void  main()
{
	int  a[2][3] = { {1,2,3},{4,5,6} };

	//四种指针的值完全一样
	printf("%p     %p     %p    %p \n"   ,    a,   a[0],  &a[0],  &a[0][0]);

	int(*p1)[3] = a; //指向一个二维数组的指针
	int *p2  = a[0];//错误的、a[0]仅仅是一个int * 的普通指针
	int(*p3)[3] = &a[0];
	int *p4 = &a[0][0];// 错误的、也只是一个普通指针

	//普通指针与二维数组指针的区别
	printf("%p     %p     \n",  p2, p2+1);//普通，偏移了4个字节
	printf("%p     %p     \n",  p1, p1+1);//二维，偏移了12个字节,  3X4= 12

	//1把指针当成二维数组名
	 for (int i = 0; i < 2; i++)
	 for (int j = 0; j < 3; j++)
	 {
		 printf("%d      ", p1[i][j]);
     }
	 printf("\n" );

	 //2 
	 for (int i = 0; i < 2; i++)
	 for (int j = 0; j < 3; j++)
	  {
			 printf("%d      ",  *(  p1[i]+j)); // p1[i]是一维数组的首地址
	 }
	 printf("\n");


	 //3
	 for (int i = 0; i < 2; i++)
	 for (int j = 0; j < 3; j++)
		 {
			 printf("%d      ",   *( *(p1+i) + j)); // p1是行指针， *(p1+i) 等价于 p1[i]
		 }
	 printf("\n");



	 //4
	 for (int i = 0; i < 2; i++)
		 for (int j = 0; j < 3; j++)
		 {
			 printf("%d      ", *(  *(&p1[i])   + j)); // p1是行指针，*(&p1[i])  等价于 p1[i]
		 }
	 printf("\n");
}