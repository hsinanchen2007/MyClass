#include<stdio.h> //ϵͳͷ�ļ���������printf,scanf��ϵͳ����������
 

//������һ�����յ�ö��,Ĭ�ϻ��0��ʼ����
enum  Festival
{
	GuoQing=4,
	ZhongQiu=33,
	DuanWu=8,
	ChunJie  
};

//����һ�����ڵ�����
enum week
{
	Sun=7,
	Mon=1,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat
};


void  main()//ϵͳ�������������������ں�������������ļ�д
{
	int   festival = ZhongQiu;
	if (festival == ZhongQiu)//�ɶ����ر�ǿ
	{
		printf("%d \n",ZhongQiu);
		printf("����ڵ��ˣ�\n");
	}

	 
	printf("������1~7֮���һ�����֣�\n");
	int day;
	scanf("%d", &day);     //����һ�� i  
	switch (day)
	{
	case Sun:	    printf("������\n"); break;
	case Mon:	printf("����һ\n"); break;
	case Tue:	    printf("���ڶ�\n"); break;
	case Wed:	printf("������\n"); break;
	case Thu:	    printf("������\n"); break;
	case Fri:	    printf("������\n"); break;
	case Sat:	    printf("������\n"); break;
	}


}

