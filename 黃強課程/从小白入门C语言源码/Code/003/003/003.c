#include <stdio.h>//����ͷ�ļ�


//���������������
void    main()
{
	//�ַ����� ����ĸ��
	printf("char:%d\n" ,sizeof(char));

	//���ͣ�������
	printf("short:%d\n", sizeof(short));//������
	printf("int:%d\n", sizeof(int));//����
	printf("long:%d\n", sizeof(long));//������

	//�����ͣ�С����
	printf("float:%d\n", sizeof(float));//������
	printf("double:%d\n", sizeof(double));//˫����
}