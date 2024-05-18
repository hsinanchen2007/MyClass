#include<stdio.h>


void  main()
{
	/*
	//if选择结构 ，3种形式
	if (1)//1代表完成了作业
	{
		printf("可以看动画片！\n");
	}

	if (0)//0代表没有完成了作业
	{
		printf("可以看动画片！\n");
	}
	else
	{
		printf("不可以看动画片！\n");
	}



	int  a = 0;
	printf("请输入分数：\n");
	scanf("%d", &a);

	if (a >= 90)
	{
		printf("优秀分数：\n");
	}
	else  if(a>=80)
	{
		printf("良好分数：\n");
	}
	else  if (a >= 60)
	{
		printf("及格分数：\n");
	}
	else
	{
		printf("不及格分数：\n");
	}

	*/


	//switch-case结构
	int  b = 0;
	printf("请输入数字：\n");
	scanf("%d", &b); 
	switch ( b)
	{ 
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break; 
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期天\n");
		break; 
	default:
		printf("非法的数字！\n");
		break;
	}



}