# include <stdio.h> 
# include <stdlib.h> 


void main()
{
	int    a = 10;
	char b = 'A';
	float c = 12.3456;


	//�����Ϳ���ָ���κ����͵ı���
	void *pA = &a;
	void *pB = &b;
	void *pC = &c;

	//�����ʹ��ԭ���ı��� 
	//int  a1 =(int)( *pA);//�����

	int  a1 =  (*  (int*)pA );//��ȷ��ת��
	printf("%d\n", a1);

	int a3;//ֵ�������
	printf("%d\n", a3);

	int *pA3;//Ұָ�룬Σ��
	pA3 = NULL;//   #define NULL ((void *)0)
	printf("%p\n", pA3);

	pA3 = (int *)malloc(4);
	printf("%p\n", pA3);//�Ϸ����ڴ��ַ

	free(pA3);
	printf("%p\n", pA3);//�����ٵ��ڴ��ַ����ʱpA3��ΪҰָ��
	pA3 = NULL;//�ÿգ�����Ұָ��

}