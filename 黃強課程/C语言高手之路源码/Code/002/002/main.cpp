#include<stdio.h>

//��һ��д��
/*
void   main()
{
	printf("�������main��\n");
}


//�ڶ���д��
int  main()
{
	printf("�������main��\n");
	return 0;
}
*/

//������main����

int   main(int  argc, char *argv[])//int   main(int  argc, char **argv)
{
	/*
	printf("argc����argv�����Ԫ�ظ�����%d\n"  ,argc);//argcһ����>=0��

	printf("argv[0]�������·����%s\n", argv[0]); 

	for (int i =1; i < argc; ++i)
	{
		printf("��%d��������%s\n", i, argv[i]);
	} 
	*/

	//ģ��echo����
	for (int i = 1; i < argc; ++i)
	{
		printf("%s      ",  argv[i]);
	}
	printf("\n");

}