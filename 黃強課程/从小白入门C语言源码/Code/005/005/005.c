#include "stdio.h"

void  main()
{

	//ǰ׺��һ��������Ľ��Ʋ�һ����������û�취��ʾ
	printf("%d\n", 10000);//Ĭ����ʮ����

	printf("%d\n", 010);//�˽��ƣ���0��ͷ

	printf("%d\n", 0x10);//ʮ�����ƣ���0x��ͷ



	//�ô���չʾ����ת��
	int a = 215;
	printf("ʮ����		 %d\n", a);
	printf("�˽���		 %o\n", a); 
	printf("ʮ������	 %x          %X          %p\n", a, a, a);


	char s[10];
	itoa(a, s, 2);//������תΪ������
	printf("������		 %s\n", s);

}