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

	//����һ���ṹ���������ʼ��
	struct  Student   stu = {  10000, "zhangsan",  18  };

	//����һ���ṹ��ָ�����
	struct  Student  * pStu = &stu;//�ýṹ������ĵ�ַ��ֵ

	//���ʽṹ���Ա    ������ .    ָ���� ->
	printf("ѧ�ţ�%d , ������ %s, ���䣺  %d\n", stu.num, stu.name, stu.age);// .������
	printf("ѧ�ţ�%d , ������ %s, ���䣺  %d\n", pStu->num, pStu->name, pStu->age);//  ->������



}

