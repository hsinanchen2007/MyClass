#include<stdio.h>


void  main()
{
 //ѭ���ṹ- for
	int  sum = 0;
	for (int i = 1; i <= 100; ++i)//û��++i��������һֱΪ�棬��ô��ѭ��
	{
		sum += i;//sum  = sum +i;
	}
	printf("for  %d\n", sum );


	//ѭ���ṹ-while
	sum = 0;
	int j = 1;
	while (j <= 100)
	{
		sum += j;

		++j;//�������ǣ��ı�����״̬�����������ѭ��
	}
	printf("while  %d\n", sum);


	//ѭ���ṹ-do while
	sum = 0;
	int k = 1;
	do//һ����ִ��һ��
	{
		sum += k;
		++k;
	} while (0);
	//while (k <= 100);
	printf("do while  %d\n", sum);

}