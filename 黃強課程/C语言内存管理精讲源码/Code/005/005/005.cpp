#include<stdio.h>


//������ȫ�־�̬��

int   a;  //ȫ�ֱ�����δ��ʼ��
short   b = 10;//ȫ�ֱ������Ѹ�ֵ
char  *c = NULL;//ȫ�ֱ������Ѹ�ֵ
static  int   f = 200;//��̬����


int  main()
{
	static  int  d = 100;
	static  int  e = 200;

	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", &c);
	printf("%p\n", &d);
	printf("%p\n", &e);
	printf("%p\n", &f);
}