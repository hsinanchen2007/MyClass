#include<stdio.h>

void  main()
{

	int  a = 10;
	int  b = 20;
	//��ʽ����ӡ�������������Ļ��
	printf("%d  ,  %d\n", a, b);
	printf("a�ǣ�%d   b�ǣ�%d\n", a, b);

	//�Ӽ������û��ֶ����루��printf���ö��ڣ�
	scanf("%d%d", &a, &b);
	printf("a�ǣ�%d   b�ǣ�%d\n", a, b);


	//��ʽ�����Ʒ� 
	char g = 'A';
	printf("%c\n", g);

	short  h = 10;
	printf("%d\n", h);

	int   i= 100;
	printf("%d\n", i);

	long   j = 200;
	printf("%ld\n", j);


	float   k = 1.234;
	printf("%f\n", k);

	double  l = 1.345678;
	printf("%f\n", l);

}