#include<stdio.h>

//     #������ת��Ϊ�ַ�������
#define   STR( s )     #s


//     ##  ��������������
#define  STRUCT(name)        struct My##name##Struct \
                                              {\
                                                   int   m_##name;    \
											  };


//   #@ ������ת��Ϊ�ַ�
#define  CHAR(c)      #@c

// __VA_ARGS__       �ɱ������
#define    PRT(...)      printf(__VA_ARGS__)


//��ʾ�������
#define   fun()  \
	{ printf("���1\n"); printf("���2\n"); }

#define  fun2()   do {\
printf("���1\n"); printf("���2\n");\
}while (0)

int  main()
{
	//����#
	printf("#�����    %s\n", STR(123456));
	printf("#�����    %s\n", STR("123456"));
	printf("#�����    %s\n", STR(�й�));

	//����##
	STRUCT(AA);
	STRUCT(BB); 
	MyAAStruct  a;
	a.m_AA = 111; 
	MyBBStruct  b;
	b.m_BB = 222;

	//����#@
	printf("#@�����    %c\n",  CHAR(1));
	printf("#@�����    %c\n", CHAR(11));
	printf("#@�����    %c\n", CHAR(A));


	//����__VA_ARGS__
	PRT("%d\n" ,  1); //2������������
	PRT("%d    %s\n",  1  ,  "hello");//3������������


    //����Ԥ�����,һ��������־������ܷ���
	printf("__LINE__    %d\n",   __LINE__);//�к�
	printf("__FUNCTION__    %s\n", __FUNCTION__);//������
	printf("__FILE__     %s\n", __FILE__);//�ļ���
	printf("__DATE__    %s\n", __DATE__);//����
	printf("__TIME__    %s\n", __TIME__);//����

	//��ʾ������
	if (false) fun();

	if (false) fun() //ʹ�ò�ͳһ
	else  printf("���3��\n");

	//����do while
	if (false) fun2(); 
	if (false) fun2();
	else  printf("���3��\n");


	return 0;
}