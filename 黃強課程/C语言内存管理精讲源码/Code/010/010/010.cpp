#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char  * fun()
{
	char arr[10];
	 return  arr;
 }//arr��ջ�ڴ棬�뿪�˻����ţ�ջ���ͷŻ���


int main()
{
	//1.���ʵ�Ұָ��ָ�������Խ�����
	char  *p;//û�г�ʼ����Ұָ�룬��ָһ��
	//strcpy(p, "hello");//�Ƿ�Խ�����

	//2.�����±�Խ�����
	int   * p2 = (int *)calloc(10, sizeof(int));
	for (size_t i = 0; i <= 10; i++)
	{
		p2[i] = i;//���Ѳ����Խ����ʣ� �±�Խ��
	}

	//3.ʹ���Ѿ��ͷŵ��ڴ�
	char *p3 = (char *)malloc(10);
	free(p3);
	if (p3 != NULL)//����if��������
	{
		strcpy(p3, "hello");//����p3�Ѿ����ͷ�
	}


	//4.��ͼ����һ���ͷŵ�ջ�ռ�
	char *p4 = fun();  //p4ָ���ջ�ռ��Ѿ����ͷ�
	strcpy(p4, "hello");
	printf("%s\n",p4);


	//5.���׺��� �ַ��������\0
	char  *p5 = (char *)malloc(strlen("hello"));//���Ǽ�1
	strcpy(p5, "hello");//����p5�ĳ��Ȳ�����Խ��


	return 0;
}