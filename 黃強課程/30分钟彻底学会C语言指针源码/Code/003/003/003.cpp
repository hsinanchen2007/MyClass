#include<stdio.h> 
 
int  main()
{
	int  *p1 = NULL;//��ʼ��Ϊ��,0
/*
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
 */

	char *p2 = NULL;
	float *p3 = NULL;


	int  a;//����һ�����ͱ���a
	//�������ˣ���λ�ȡa���ڴ��ַ��
	//ͨ��& ����ȡ

	printf("a���ڴ��ַ�� %p\n",  &a);

	//int *  pA = (int *)0x00D7FAF0 ;//�����Ͽ�����ô��ֵ,
	                                                    //���������֪���ڴ��ַ
	int  *pA = &a;//ʵ���е�д��


	//char *pB = &a;//���� char * ������int * ��ֵ�� ������Ҫ����һ��


	int  b = 5;
	int  *pB = &b;
	printf("b�е����ݣ� %d\n", *pB);



	return 0;
}