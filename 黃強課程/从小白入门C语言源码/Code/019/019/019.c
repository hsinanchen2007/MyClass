#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������
#include<stdlib.h> //ϵͳͷ�ļ���������malloc,free��ϵͳ����������

void  main()//ϵͳ�������������������ں�������������ļ�д
{
	//������3������
	char  a = 'A';
	int b = 10;
	float c = 1.234f;

	//char *,  int  *,   float  *
   //void  * ����ָ���κ����͵ı����ĵ�ַ
	void  *pA = &a;
	void  *pB = &b;
	void  *pC= &c;

	//���󣬲�����ʹ�ò�����������
	//printf("%c",  *pA);

	//��Ҫǿ��ת���󣬲���ʹ��
	 char  *pAA = (char *)pA;
	 int  *  pBB = (int *)pB;
	 float  *pCC = (float *)pC;
	 printf("%c\n", *pAA);
	 printf("%d\n", *pBB);
	 printf("%f\n", *pCC);


	 //void *���Գн��κ����͵ĵ�ַ�����Ծ��м�����
	 int  *p = (int *)malloc(4);//���Է����κ����͵Ŀռ�
	 int  *p2 = (char  *)malloc(4);
	 float  *p3= (float  *)malloc(4);
	 *p3 = 1.234f;
	 

	 printf("%p\n", p3);
	 free(p3);//�ͷ��ڴ��ˣ����ǲ�����ָ���ֵ��NULL����Ҫ�ֶ�=NULL���������Ұָ��
	 printf("%p\n", p3);
	 //�˿�����ȥ����p3���ڴ棬��ʵ���ǷǷ�����!
	 p3 = NULL;//��Ҫ�ֶ��ÿգ�����Ұָ��
	 if(p3!=NULL)
	 { 
	     printf("%f\n", *p3);//�˿��Ѿ�����ֵ��
	 }

	 //�������һ��ָ�����������ʼ��
	 int  *p4; // Ӧ��p4 = NULL;
	 printf("%p\n", NULL);
	//printf("%p\n",p4);//�ҵĵ�ֵַ����ָһ��

}

