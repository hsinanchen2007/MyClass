#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int  main()
{
	//演示栈空间大小，编译器默认1M
    #define   N     1024 * 1024* 4
	char a[N]; //栈内存 小于1M
	memset(a, 'A',N);
	printf("%c\n", a[N - 1]);


	//演示堆的大小 
	int  MB = 0;
	while (malloc(1024 * 1024))
	{
		++MB;
	}
	printf("分配了 %f  G的堆空间 \n",  MB *1.0/1024  );


	return 0;
}