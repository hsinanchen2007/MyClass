#include<stdio.h>
#include<windows.h>


struct A
{
	char a;  //0-1
	double  b;  //  8-15
	int c;      //16-20  ,����24
};
 
int  main()
{
	printf("sizeof(A) :%d\n",sizeof(A));

	// 0����ת��Ϊ�κ����͵�NULLָ��

	A *p = (A*)0;
	//printf("%d\n", p->a ); //NULLָ��ָ���Ա�����Ƿ�

	// ��ȡÿ����Ա��ƫ����     
    printf("%d\n", &(p->a)); //�Ϸ�
	printf("%d\n", &(p->b));
	printf("%d\n", &(p->c));


	//�����֪��ĳ����Ա�����ĵ�ַ�����ǲ��ǾͿ���֪�������ṹ����׵�ַ
	A   x;  //  &x ���Ի�ȡ�ṹ��x���׵�ַ
	x.a = 'A';
	x.b = 1.234;
	x.c = 333;
	//����ֻ֪����Ա����x.b���׵�ַ &x.b����λ�ȡx���׵�ַ 
	A  *pStart = (A *) (   (int ) &x.b  -   (int )&(p->b) );
	printf("%c, %f, %d\n", pStart->a, pStart->b, pStart->c);

	 
	//����windows�ṩ�ĺ�����ȡ��ԭ��һ��
	A  *pStart2 = CONTAINING_RECORD(&x.b, A, b);
	printf("%c, %f, %d\n", pStart2->a, pStart2->b, pStart2->c);

	 

	return    0;
}