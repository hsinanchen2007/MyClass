#include<stdio.h>

 
struct A
{
	int  a; 
	char b;
	//...
};

struct  B
{
	int  a;
	//struct  B  next; //���޵�ȥ���壬����
	struct  B * next; //����ָ�룬�򲻻ᱨ��������ʵ��ͬ����Ч��
};


//���ýṹ����Դ��ݶ������
void   fun(void  *p)
{
	A  *pA = (A*)p;
	printf("%d  %c\n",pA->a,pA->b);
}


int  main()
{

	//1.����ָ����ĳ�����ֵ
	 volatile const int  a = 100;
	//a = 200;//���� �������������޸�
	int  *pA = (int *)&a;
	*pA = 200;
	printf("%d\n", a);


	//2.����void*���� �κ����͵Ĳ���,���ýṹ�崫�ݶ������
	A   x;
	x.a = 100;
	x.b = 'A';
	fun(&x);


	//3.����ָ��ʵ������ṹ
	B   b1;
	b1.a = 111;

	B   b2;
	b2.a = 222;
	b1.next =&b2;  //�������γ�����

	B   b3;
	b3.a = 333;
	b2.next = &b3;  //�������γ����� 
	b3.next = NULL;

	B *p = &b1;//����ͷ
	while (p)
	{
		printf("%d     ", p->a);
		p = p->next;
	}

}