#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 

char  * GetBuf()
{
	return  (char *)malloc(10);
}

void  GetBuf2(char *p)//p�Ѿ���һ�ݿ�������ԭ�������κι�ϵ
{
	p= (char *)malloc(10);
}

char  * GetBuf3()
{
	char  *p = "hello";//�����ڴ��������ɸ���
	return p;
}


int main()
{
 
	//1.��ʧ�˷�����ڴ���׵�ַ�������޷��ͷ�
	GetBuf();//���ǽ��շ���ֵ��


	//2.��ʧ������ڴ��ַ
	char  *p1= (char *)malloc(10);
	char  *p2 = (char *)malloc(10);
	p1 = p2;//��һ�������µ�һ�η���Ķ��ڴ涪ʧ���޷��ͷ�

	//3.��ͼϣ������ָ�������ȡ���ڴ棬�ⲻ֪�ǿ���
	char  *p3 = NULL;
	GetBuf2(p3); //Ӧ��ʹ��ָ���ָ�룬��������
	//strcpy(p3, "hello"); //���������p3��ȻΪNULL

	//4.ÿѭ��һ�Σ�й¶һ���ڴ�
	char  * p4 = NULL;
	for (int i = 0; i < 10; ++i)
	{
		p4= (char *)malloc(10);
	}
	strcpy(p4, "hello"); // �����p4ָֻ�����һ�η���ģ�ǰ���ȫ���ڴ�й©

	//5.�Ƿ����ʳ�����
	char *p5 = GetBuf3();
	strcpy(p5, "hello");  



	return 0;
}