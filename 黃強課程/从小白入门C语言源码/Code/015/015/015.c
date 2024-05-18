#include<stdio.h> //系统头文件，包含了printf,scanf等系统函数的声明
 

//求和1至n的累加和，用递归的方式实现
int   NFun(int  n)
{
	//思路：如果N=3，  3+ NFun（2），    如果N=2，  2+ NFun（1），    如果N=1，   NFun（1）=1 

	//终结条件
	if (n==1)
	{
		return 1;
	}
	else
	{
		return  n+ NFun(n-1);//自我调用
	}

}


void  main()//系统主函数，整个程序的入口函数，这个是它的简写
{
	int  sum = NFun(100);
	printf("%d\n",sum);
}

 