#include <stdio.h>

void  swap(int a, int b)
{
	int  temp = a;
	a = b;
	b = temp; 
}

void  swap2(int *a, int *b)
{
	int  temp = *a;
	*a = *b;
	*b = temp;
}

void  swap3(int **a, int **b)
{
	int *  temp = *a;
	*a = *b;
	*b = temp;
}

 

void  main()
{
	int  a = 10;
	int  b = 20;

	//����ʧ�ܣ������ڽ�����ʵ�εĿ�������ʵ���޹�
	swap(a,b);
	printf("%d, %d\n",a,b );

	//�����ɹ��� ʵ�εĵ�ַ���룬ֱ�Ӳ���ʵ�ε����� 
	swap2(&a, &b);
	printf("%d, %d\n", a, b);


	int c = 30;
	int d = 40;
	int *pC = &c;
	int *pD = &d;
	//����ʧ�ܣ������ڽ�����ʵ�εĿ�������ʵ���޹�
	swap(pC, pD);
	printf("%d, %d\n", *pC, *pD);

	//����Ĵ��Ρ���������ǿ������ת������������Ķ���
 	swap3(pC, pD);
  	printf("%d, %d\n", *pC, *pD);

	//�����ɹ�����ȷ��д����ԭ��ͬ�ϣ���Ϊָ�����Ҳ�Ǳ�������û��ʲô����
	swap3(&pC, &pD);
	printf("%d, %d\n", *pC, *pD);
}