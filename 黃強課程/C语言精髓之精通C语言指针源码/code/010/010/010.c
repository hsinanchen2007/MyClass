#include<stdio.h>


typedef int(*PFUN)(int); //���庯��ָ������

PFUN  fun(int a, int b){	PFUN  f = NULL;	return f;}

void  main()
{
	int  a = 10;
	int  b = 20;

	//ָ�볣����ָ��ֵ���ɸı䣬Ҳ����˵�����ܸı�ָ��
	int * const   p = &a;
	//p = &b;//����


	//ָ����ڴ�ռ�����ݲ��ɸı�
	const int  *p1 = a;
	//*p1 = 30;//����


	const int *  const p2 = &a;
	 //p2 = &b;//����
	 //*p2 = 30;//����


	int(*pA)[10];	int arr[2][10] = { 0 };	pA = arr; 	//ָ��һ��ָ�루��һ��ָ���ά�����ָ�룬�ڶ�ά��10��	int(**p3)[10] = &pA;

 	int *c[2] = { &a,  &b };	//ָ��һ��ָ������ĵ�ַ  �����ָ�����飬������Ԫ�أ�	int *(*p4)[2] = &c;
	PFUN  f1;	PFUN  f2;	//ָ�����飬�����е�ÿ��Ԫ�ض��Ǻ���ָ�루ָ��ĺ�������ֵ��int������int��	int(*p5[2])(int) = { f1,f2 };


	//����ָ�� ��ָ��ĺ�������ֵ�Ǻ���ָ�루ָ��ĺ�������ֵ��int������int�� ������������int	int(*(*p6)(int, int))(int);	p6 = fun;

}