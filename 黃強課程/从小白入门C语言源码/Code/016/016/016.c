#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明


int  g = 10;//没在函数体内，是全局变量, 作用域，整个源文件

  
void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
	printf("全局变量g：%d\n",g);

	int  a = 20;//在函数体内定义，局部变量 ，作用域从此开始

	{ //代码块
		int  b = 30;//局部变量

		g = 50;//使用全局变量
		printf("全局变量g：%d\n", g);

		int g = 40;
		printf("局部变量g：%d\n", g);//此处呢，局部变屏蔽盖了全局变量值

	}//b在此处销毁

	//printf("代码块局部变量b：%d\n", b);//超出b的作用域

	printf("局部变量a：%d\n", a);


	sum(300,50);

}//a在此处销毁


int  sum(int a, int  b)//a,b局部变量
{ 
	printf("全局变量g：%d\n", g);

	int  c = a + b;//c局部变量
	printf("局部变量c：%d\n", c);

}//a,b,c在此销毁