#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������
#include<string.h> //ϵͳͷ�ļ���������strcpy , strlen��ϵͳ����������


//����һ��ѧ���ṹ������
struct   Student
{
	int  num;//ѧ��
	char name[20];//����
	int   age;//���� 
};


void  main()//ϵͳ�������������������ں�������������ļ�д
{
	//����ṹ�����stu1����ʼ����
	struct  Student   stu1 = {10000,   "zhangshan",  18};

	//�ȶ���ṹ�����stu2��Ȼ���ٸ�ֵ
	struct  Student    stu2;
	stu2.num = 10001;//��. �����ʳ�Ա
	strcpy(stu2.name,  "lisi" );
	stu2.age = 20;


	printf("ѧ�ţ� %d\n",stu1.num);
	printf("������ %s\n", stu1.name);
	printf("���䣺 %d\n", stu1.age);
}

