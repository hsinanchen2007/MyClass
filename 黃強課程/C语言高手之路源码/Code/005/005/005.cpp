#include<stdio.h>
#include"005.h"
#include"005.h"//�ظ�����

//ȥ������ָ��
//#pragma  warning(disable:4700)



//#define  A   

int  main()
{  
 //��������1
#ifdef   A 
	printf("�����˷���A\n");
#endif


	//��������2
#ifdef   A 
	printf("�����˷���A\n"); 
#else 
	printf("�޷���A\n");
#endif
	  
	//��������3
#ifndef   A 
	printf("�޷���A\n");
#else 
	printf("�����˷���A\n");
#endif


	//��������4
#if     22 
	printf("����Ϊ��\n");
#else 
	printf("����Ϊ��\n");
#endif


	//��������4
#if    0 
	printf("��һ�����\n");
#elif   33
	printf("�ڶ������\n");
#else 
	printf("�������\n");
#endif


 //#errorָ��
#define   B    2
#if  B>3
#error   B   is  larger then  3!
#endif


printf("%d   ,  %s \n", __LINE__, __FILE__);
#line   666   "1.txt"
printf("%d   ,  %s \n", __LINE__, __FILE__);

 
int  a;
int  b = a;


return 0;
}