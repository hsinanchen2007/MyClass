#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf�Ⱥ���������
#include"014.h"//�Զ��庯����ͷ�ļ�������sum������


void  main()//ϵͳ�������������������ں�������������ļ�д
{
	//����sum����
	int  c = sum(100 , 200);
	printf("%d", c);
}

//sum ������ʵ��
int  sum(int  a, int b)
{
	return  a + b;
}