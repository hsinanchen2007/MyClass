#include<stdio.h>


void fun(void *p) //�����к�ǿ����չ��
{
	//��ԭ��ʵ���ͼ���
}

int  main()
{

	//��ʾָ��ı���
	int  a = 100;
	int *p = &a;//����ָ��
	int  c = (int)p;//����һ���޷��ŵ�����
	int *p2 = (int *)c;
	printf("%d\n", *p2);


	//��ʵ��Ŀ�����е�ʹ�ü���
	char buf[256];
	int  *p3 = (int *)buf;
	*p3 = 222;//�ǺϷ��ģ���Ϊָ��Ϸ��ڴ棬����4���ֽ�
	printf("%d\n", *p3);

	float *p4 = (float *)buf;
	*p4 = 12.345f;
	printf("%f\n", *p4);//�ǺϷ��ģ���Ϊָ��Ϸ��ڴ棬����4���ֽ�


	struct A
	{
		int a;
		double b; 
	};
	A *p5 = (A *)buf;
	p5->a= 34;
	p5->b = 34.567;
	printf("%d ,  %f\n", p5->a, p5->b);//�ǺϷ��ģ���Ϊָ��Ϸ��ڴ棬����A���ֽ���


	//��ʾvoid *����
	int x = 100;
	char y = 'A';
	float z = 1.23456f;
	void *p6 = &x;//void *����ָ���κ����͵ĵ�ַ
	void *p7 = &y;
	void *p8 = &z;

	//���������Ŀ���չ��
	fun(&x);
	fun(&y);
	fun(&z);
	fun(p5);


	return  0;
}