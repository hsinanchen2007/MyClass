#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int  main()
{
	//��ʾջ�ռ��С��������Ĭ��1M
    #define   N     1024 * 1024* 4
	char a[N]; //ջ�ڴ� С��1M
	memset(a, 'A',N);
	printf("%c\n", a[N - 1]);


	//��ʾ�ѵĴ�С 
	int  MB = 0;
	while (malloc(1024 * 1024))
	{
		++MB;
	}
	printf("������ %f  G�Ķѿռ� \n",  MB *1.0/1024  );


	return 0;
}