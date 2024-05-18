#include <stdio.h>

int main()
{
	int  a = 90;//考试成绩

	if (a >= 90) //条件为真就执行下面的语句块
	{
		printf("给你买奥特曼！\n");
	}


	if (a > 95)
	{
		printf("给你买大号的奥特曼！\n");
	}
	else
	{
		printf("没有95分以上！\n");
	}


	if (a > 95)
	{
		printf("给你买大号的奥特曼！\n");
	}
	else if (a > 91)
	{
		printf("给你买中号的奥特曼！\n");
	}
	else 
	{
		printf("没有91分以上！\n");
	}
	 


	//你周一补数学，周二补语文，周三补英语，周四补物理，周五补生物！
	//使用if else语句来写很麻烦的

	int day = 3;
	if (day == 1)
	{
		printf("周一补数学\n"); 
	}
	else if (day == 2)
	{
		printf("周二补语文\n");
	}
	else if (day == 3)
	{
		printf("周三补英语\n");
	}
	else if (day == 4)
	{
		printf("周四补物理\n");
	}
	else if (day == 5)
	{
		printf("周五补生物\n");
	}


	//使用switch case语句更加适合
	day = 6;
	switch (day)
	{
	case 1:
		printf("周一补数学\n");
		break;

	case 2:
		printf("周二补语文\n");
		break;

	case 3:
		printf("周三补英语\n");	
		break;

	case 4:
		printf("周四补物理\n");
		break;

	case 5:
		printf("周五补生物\n");
		break;

	default:
		printf("今天休息！\n");

	}

}
