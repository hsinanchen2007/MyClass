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

	//����ṹ�����鲢��ʼ��,�����ÿ��Ԫ�ض���һ���ṹ��
	struct   Student   stus1[3] =
	{
		{ 10000, "zhangshan", 18},
		{ 10001, "lisi", 19 },
		{ 10002, "zhaowu", 20 }
	};

	//�ȶ��壬�ٸ�ֵ
	struct   Student   stus2[3]; 
	//��һ��Ԫ�صĸ�ֵ
	stus2[0].num = 20001;
	strcpy(stus2[0].name, "sunliu");
	stus2[0].age = 31; 
	//�ڶ���Ԫ�صĸ�ֵ
	stus2[1].num = 20002;
	strcpy(stus2[1].name, "huangwu");
	stus2[1].age = 32; 
	//������Ԫ�صĸ�ֵ
	stus2[2].num = 20003;
	strcpy(stus2[2].name, "xiaoqi");
	stus2[2].age = 33;



	for (int i = 0; i < 3; ++i)
	{
		//ÿ������Ԫ�ض���һ���ṹ��
		struct  Student tmp = stus1[i]; 
		printf("ѧ�ţ�%d   ����: %s    ����:%d  \n", tmp.num, tmp.name, tmp.age);
	}


}

