#include<stdio.h> 

struct  A
{
	int m;
	char n;
};

int  main()
{
	 //����ṹ�����
	struct   A    a = {555,'A'};
	struct   A*   pA = &a;//��ȡ�ṹ������ĵ�ַ�������ṹ��ָ�����
	printf("pA��ֵ�� %p\n",  pA);

	//  *pA �ȼ��� a
	printf("m:  %d,  n: %c \n", (*pA).m, (*pA).n);

	//���ýṹ��ָ����� ����-> �� ���ʽṹ���Ա
	printf("m:  %d,  n: %c \n",pA->m, pA->n);

	return 0;
}