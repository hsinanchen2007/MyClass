#include<stdio.h>
#include<stdlib.h>

int  main()
{

	//malloc  ,�������ֽ��� , ��������ڴ�ռ��ֵ�������
	int  *p = (int *)malloc(5 *  sizeof(int));
	p[0] = 123;
	for (int i = 0; i < 5; ++i)
	{ 
		printf("%d   ", p[i]); //����4��ֵ���
	}

	printf("\n------------------------------------------------------------\n " );

	//calloc������������ �Զ����ڴ�ռ��ʼ��Ϊ0
	int   *p2 = (int *)calloc(5, sizeof(int));
	p2[4] = 123;
	for (int i = 0; i < 5; ++i)
	{
		printf("%d   ", p2[i]); 
	}



	printf("\n------------------------------------------------------------\n ");
	 
	//realloc �����Ե����ڴ�ռ�Ĵ�С �����ҿ���ԭ��������(���󣬻���  ��С)
	//int  *p3 =(int *) realloc(p, 6* sizeof(int));//����һ��㣬������ַ��ͬ
	//int  *p3 = (int *)realloc(p, 2 * sizeof(int));//��С��������ַ��ͬ
	int  *p3 = (int *)realloc(p, 100 * sizeof(int));//���ܴ�������ַ��ͬ ,�ͷ�ԭ�����ڴ�ռ�
	for (int i = 0; i <2; ++i)
	{
		printf("%d   ", p3[i]);
	} 

	printf("\np��ַ��  %p   ��  p3�ĵ�ַ��  %p   ", p,  p3);
	 



	return 0;
}