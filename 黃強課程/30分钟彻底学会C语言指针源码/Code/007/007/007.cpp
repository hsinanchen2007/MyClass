#include<stdio.h>

int  main()
{

	//ָ��+ ����N  ����ʾ����ƫ��N*sizeof(����)
	int  a = 100;
	int *p1 = &a;
	printf("%p    %p\n", p1, p1 + 2);//006FFE14 �� 006FFE1C���2*  sizeof(int)�ֽ�

	char  b = 'A';
	char *p2 = &b;
	printf("%p    %p\n", p2, p2 + 2);//008FFDFF�� 008FFE01���2*  sizeof(char)�ֽ�

	//++ָ�룬 ��ʾƫ��sizeof(����)��  ָ�뱾���ֵ��ı�
	int *p3 = &a;
	printf("%p  ",  p3); 
	printf("%p  ", ++p3);
	printf("%p  \n", p3);//++��ָ�������ֵ�ı�

	  //ָ��- ����N  ����ʾ��ǰƫ��N*sizeof(����) 
	int *p4 = &a;
	printf("%p    %p\n", p4, p4 - 2);//006FFE0C  006FFE04 ���2*  sizeof(int)�ֽ�

	//--ָ�룬 ��ʾƫ��sizeof(����)��  ָ�뱾���ֵ��ı�
	int *p5 = &a;
	printf("%p  ", p5);
	printf("%p  ", --p5);
	printf("%p  \n", p5);//--��ָ�������ֵ�ı�


	//ָ��-ָ��
	int *p6 = &a;
	int *p7 = &a + 3;
	printf("%d \n", p7-p6);//���3
	printf("%d \n", (unsigned int )p7 - (unsigned int)p6);// 3*sizeof(����)



	return 0;
}