#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������

//����һ������������MyUnion
union   MyUnion
{
	char      a[9];
	int         b;
	float      c; 
};

void  main()//ϵͳ�������������������ں�������������ļ�д
{
 
	//����һ��MyUnion���������
	union  MyUnion  u1;

	strcpy(u1.a, "hello");//�Ѿ���b,c������
	printf("a:%s\n",  u1.a);

	 u1.b = 10;//�Ѿ���a,c������
	 printf("b:%d\n", u1.b);
	 printf("a:%s\n", u1.a);

	 u1.c = 10.11f;//�Ѿ���b,a������
	 printf("c:%f\n", u1.c);
	 printf("b:%d\n", u1.b);
	 printf("a:%s\n", u1.a);


	 //�������СΪ������ݳ�Ա�Ĵ�С��������Ϊ4�ı���
	 printf("size :%d\n", sizeof(union  MyUnion));


}

