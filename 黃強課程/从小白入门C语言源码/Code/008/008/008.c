#include<stdio.h>


void  main()
{
	/*
	//ifѡ��ṹ ��3����ʽ
	if (1)//1�����������ҵ
	{
		printf("���Կ�����Ƭ��\n");
	}

	if (0)//0����û���������ҵ
	{
		printf("���Կ�����Ƭ��\n");
	}
	else
	{
		printf("�����Կ�����Ƭ��\n");
	}



	int  a = 0;
	printf("�����������\n");
	scanf("%d", &a);

	if (a >= 90)
	{
		printf("���������\n");
	}
	else  if(a>=80)
	{
		printf("���÷�����\n");
	}
	else  if (a >= 60)
	{
		printf("���������\n");
	}
	else
	{
		printf("�����������\n");
	}

	*/


	//switch-case�ṹ
	int  b = 0;
	printf("���������֣�\n");
	scanf("%d", &b); 
	switch ( b)
	{ 
	case 1:
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
		break; 
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
		break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	case 7:
		printf("������\n");
		break; 
	default:
		printf("�Ƿ������֣�\n");
		break;
	}



}