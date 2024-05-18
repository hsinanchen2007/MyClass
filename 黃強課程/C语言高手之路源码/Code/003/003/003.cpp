#include<stdio.h>
#include<stdlib.h>

void  fun(char a[3])//�������Ϊָ��
{
	printf("fun   %d\n", sizeof(a));//ָ��
}

void  fun2(char (&a)[3]) //�������Ϊ���������
{
	printf("fun   %d\n", sizeof(a));//����
}
 
void  fun3(char(*a)[3]) //�������Ϊָ��һά�����ָ��
{
	printf("fun   %d\n", sizeof( *a));//  *a����
}


struct  A
{ 
	int   sum(int  a,int  b)
	{
		return a + b;
	} 
};


union  B
{
	char  a[13]; //���ռ�Ϊ13�����Ƕ��룬Ϊ16
	int  b; 
};


//�õ�����Ԫ�ظ���
#define   count(arr)   ( sizeof(arr)  /  sizeof(arr[0]))


int  main()
{
	//sizeof����ָ�룬ָ��ȫ������4�ֽ�
	char  *p1 = "hello";
	printf("p1   %d\n",  sizeof(p1));

	char *  p2 = (char *)malloc(10);
	printf("p2   %d\n", sizeof(p2));

	void  *p22 = NULL;
	printf("p22   %d\n", sizeof(p22));

	//sizeof��������
	int  p3[100] = { 1, 2, 3 };
	printf("p3   %d\n", sizeof(p3));//ע�⣺���ֽ� ������4 *100 ��Ԫ��

	int  p4[] = { 1, 2, 3, 4 ,5 };
	printf("p4   %d\n", sizeof(p4)); 

	char p5[] = "hello"; //ע�⣬ hello���滹��\0,���Դ�СΪ1*6
	printf("p5   %d\n", sizeof(p5));

	//sizeof���Զ�ά����
	int  p6[3][4];
	printf("p6   %d\n", sizeof(p6));//����ά�����*���ʹ�С   3*4*4


	//sizeof���Ժ�������
	char   a[3] = {1,2,3};
	fun(a);
	fun2(a);
	fun3(&a); //ȡһά����ĵ�ַ

	//sizeof���Կսṹ��
	printf("A   %d\n", sizeof(A));//�սṹ���ڴ���СΪ1
	//������ռ���ڴ�ռ�
	 
	//sizeof����������
	printf("B   %d\n", sizeof(B));//���ĳ�Ա��С�������ڴ����

	//sizeof����
	int  i = 1;
	int  n = sizeof(++i);//��Ϊsizeof�ǲ������������Ǻ������ڱ���ʱ��ȷ����
	printf("sizeof(++i)   %d     n:%d\n", i  ,n);  //++i��Ч

	//���Եõ��������
	printf("count    %d\n",  count(a));  



	return 0;
}