#include<stdio.h>

int  main()
{
   //�ַ��������������һ����ַ
	printf("%p\n", "hello");

	//�����ַ���ָ��
	char *p = "hello";//���׵�ַ��ֵ���ɿ���һ��һά�ַ�����

	//����ָ������ַ�����,\0Ϊ���һ��Ԫ��
	for (int  i = 0; i < 6; i++)
	{
		//printf("%c", p[i]);
		//printf("%c",  *(p+i));
		printf("%c", *(p ++));
	}
	printf("---");//����ۿ�\0�Ĵ���
	printf("\n");

 
	//�ַ����������ܸ�ֵ���������������һ������
	char *p2 = "hello";
	//p2[1] = 'a';//����
	printf("%s", p2);


	return   0;
}